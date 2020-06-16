#pragma once
#include "EmoteGenericData.h"


class EmoteFileWriter
{
public:
	static void createMapFile(std::string fileName, MapFileData dataToSave);
};