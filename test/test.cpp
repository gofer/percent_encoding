#include <iostream>
#include <string>
#include <percent_encoding.hpp>
#include <gtest/gtest.h>

TEST(test1, WithRefrence) {
	std::string* src   = new std::string("ウィキペディアchang kawaii→");
	std::string* dst_e = new std::string();
	std::string* dst_d = new std::string();
	
	PercentEncoding::encode(src, dst_e);
	
	PercentEncoding::decode(dst_e, dst_d);
	
	ASSERT_EQ(*src, *dst_d);

	delete dst_d;
	delete dst_e;
	delete src;
}

TEST(test1, WithPointer) {
	const std::string src("ウィキペディアchang kawaii→");
	
	std::string dst_e = PercentEncoding::encode(src);

	std::string dst_d = PercentEncoding::decode(dst_e);

  ASSERT_EQ(src, dst_d);
}
