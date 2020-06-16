#pragma once
#include "EmoteGenericData.h"
#include <fstream>

class EmoteFileWriter
{
public:
	static void createMapFile(std::string fileName, MapFileData dataToSave);
};