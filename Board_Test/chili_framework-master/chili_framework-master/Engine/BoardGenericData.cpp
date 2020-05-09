#include "BoardGenericData.h"

visibilityStatus isRectVisible(const Vec2& topLeftPos, const Vec2& botRightPos)
{
	if (int(botRightPos.x) >= 0 &&
		int(topLeftPos.x) < Graphics::ScreenWidth &&
		int(botRightPos.y) >= 0 &&
		int(topLeftPos.y) < Graphics::ScreenHeight)
	{
		if (int(topLeftPos.x) >= 0 &&
			int(botRightPos.x) < Graphics::ScreenWidth &&
			int(topLeftPos.y) >= 0 &&
			int(botRightPos.y) < Graphics::ScreenHeight)
		{
			return visibilityStatus::total;
		}
		else
		{
			if (int(botRightPos.x) < Graphics::ScreenWidth &&
				int(botRightPos.y) < Graphics::ScreenHeight &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTL;
			}
			if (int(botRightPos.x) < Graphics::ScreenWidth &&
				int(botRightPos.y) >= Graphics::ScreenHeight &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) < Graphics::ScreenHeight)
			{
				return visibilityStatus::partBL;
			}
			if (int(botRightPos.x) >= Graphics::ScreenWidth &&
				int(botRightPos.y) >= Graphics::ScreenHeight &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partBR;
			}
			if (int(botRightPos.x) >= Graphics::ScreenWidth &&
				int(botRightPos.y) < Graphics::ScreenHeight &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTR;
			}
			if (int(botRightPos.x) < Graphics::ScreenWidth &&
				int(botRightPos.y) < Graphics::ScreenHeight &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partLeft;
			}
			if (int(botRightPos.x) < Graphics::ScreenWidth &&
				int(botRightPos.y) < Graphics::ScreenHeight &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTop;
			}
			if (int(botRightPos.x) < Graphics::ScreenWidth &&
				int(botRightPos.y) >= Graphics::ScreenHeight &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partBottom;
			}
			if (int(botRightPos.x) >= Graphics::ScreenWidth &&
				int(botRightPos.y) < Graphics::ScreenHeight &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partRight;
			}
			return visibilityStatus::off;
		}
	}
	else
	{
		return visibilityStatus::off;
	}
};

bool isVecVisible(const Vec2& vec)
{
	if (vec.x >= 0 &&
		vec.x < Graphics::ScreenWidth &&
		vec.y >= 0 &&
		vec.y < Graphics::ScreenHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
};

Vec2 visibleTopLeft(const Vec2& convertedTL, visibilityStatus status)
{
	float x, y;
	if (status == visibilityStatus::partTL || status == visibilityStatus::partBL || status == visibilityStatus::partLeft)
	{
		x = 0.0f;
	}
	else
	{
		x = convertedTL.x;
	}
	if (status == visibilityStatus::partTL || status == visibilityStatus::partTR || status == visibilityStatus::partTop)
	{
		y = 0.0f;
	}
	else
	{
		y = convertedTL.y;
	}
	return Vec2(x, y);
};

Vec2 visibleBottomRight(const Vec2& convertedBR, visibilityStatus status)
{
	float x, y;
	if (status == visibilityStatus::partTR || status == visibilityStatus::partBR || status == visibilityStatus::partRight)
	{
		x = float(Graphics::ScreenWidth - 1);
	}
	else
	{
		x = convertedBR.x;
	}
	if (status == visibilityStatus::partBL || status == visibilityStatus::partBR || status == visibilityStatus::partBottom)
	{
		y = float(Graphics::ScreenHeight - 1);
	}
	else
	{
		y = convertedBR.y;
	}
	return Vec2(x, y);
};