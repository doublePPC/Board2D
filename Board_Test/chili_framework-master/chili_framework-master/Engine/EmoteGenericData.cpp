#include "EmoteGenericData.h"

BackgroundContainer::BackgroundContainer()
	: grass(Surface("Ressources\\Gazon.bmp")),
	asphalt(Surface("Ressources\\Asphalte.bmp")),
	sidewalk(Surface("Ressources\\Trottoir.bmp"))
{
}

Surface& BackgroundContainer::getGrass()
{
	return grass;
}

Surface& BackgroundContainer::getAsphalt()
{
	return asphalt;
}

Surface& BackgroundContainer::getSidewalk()
{
	return sidewalk;
}

DecorObjectContainer::DecorObjectContainer()
	: walkSign(Surface("Ressources\\TraversePiéton62x133.bmp"))
{
}

Surface& DecorObjectContainer::getWalkSign()
{
	return walkSign;
}
