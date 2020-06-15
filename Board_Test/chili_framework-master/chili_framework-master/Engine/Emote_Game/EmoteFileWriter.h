#pragma once
#include "EmoteGenericData.h"
#include <ostream>

class EmoteFileWriter
{
	static void createMapFile(std::string fileName, MapFileData dataToSave);
};