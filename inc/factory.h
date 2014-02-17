#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <fcntl.h>
#include "interface/i_converter.h"
#include "command_line.h"
#include "converter_2dos.h"
#include "converter_2nix.h"
#include "converter_2mac.h"
#include "converter_2fix.h"
namespace converter {
	namespace factory {
		i_converter* get_converter( const command_line& cmd );
		void release( i_converter* converter );
		std::istream* get_input( const command_line& cmd );
		void release( std::istream* input );
	}
}
#endif