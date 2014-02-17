#include "../inc/main.h"

int main( int argc, char* argv[] ) {
	try {
		if( argc < 2 ) throw std::runtime_error( converter::strings::err_too_few_arguments );
		converter::command_line cmd( argc, argv );
		if( cmd.get_flag( "help" ) ) {
			std::cout << converter::strings::msg_usage << "\n";
			std::cout << converter::strings::msg_usage_syntax << "\n";
		}
		else {
			converter::run( cmd );
		}
	}
	catch( std::exception const & error ) {
		std::cout << error.what() << "\n";
		return -1;
	}
	return 0;
}

void converter::
run( const command_line& cmd ) {
	i_converter* conv = factory::get_converter( cmd );
	std::istream* input = factory::get_input( cmd );
	char buffer[ params::block_size ];
	std::streamsize char_count = sizeof buffer;
	while( char_count == sizeof buffer ) {
		input->read( buffer, sizeof buffer );
		char_count = input->gcount();
		conv->translate( buffer, char_count );
		std::cout.write( conv->buffer(), conv->char_count() );
	}
	factory::release( input );
	factory::release( conv );
}
