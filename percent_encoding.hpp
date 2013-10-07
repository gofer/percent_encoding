#ifndef __PERCENT_ENCODING_HPP__
#define __PERCENT_ENCODING_HPP__

#include <string>

namespace PercentEncoding {
	int encode(std::string*, std::string*);
	std::string encode(const std::string&);
	int decode(std::string*, std::string*);
	std::string decode(const std::string&);
}

#endif
