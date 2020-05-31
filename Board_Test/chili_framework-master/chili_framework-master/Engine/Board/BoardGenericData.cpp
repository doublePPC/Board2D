#include "BoardGenericData.h"

visibilityStatus isRectVisible(const Vec2& topLeftPos, const Vec2& botRightPos)
{
	// works with converted coordinates
	if (int(botRightPos.x) >= 0 &&
		int(topLeftPos.x) < BrdData::Cam_X_Size &&
		int(botRightPos.y) >= 0 &&
		int(topLeftPos.y) < BrdData::Cam_Y_Size)
	{
		if (int(topLeftPos.x) >= 0 &&
			int(botRightPos.x) < BrdData::Cam_X_Size &&
			int(topLeftPos.y) >= 0 &&
			int(botRightPos.y) < BrdData::Cam_Y_Size)
		{
			return visibilityStatus::total;
		}
		else
		{
			if (int(botRightPos.x) < BrdData::Cam_X_Size &&
				int(botRightPos.y) < BrdData::Cam_Y_Size &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTL;
			}
			if (int(botRightPos.x) < BrdData::Cam_X_Size &&
				int(botRightPos.y) >= BrdData::Cam_Y_Size &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) < BrdData::Cam_Y_Size)
			{
				return visibilityStatus::partBL;
			}
			if (int(botRightPos.x) >= BrdData::Cam_X_Size &&
				int(botRightPos.y) >= BrdData::Cam_Y_Size &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partBR;
			}
			if (int(botRightPos.x) >= BrdData::Cam_X_Size &&
				int(botRightPos.y) < BrdData::Cam_Y_Size &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTR;
			}
			if (int(botRightPos.x) < BrdData::Cam_X_Size &&
				int(botRightPos.y) < BrdData::Cam_Y_Size &&
				int(topLeftPos.x) < 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partLeft;
			}
			if (int(botRightPos.x) < BrdData::Cam_X_Size &&
				int(botRightPos.y) < BrdData::Cam_Y_Size &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) < 0)
			{
				return visibilityStatus::partTop;
			}
			if (int(botRightPos.x) < BrdData::Cam_X_Size &&
				int(botRightPos.y) >= BrdData::Cam_Y_Size &&
				int(topLeftPos.x) >= 0 &&
				int(topLeftPos.y) >= 0)
			{
				return visibilityStatus::partBottom;
			}
			if (int(botRightPos.x) >= BrdData::Cam_X_Size &&
				int(botRightPos.y) < BrdData::Cam_Y_Size &&
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
		vec.x < BrdData::Cam_X_Size &&
		vec.y >= 0 &&
		vec.y < BrdData::Cam_Y_Size)
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
		x = float(BrdData::Cam_X_Size - 1);
	}
	else
	{
		x = convertedBR.x;
	}
	if (status == visibilityStatus::partBL || status == visibilityStatus::partBR || status == visibilityStatus::partBottom)
	{
		y = float(BrdData::Cam_Y_Size - 1);
	}
	else
	{
		y = convertedBR.y;
	}
	return Vec2(x, y);
};