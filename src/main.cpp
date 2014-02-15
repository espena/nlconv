#include "../inc/main.h"
int main( int argc, char* argv[] ) {
	try {
		if( argc < 2 ) throw std::runtime_error( "Expected at least 1 argument." );
		converter::i_converter* converter = converter::factory::get_converter( argc, argv );
		std::istream* input = converter::factory::get_input( argc, argv );
		char buffer[ converter::params::block_size ];
		std::streamsize char_count = sizeof buffer;
		while( char_count == sizeof buffer ) {
			input->read( buffer, sizeof buffer );
			char_count = input->gcount();
			converter->translate( buffer, char_count );
			std::cout.write( converter->buffer(), converter->char_count() );
		}
		converter::factory::release( input );
		converter::factory::release( converter );
	}
	catch( std::exception const & error ) {
		std::cout << error.what();
		return -1;
	}
	return 0;
}