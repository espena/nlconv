#include "../inc/conversion.h"

void converter::conversion::
reset() {
	m_char_count = 0;
}

void converter::conversion::
pass_put( char c ) {
	pass( c );
	put( c );
}

void converter::conversion::
pass( char c ) {
	m_last_char = c;
}

void converter::conversion::
put( char c ) {
	if( m_char_count < sizeof m_buffer ) {
		m_buffer[ m_char_count++ ] = c;
	}
	else {
		throw std::runtime_error( strings::err_conversion_buffer_overflow );
	}
}

bool converter::conversion::
just_passed( char c ) {
	return m_last_char == c;
}