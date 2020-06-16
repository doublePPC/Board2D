#include "EmoteFileReader.h"

void EmoteFileReader::readMapFile(std::string fileName)
{
	std::string fileDirectory = "Emote_Game\\Maps\\";
	std::string fileFormat = "eMap";
	std::ifstream mapFile;
	mapFile.open(fileDirectory + fileName + "." + fileFormat, std::ios::binary | std::ios::ate);

	if (mapFile.is_open())
	{
		// reading the file and storing the bytes in a char tab
		int fileSize = mapFile.tellg();
		char* fileData = new char[fileSize];
		std::string formatRead = "";
		mapFile.seekg(0, std::ios::beg);
		mapFile.read(fileData, fileSize);

		// converting the data
		assert(fileSize >= 9);
		std::string readFormat(fileData, 8);
		int sizeOfInt = fileData[8];
		
		bool dude = true;
	}
	else
	{
		std::string errorMessage = "Load failed. Make sure the map file type is eMap";
	}
	mapFile.close();
}
