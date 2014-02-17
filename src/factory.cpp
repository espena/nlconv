#include "../inc/factory.h"

converter::i_converter* converter::factory::
get_converter( const command_line& cmd ) {
	i_converter* converter = 0;

	if( cmd.get_flag( "-2dos" ) ) {
		converter = new converter_2dos();
	}
	else if( cmd.get_flag( "-2nix" ) ) {
		converter = new converter_2nix();
	}
	else if( cmd.get_flag( "-2mac" ) ) {
		converter = new converter_2mac();
	}
	else if( cmd.get_flag( "-2fix" ) ) {
		converter = new converter_2fix();
	}
	if( 0 == converter ) {
		throw std::runtime_error( "No appropriate converter found." );
	}
	else {
		converter->init( cmd );
	}
	return converter;
}

std::istream* converter::factory::
get_input( const command_line& cmd ) {
#ifdef _WIN32
	_setmode( _fileno( stdout ), _O_BINARY );
	_setmode( _fileno( stdin ), _O_BINARY );
#endif
	std::string i = cmd.get_str( "-i" );
	return i.empty() ? &std::cin : new std::ifstream( i, std::ifstream::binary );
}

void converter::factory::
release( i_converter* converter ) {
	delete converter;
	converter = 0;
}

void converter::factory::
release( std::istream* input ) {
	if( input != &std::cin ) {
		delete input;
	}
	input = 0;
}