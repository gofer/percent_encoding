#include <cstdio>
#include <percent_encoding.hpp>

namespace PercentEncoding {
	char _is_hex_char(char ch) {
		if('0' <= ch && ch <= '9') return (ch - '0');      else
		if('A' <= ch && ch <= 'F') return (ch - 'A') + 10; else
		if('a' <= ch && ch <= 'f') return (ch - 'a') + 10; else
		return static_cast<char>(-1);
	}
	
	char _hex_str2int(char* str) {
		return _is_hex_char(str[0]) << 4 | _is_hex_char(str[1]);
	}
	
	int decode(std::string* src, std::string* dst) {
		char* buf = new char[3];
		buf[2] = '\0';
		for(uint64_t i=0; i<src->length(); ++i) {
			if(src->at(i) == '%') {
				buf[0] = src->at(++i);
				buf[1] = src->at(++i);
				dst->append(1, _hex_str2int(buf));
			} else {
				dst->append(1, src->at(i));
			}
		}
		delete buf;
		return 0;
	}
	
	std::string decode(const std::string& src) {
		std::string dst;
		char* buf = new char[3];
		buf[2] = '\0';
		for(uint64_t i=0; i<src.length(); ++i) {
			if(src[i] == '%') {
				buf[0] = src.at(++i);
				buf[1] = src.at(++i);
				dst.append(1, _hex_str2int(buf));
			} else {
				dst.append(1, src.at(i));
			}
		}
		delete buf;
		return dst;
	}
};
