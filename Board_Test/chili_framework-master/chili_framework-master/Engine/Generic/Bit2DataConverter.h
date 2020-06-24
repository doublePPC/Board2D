#pragma once
#include <cassert>

class BitDataConverter 
{
public:
	static int charTo4ByteInt(unsigned char* dataToConvert, int start);
	static unsigned int charTo4ByteUint(unsigned char* dataToConvert, int start);
};