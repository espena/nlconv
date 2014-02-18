#ifndef __CONVERTER_PARAMS_H__
#define __CONVERTER_PARAMS_H__
#include <ios>
namespace converter {
	namespace params {
		namespace delimiter {
			const char cr = '\r';
			const char lf = '\n';
			const char* const str_cr = "\r";
			const char* const str_lf = "\n";
			const char* const str_crlf = "\r\n";
		}
		const std::streamsize block_size = 2048;
		const unsigned int max_delimiter_size = 2;
		const char* const default_delimiter = delimiter::str_crlf;
		const unsigned char utf8_bom[] = { 0xef, 0xbb, 0xbf };
	};
}
#endif