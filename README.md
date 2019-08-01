# Percent Encoding(URL Encoding) Encode/Decode Functions  for C++

## What's this
This is percent encoding encode/decode functions for C++.

## Attention
This code uses C++11 features.

## How to use

### With pointer
Encode function is in namespace PercentEncoding. This function always return 0.

    int PercentEncoding::encode(const std::string* src, std::string* dst);

Decode function is in namespace PercentEncoding. This function always return 0.

    int PercentEncoding::decode(const std::string* src, std::string* dst);
	
### With reference
Encode function is in namespace PercentEncoding.

	std::string PercentEncoding::encode(const std::string& src);

Decode function is in namespace PercentEncoding.

    std::string PercentEncoding::decode(const std::string& src);

### Examples
In detail, please shows percent_encoding_test.cpp.
That code is compiled on following commands.

    g++ percent_encoding_encode.cpp percent_encoding_decode.cpp percent_encoding_test.cpp -I. -lstdc++ -std=c++11 -o test.out

## Licence
This codes are licensed by New BSD License.
