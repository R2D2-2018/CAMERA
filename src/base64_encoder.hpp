#ifndef BASE64_ENCODER_HPP
#define BASE64_ENCODER_HPP

#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

namespace Camera {
static const std::string base64Chars = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

static inline bool isBase64(unsigned char c){
	return ( std::isalnum(c) || (c == '+') || (c == '/') );
}


class Base64Encoder{
private: 
	std::string filePath;
	std::vector<unsigned char> buffer;
	
	std::vector<unsigned char> & getByteStream();
public:
	Base64Encoder(std::string & filePath);
	Base64Encoder();
	
	void setFilePath(std::string & newFilePath);
	std::string encode();
	std::string encode(std::vector<unsigned char> & data);
	
	
	
};
}

#endif //BASE64_ENCODER_HPP