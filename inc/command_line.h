#ifndef __COMMAND_LINE_H__
#define __COMMAND_LINE_H__
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "converter_strings.h"
namespace converter {
	class command_line {
    std::map<std::string, int> m_ints;
    std::map<std::string, std::string> m_strs;
    std::map<std::string, bool> m_flags;
  public:
    ~command_line() { };
    command_line( int argc, const char* const argv[] );
    int get_int( std::string key ) const;
    bool get_flag( std::string key ) const;
    std::string get_str( std::string key ) const;
	};
}
#endif