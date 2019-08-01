#include <iostream>
#include <string>
#include <percent_encoding.hpp>

void type1() {
	std::string* src   = new std::string("ウィキペディアchang kawaii→");
	std::string* dst_e = new std::string();
	std::string* dst_d = new std::string();
	
	std::cout << *src   << std::endl;
	
	PercentEncoding::encode(src, dst_e);
	
	std::cout << *dst_e << std::endl;
	
	PercentEncoding::decode(dst_e, dst_d);
	
	std::cout << *dst_d << std::endl;
	
	delete dst_d;
	delete dst_e;
	delete src;
}

void type2() {
	const std::string src("ウィキペディアchang kawaii→");
	std::cout << src << std::endl;
	
	std::string dst = PercentEncoding::encode(src);
	
	std::cout << dst << std::endl;
	
	std::cout <<  PercentEncoding::decode(dst)<< std::endl;
}

int main(void) {
	type1();

	type2();
	
	return 0;
}
