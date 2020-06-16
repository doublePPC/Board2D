#include "EmoteFileWriter.h"

void EmoteFileWriter::createMapFile(std::string fileName, MapFileData dataToSave)
{
	std::string fileFormat = "eMap";
	std::ofstream mapFile;
	mapFile.open(fileName + "." + fileFormat, std::ios::binary | std::ios::trunc);

	if (mapFile.is_open())
	{
		// store file format for safety check
		mapFile.write((char*) &fileFormat, sizeof(fileFormat));

	}
	else
	{
		assert(mapFile.is_open()); // eventually, statement should become an error message to user...
	}
	mapFile.close();
}
