#include "EmoteFileWriter.h"

void EmoteFileWriter::createMapFile(std::string fileName, MapFileData dataToSave)
{
	std::string fileDirectory = "Emote_Game\\Maps\\";
	std::string fileFormat = "eMap";
	std::ofstream mapFile;
	mapFile.open(fileDirectory + fileName + "." + fileFormat, std::ios::binary | std::ios::trunc);

	if (mapFile.is_open())
	{
		int sizeCounter = sizeof(fileFormat.c_str());
		// store file format for safety check
		mapFile.write(fileFormat.c_str() , sizeof(fileFormat.c_str()));
		// store size of int to know if ints are saved with 8 bytes or 4
		char intSize = char(sizeof(int));
		mapFile.write((char*) &intSize, sizeof(intSize));
	}
	else
	{
		assert(mapFile.is_open()); // eventually, statement should become an error message to user...
	}
	mapFile.close();
}
