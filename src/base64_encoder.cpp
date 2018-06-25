#include "base64_encoder.hpp"

Camera::Base64Encoder::Base64Encoder(std::string & filePath):
	filePath(filePath)
{}

Camera::Base64Encoder::Base64Encoder(){}

std::vector<unsigned char> & Camera::Base64Encoder::getByteStream(){
	buffer.clear();
	std::ifstream file(filePath, std::ios::binary);
	std::istream_iterator<unsigned char> begin(file), end;
	buffer.assign(begin,end);
	return buffer;
}

void Camera::Base64Encoder::setFilePath(std::string & newFilePath){
	filePath = newFilePath;
}

std::string Camera::Base64Encoder::encode(){
	
	std::vector<unsigned char> & data = getByteStream();
	
	std::string result;
	int i=0, j=0;
	
	unsigned char array3[3];
	unsigned char array4[4];

	for(unsigned char & c : data){
		array3[i++] = c;
		if (i==3){
			array4[0] = (array3[0] & 0xfc) >> 2;
			array4[1] = ( (array3[0] & 0x03) << 4 ) + ( (array3[1] & 0xf0) >> 4 ); 
			array4[2] = ( (array3[0] & 0x0f) << 2 ) + ( (array3[2] & 0xc0) >> 6 );
			array4[3] = array3[2] & 0x3f;
			
			for(i = 0; (i<4); i++){
				result += base64Chars[ array4[i] ];
			} i=0; 
		}

	}

	if(i){
		for(j = i; j < 3; j++){
			array3[j] = '\0';
		}
		array4[0] = ( array3[0] & 0xfc ) >> 2;
		array4[1] = ( ((array3[0] & 0x03) << 4) + ( (array3[1] & 0xf0) >> 4 ) );
		array4[2] = ( ((array3[1] & 0x0f) << 2) + ( (array3[2] & 0xc0) >> 6 ) );
		
		for( j=0; (j < i + 1); j++ ){
			result += base64Chars[ array4[j] ];
		}
		while((i++ < 3)){ result += '='; }
	}
	
	return result;
	
}

std::string Camera::Base64Encoder::encode(std::vector<unsigned char> & data){
		
	std::string result;
	int i=0, j=0;
	
	unsigned char array3[3];
	unsigned char array4[4];

	for(unsigned char & c : data){
		array3[i++] = c;
		if (i==3){
			array4[0] = (array3[0] & 0xfc) >> 2;
			array4[1] = ( (array3[0] & 0x03) << 4 ) + ( (array3[1] & 0xf0) >> 4 ); 
			array4[2] = ( (array3[0] & 0x0f) << 2 ) + ( (array3[2] & 0xc0) >> 6 );
			array4[3] = array3[2] & 0x3f;
			
			for(i = 0; (i<4); i++){
				result += base64Chars[ array4[i] ];
			} i=0; 
		}

	}

	if(i){
		for(j = i; j < 3; j++){
			array3[j] = '\0';
		}
		array4[0] = ( array3[0] & 0xfc ) >> 2;
		array4[1] = ( ((array3[0] & 0x03) << 4) + ( (array3[1] & 0xf0) >> 4 ) );
		array4[2] = ( ((array3[1] & 0x0f) << 2) + ( (array3[2] & 0xc0) >> 6 ) );
		
		for( j=0; (j < i + 1); j++ ){
			result += base64Chars[ array4[j] ];
		}
		while((i++ < 3)){ result += '='; }
	}
	
	return result;
}
