#ifndef __CONVERSION_H__
#define __CONVERSION_H__
#include <ios>
#include <stdexcept>
#include "converter_params.h"
#include "converter_strings.h"
namespace converter {
	class conversion {
		std::streamsize m_char_count;
		char m_buffer[ params::block_size * ( params::max_delimiter_size + 1 ) ];
		char m_last_char;
	public:
		~conversion() { };
		char* buffer() { return m_buffer; };
		std::streamsize char_count() { return m_char_count; }
		void reset();
		void pass( char c );
		void put( char c );
		void pass_put( char c );
		bool just_passed( char c );
	};
}
#endif