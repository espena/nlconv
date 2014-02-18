#include "../inc/command_line.h"

converter::command_line::
command_line( int argc, const char* const argv[] ) {
	for( int i = 0; i < argc; i++ ) {
		std::string key = argv[ i ];
		if(	"--help"	== key ||
			"--2dos"	== key ||
			"--2mac"	== key ||
			"--2nux"	== key ||
			"--2fix"	== key ||
			"--cr"		== key ||
			"--lf"		== key ||
			"--crlf"	== key ||
			"--utf8"	== key )
		{
			m_flags[ key.substr( 2, std::string::npos ) ] = true;
		}
		else if( ( "--input" == key || "-i" == key ) && i < ( argc - 1 ) ) {
			std::string val = argv[ i + 1 ];
			m_strs[ "input" ] = val;
		}
		else if( ( "--length" == key || "-l" == key ) && i < ( argc - 1 ) ) {
			try {
				int val = 0;
				std::stringstream ss( argv[ i + 1 ] );
				ss >> val;
				m_ints[ "length" ] = val;
			}
			catch( ... ) {
				std::cout << strings::err_invalid_record_length_parameter;
				throw;
			}
		}
		else if( key.length() > 1 && key.at( 0 ) == '-' && key.at( 1 ) != '-' ) {
			// Short options
			size_t n = key.length();
			for( size_t j = 1; j < n; j++ ) {
				switch( key.at( j ) ) {
					case 'h':	// --help
						m_flags[ "help" ] = true;
						break;
					case 'd':	// --2dos
						m_flags[ "2dos" ] = true;
						break;
					case 'n':	// --2nux
						m_flags[ "2nux" ] = true;
						break;
					case 'm':	// --2mac
						m_flags[ "2mac" ] = true;
						break;
					case 'f':	// --2fix
						m_flags[ "2fix" ] = true;
						break;
					case 'u':	// --utf8
						m_flags[ "utf8" ] = true;
						break;
					case 'C':	// --cr
						m_flags[ "cr" ] = true;
						break;
					case 'L':	// --lf
						m_flags[ "lf" ] = true;
						break;
					case 'R':	// --crlf
						m_flags[ "crlf" ] = true;
						break;
					default:
						throw std::runtime_error( strings::err_unknown_short_parameter );
				}
			}
		}
	}
}

int converter::command_line::
get_int( std::string key ) const {
	return m_ints.find( key ) == m_ints.end() ? 0 : m_ints.find( key )->second;
}

bool converter::command_line::
get_flag( std::string key ) const {
	return m_flags.find( key ) == m_flags.end() ? false : m_flags.find( key )->second;
}

std::string converter::command_line::
get_str( std::string key ) const {
	return m_strs.find( key ) == m_strs.end() ? "" : m_strs.find( key )->second;
}
