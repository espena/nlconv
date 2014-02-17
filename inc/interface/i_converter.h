#ifndef __I_CONVERTER_H__
#define __I_CONVERTER_H__
#include <ios>
#include "../command_line.h"
namespace converter {
	class i_converter {
	public:
		virtual ~i_converter() { };
		virtual void init( const converter::command_line& cmd ) = 0;
		virtual void translate( const char* buffer, std::streamsize char_count ) = 0;
		virtual char* buffer() = 0;
		virtual std::streamsize char_count() = 0;
	};
}
#endif