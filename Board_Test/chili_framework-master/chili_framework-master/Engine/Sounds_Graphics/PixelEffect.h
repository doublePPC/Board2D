#pragma once
#include "..\\Generic\\Colors.h"
#include <cstdlib>

namespace PixelEffects
{
	class FixedColorTransparency
	{
	public:
		FixedColorTransparency() = delete;
		FixedColorTransparency(Color transparent)
			: transparent(transparent)
		{}
		~FixedColorTransparency() = default;
		Color CalculateColor(Color background, Color sprite)
		{
			if (sprite == transparent)
			{
				return background;
			}
			else
			{
				return sprite;
			}
		}
		Color operator()(Color back, Color spri)
		{
			return CalculateColor(back, spri);
		}
	private:
		Color transparent;
	};

	class WhiteRelativeTransparency
	{
	private:
		bool CheckOpacityTreshold(Color sprite)
		{
			return opacityTreshold.GetR() >= sprite.GetR() &&
				opacityTreshold.GetG() >= sprite.GetG() &&
				opacityTreshold.GetB() >= sprite.GetB();
		}
		bool CheckTransparencyTreshold(Color sprite)
		{
			return fullTransparentTreshold.GetR() <= sprite.GetR() &&
				fullTransparentTreshold.GetG() <= sprite.GetG() &&
				fullTransparentTreshold.GetB() <= sprite.GetB();
		}
	public:
		WhiteRelativeTransparency() = delete;
		WhiteRelativeTransparency(Color opacTresh, Color fullTranTresh)
			 : opacityTreshold(opacTresh),
			fullTransparentTreshold(fullTranTresh)
		{}
		~WhiteRelativeTransparency() = default;
		Color CalculateColor(Color background, Color sprite)
		{
			if (CheckOpacityTreshold(sprite))
			{
				return sprite;
			}
			else if (CheckTransparencyTreshold(sprite))
			{
				return background;
			}
			else
			{
				unsigned char red = sprite.GetR() * background.GetR() / 255;
				unsigned char green = sprite.GetG() * background.GetG() / 255;
				unsigned char blue = sprite.GetB() * background.GetB() / 255;
				return Color(red, green, blue);
			}
		}
		Color operator()(Color back, Color spri)
		{
			return CalculateColor(back, spri);
		}
	private:
		Color opacityTreshold;
		Color fullTransparentTreshold;
	};

	class GhostRelativeTransparency
	{
	private:
		unsigned char GetValue(unsigned char backColorLvl, unsigned char spriteColorLvl)
		{
			int gap = std::abs(backColorLvl - spriteColorLvl);
			if (backColorLvl == spriteColorLvl)
			{
				return spriteColorLvl;
			}
			else
			{
				gap = gap * transparencyLevel / 100;
				if (backColorLvl > spriteColorLvl)
				{
					return spriteColorLvl + gap;
				}
				else
				{
					return spriteColorLvl - gap;
				}
			}
		}
	public:
		GhostRelativeTransparency() = delete;
		GhostRelativeTransparency(unsigned char level)
		{
			transparencyLevel = level * 100 / 255;
		}
		~GhostRelativeTransparency() = default;
		Color CalculateColor(Color background, Color sprite)
		{
			unsigned char red = GetValue(background.GetR(), sprite.GetR());
			unsigned char green = GetValue(background.GetG(), sprite.GetG());
			unsigned char blue = GetValue(background.GetB(), sprite.GetB());
			return Color(red, green, blue);
		}
		Color operator()(Color back, Color spri)
		{
			return CalculateColor(back, spri);
		}
	private:
		int transparencyLevel; // the higher the value, the less visible is the sprite color (is a percentage)
	};

	class StraightCopy
	{
	public:
		StraightCopy() = default;
		~StraightCopy() = default;
		Color operator()(Color back, Color spri)
		{
			return spri;
		}
	};
}
