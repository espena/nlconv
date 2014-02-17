#include "../inc/command_line.h"

converter::command_line::
command_line( int argc, const char* const argv[] ) {
	for( int i = 0; i < argc; i++ ) {
		std::string key = argv[ i ];
		if( key == "-2dos" || 
				key == "-2win" ||
				key == "-2nux" ||
				key == "-2fix" ||
				key == "-cr"   ||
				key == "-lf"   ||
				key == "-crlf" ||
				key == "-utf8" )
		{
			m_flags[ key ] = true;
		}
		else if( i < ( argc - 1 ) ) {
			if( key == "-i" ) {
				std::string val = argv[ i + 1 ];
				m_strs[ key ] = val;
			}
			else if( key == "-l" ) {
				try {
					int val = 0;
					std::stringstream ss( argv[ i + 1 ] );
					ss >> val;
					m_ints[ key ] = val;
				}
				catch( ... ) {
					std::cout << "Invalid record length (parameter -l).";
					throw;
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
	return m_strs.find( key ) == m_strs.end() ? 0 : m_strs.find( key )->second;
}
