#ifndef __MAIN_H__
#define __MAIN_H__
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "command_line.h"
#include "converter_params.h"
#include "converter_strings.h"
#include "conversion.h"
#include "factory.h"
namespace converter {
	void run( const command_line& cmd );
}
#endif