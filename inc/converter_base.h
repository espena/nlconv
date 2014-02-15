#ifndef __CONVERTER_BASE_H__
#define __CONVERTER_BASE_H__
#include "interface/i_converter.h"
namespace converter {
	class converter_base : public i_converter {
		i_converter* m_converter_2xxx;
		int m_argc;
		char* const * m_argv;
	public:
		virtual ~converter_base() { delete m_converter_2xxx; };
		converter_base( i_converter* converter_2xxx ) : m_converter_2xxx( converter_2xxx ) { };
		virtual void init( int argc, char* const argv[] );
		virtual void translate( const char* buffer, std::streamsize char_count );
		virtual char* buffer() { return m_converter_2xxx->buffer(); };
		virtual std::streamsize char_count() { return m_converter_2xxx->char_count(); }
	};
}
#endif