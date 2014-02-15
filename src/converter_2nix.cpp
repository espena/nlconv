#include "../inc/converter_2nix.h"
void converter::converter_2nix::
translate( const char* in_buffer, std::streamsize in_char_count ) {
	m_conversion.reset();
	for( std::streamsize i = 0; i < in_char_count; i++ ) {
		char current_char = in_buffer[ i ];
		switch( current_char ) {
		case params::delimiter::cr:
			m_conversion.pass( params::delimiter::cr );
			break;
		case params::delimiter::lf:
			if( !m_conversion.just_passed( params::delimiter::cr ) ) {
				m_conversion.pass_put( params::delimiter::lf );
			}
			break;
		default:
			if( m_conversion.just_passed( params::delimiter::cr ) ) {
				m_conversion.put( params::delimiter::lf );
			}
			m_conversion.pass_put( current_char );
		}
	}
}