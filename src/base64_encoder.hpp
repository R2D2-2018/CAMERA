#ifndef BASE64_ENCODER_HPP
#define BASE64_ENCODER_HPP

#include <string>
//#include <cstring>
#include <fstream>
//#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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
	
	
	
};


#endif //BASE64_ENCODER_HPP


