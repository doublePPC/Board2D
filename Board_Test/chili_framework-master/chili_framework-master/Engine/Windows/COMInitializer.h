#pragma once

#include "..\\Windows\\ChiliWin.h"

class COMInitializer
{
public:
	COMInitializer();
	~COMInitializer();
private:
	HRESULT hr;
};