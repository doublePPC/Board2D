#include "EmoteAnimations.h"

void Animation::adjustFacing(const Facing currentFacing)
{
	if (currentFacing == Facing::down)
	{
		animData.currentAnimY = 0;
	}
	else if (currentFacing == Facing::left)
	{
		animData.currentAnimY = 2;
	}
	else if (currentFacing == Facing::right)
	{
		animData.currentAnimY = 1;
	}
	else if (currentFacing == Facing::up)
	{
		animData.currentAnimY = 3;
	}
}

void Animation::adjustAnimation(float dt)
{
	if (animData.currentAnimX == 0)
	{
		animData.currentAnimX = 1;
	}
	else
	{
		animTimeElapsed += dt;
		if (animTimeElapsed > animationDelay)
		{
			animTimeElapsed = 0.0f;
			animData.currentAnimX++;
			if (animData.currentAnimX > amountOfAnim)
			{
				animData.currentAnimX = 1;
			}
		}
	}
}

Animation::Animation(int amountOfAnim, float animationDelay, const animationData& animDat )
	: animationDelay(animationDelay),
	animTimeElapsed(0.0f),
	amountOfAnim(amountOfAnim),
	animData(animDat)
{
}

Animation::Animation(const Animation& ref)
	: animationDelay(ref.animationDelay),
	animTimeElapsed(ref.animTimeElapsed),
	amountOfAnim(ref.amountOfAnim)
{
	animData = ref.animData;
}

Animation& Animation::operator=(const Animation& ref)
{
	animationDelay = ref.animationDelay;
	animTimeElapsed = ref.animTimeElapsed;
	amountOfAnim = ref.amountOfAnim;
	animData = ref.animData;
	return *this;
}

Animation::~Animation()
{
}

void Animation::update(int speed, const Facing facing, float dt)
{
	adjustFacing(facing);
	if (speed == 0)
	{
		animData.currentAnimX = 0;
	}
	else
	{
		adjustAnimation(dt);
	}
}

void Animation::draw(Surface& refSprite, Graphics& gfx, const Vec2& convertedPos, TilePortion visiblePart)
{
	int xStart = animData.currentAnimX * animData.sheetUnitWidth;
	int yStart = animData.currentAnimY * animData.sheetUnitHeight;
	gfx.DrawSheetFragment(convertedPos, refSprite, visiblePart.topLeft, visiblePart.bottomRight, animData.transparentColor, xStart, yStart);
}
