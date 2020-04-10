#pragma once
#include <chrono>

class FrameTime
{
public:
	// the role of the following functions is just to remove the writing in the code where 
	// time points and duration will be needed
	static std::chrono::steady_clock::time_point getPoint();
	static float getDuration(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end);

	// non-static methods
	FrameTime();

	float getFrameDeltaTime();

private:
	std::chrono::steady_clock::time_point last;
};