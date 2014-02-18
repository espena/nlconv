#ifndef __CONVERTER_STRINGS_H__
#define __CONVERTER_STRINGS_H__
namespace converter {
	namespace strings {
		const char* const err_conversion_buffer_overflow			= "Conversion buffer overflow: Subscript out of range.";
		const char* const err_invalid_record_length_parameter = "Invalid record length (parameter -l).";
		const char* const err_no_converter_found							= "No appropriate converter found.";
		const char* const err_too_few_arguments 							= "Too few arguments. Expected at least 1.";
		const char* const err_unknown_short_parameter					= "Unknown short parameter.";
		const char* const msg_usage														= "Usage:";
		const char* const msg_usage_syntax 										= "nlconv { [--2dos] | [--2mac] | [--2nux] } [--fixlength <length>] [--utf8] [--input <sourcefile>]";
	};
}
#endif