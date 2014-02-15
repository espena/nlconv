#include "../inc/converter_2fix.h"

void converter::converter_2fix::
init( int argc, char* const argv[] ) {
	m_conversion_started = false;
	m_is_utf8 = false;
	m_char_pos = 0;
	m_record_delimiter = params::default_delimiter;
	for( int i = 1; i < argc - 1; i++ ) {
		std::string arg = argv[ i ];
		if( "-l" == arg ) {
			try {
				std::stringstream ss( argv[ i + 1 ] );
				ss >> m_record_length;
				if( m_record_length < 1 ) {
					throw std::runtime_error( "Parameter -l (length) must be at least 1." );
				}
			}
			catch( ... ) {
				std::cout << "Invalid record length.";
				throw;
			}
		}
		else if( "-cr" == arg ) {
			m_record_delimiter = params::delimiter::str_cr;
		}
		else if( "-lf" == arg ) {
			m_record_delimiter = params::delimiter::str_lf;
		}
		else if( "-utf8" == arg ) {
			m_is_utf8 = true;
		}
	}
	m_record_delimiter_length = m_record_delimiter.length();
}

void converter::converter_2fix::
translate( const char* in_buffer, std::streamsize in_char_count ) {
	m_conversion.reset();
	for( std::streamsize i = 0; i < in_char_count; i++ ) {
		if( !m_conversion_started )
		{
			m_conversion_started = true;
			const size_t bom_len = sizeof params::utf8_bom;
			if( in_char_count > bom_len &&
				std::memcmp( in_buffer, params::utf8_bom, bom_len ) == 0 ) {
				// UTF-8 byte order marker
				m_is_utf8 = true;
				for( ; i < bom_len; i++ ) {
					m_conversion.pass_put( in_buffer[ i ] );
				}
				i--;
				continue;
			}
		}
		
		if( ++m_char_pos == m_record_length ) {
			// Insert delimiter
			for( std::string::size_type j = 0; j < m_record_delimiter_length; j++ ) {
				m_conversion.put( m_record_delimiter.at( j ) );
			}
			m_char_pos = 1;
		}
		
		if( m_is_utf8 && in_buffer[ i ] & 0x80u ) {
			// UTF-8 character
			unsigned char utf8_start = in_buffer[ i ] & 0xf0u;
			unsigned int b = 0;
			while( ( utf8_start << b++ ) & 0x80u ) {
				m_conversion.pass_put( in_buffer[ i++ ] );
			}
			i--;
			continue;
		}
		
		m_conversion.pass_put( in_buffer[ i ] );
	}
}