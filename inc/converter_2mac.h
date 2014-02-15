#ifndef __CONVERTER_2MAC_H__
#define __CONVERTER_2MAC_H__
#include "interface/i_converter.h"
#include "conversion.h"
namespace converter {
	class converter_2mac : public i_converter {
		conversion m_conversion;
	public:
		virtual ~converter_2mac() { };
		virtual void init( int argc, char* const argv[] ) { };
		virtual void translate( const char* buffer, std::streamsize char_count );
		virtual char* buffer() { return m_conversion.buffer(); };
		virtual std::streamsize char_count() { return m_conversion.char_count(); }
	};
}
#endif