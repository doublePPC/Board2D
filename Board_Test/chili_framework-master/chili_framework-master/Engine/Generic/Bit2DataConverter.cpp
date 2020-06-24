#include "Bit2DataConverter.h"

int BitDataConverter::charTo4ByteInt(unsigned char* dataToConvert, int start)
{
	unsigned char intData[4] = { dataToConvert[start], dataToConvert[start + 1], dataToConvert[start + 2], dataToConvert[start + 3] };
	int value = *((int*)intData);
	return value;
}

unsigned int BitDataConverter::charTo4ByteUint(unsigned char* dataToConvert, int start)
{
	unsigned char intData[4] = { dataToConvert[start], dataToConvert[start + 1], dataToConvert[start + 2], dataToConvert[start + 3] };
	unsigned int value = *((unsigned int*)intData);
	return value;
}
