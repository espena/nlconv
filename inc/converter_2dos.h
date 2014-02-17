#ifndef __CONVERTER_2DOS_H__
#define __CONVERTER_2DOS_H__
#include "interface/i_converter.h"
#include "conversion.h"
namespace converter {
	class converter_2dos : public i_converter {
		conversion m_conversion;
	public:
		virtual ~converter_2dos() { };
		virtual void init( const converter::command_line& cmd ) { };
		virtual void translate( const char* buffer, std::streamsize char_count );
		virtual char* buffer() { return m_conversion.buffer(); };
		virtual std::streamsize char_count() { return m_conversion.char_count(); }
	};
}
#endif