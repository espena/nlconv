#include "../inc/converter_base.h"
void converter::converter_base::
init( int argc, char* const argv[] ) {
	m_argc = argc;
	m_argv = argv;
	m_converter_2xxx->init( argc, argv );
}

void converter::converter_base::
translate( const char* buffer, std::streamsize char_count ) { 
	m_converter_2xxx->translate( buffer, char_count );
}