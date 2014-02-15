#include "../inc/factory.h"

converter::i_converter* converter::factory::
get_converter( int argc, char* const argv[] ) {
	i_converter* converter = 0;
	for( int i = 1; i < argc; i++ ) {
		std::string arg = argv[ i ];
		if( "-2dos" == arg ) {
			converter = new converter_base( new converter_2dos() );
			break;
		}
		else if( "-2nix" == arg ) {
			converter = new converter_base( new converter_2nix() );
			break;
		}
		else if( "-2mac" == arg ) {
			converter = new converter_base( new converter_2mac() );
			break;
		}
		else if( "-2fix" == arg ) {
			converter = new converter_base( new converter_2fix() );
			break;
		}
	}
	if( 0 == converter ) {
		throw std::runtime_error( "No appropriate converter found." );
	}
	else {
		converter->init( argc, argv );
	}
	return converter;
}

std::istream* converter::factory::
get_input( int argc, char* const argv[] ) {
#ifdef _WIN32
	_setmode( _fileno( stdout ), _O_BINARY );
	_setmode( _fileno( stdin ), _O_BINARY );
#endif
	for( int i = 1; i < argc - 1; i++ ) {
		std::string arg = argv[ i ];
		if( "-i" == arg ) {
			return new std::ifstream( argv[ i + 1 ], std::ifstream::binary );
		}
	}
	return &std::cin;
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