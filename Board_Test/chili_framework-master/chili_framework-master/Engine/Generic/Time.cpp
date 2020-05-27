#include "Time.h"

std::chrono::steady_clock::time_point FrameTime::getPoint()
{
	std::chrono::steady_clock::time_point tmPt = std::chrono::steady_clock::now();
	return tmPt;
}

float FrameTime::getDuration(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end)
{
	std::chrono::duration<float> runTime = end - start;
	return runTime.count();
}

FrameTime::FrameTime()
{
	last = FrameTime::getPoint();
}

float FrameTime::getFrameDeltaTime()
{
	auto old = last;
	last = FrameTime::getPoint();
	return FrameTime::getDuration(old, last);
}
