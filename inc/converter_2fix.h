#ifndef __CONVERTER_2FIX_H__
#define __CONVERTER_2FIX_H__
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "converter_params.h"
#include "interface/i_converter.h"
#include "conversion.h"
namespace converter {
	class converter_2fix : public i_converter {
		bool m_conversion_started;
		bool m_is_utf8;
		std::streamsize m_char_pos;
		int m_record_length;
		std::string m_record_delimiter;
		std::string::size_type  m_record_delimiter_length;
		conversion m_conversion;
	public:
		virtual ~converter_2fix() { };
		virtual void init( const converter::command_line& cmd );
		virtual void translate( const char* buffer, std::streamsize char_count );
		virtual char* buffer() { return m_conversion.buffer(); };
		virtual std::streamsize char_count() { return m_conversion.char_count(); }
	};
}
#endif