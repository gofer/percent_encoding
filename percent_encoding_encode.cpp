#include <cstdio>
#include <percent_encoding.hpp>

namespace PercentEncoding {
	bool _is_not_reserved(char ch) {
		return !(
			('A' <= ch && ch <= 'Z') ||
			('a' <= ch && ch <= 'z') ||
			('0' <= ch && ch <= '9') ||
			(ch == '-') || 
			(ch == '.') || 
			(ch == '_') || 
			(ch == '~') 
		);
	}
	
	int encode(std::string* src, std::string* dst) {
		char* buf = new char[4];
		for(uint64_t i=0; i<src->length(); ++i) {
			if( _is_not_reserved( src->at(i) ) ) {
				::sprintf(buf, "%%%02X", static_cast<unsigned char>(src->at(i)));
				dst->append(buf);
			} else {
				dst->append(1, src->at(i));
			}
		}
		delete buf;
		return 0;
	}
	
	std::string encode(const std::string& src) {
		std::string dst;
		char* buf = new char[4];
		for(uint64_t i=0; i<src.length(); ++i) {
			if( _is_not_reserved( src.at(i) ) ) {
				::sprintf(buf, "%%%02X", static_cast<unsigned char>(src.at(i)));
				dst.append(buf);
			} else {
				dst.append(1, src.at(i));
			}
		}
		delete buf;
		return dst;
	}
};
