#include "EmoteGenericData.h"

BackgroundContainer::BackgroundContainer()
	: citySet1(Surface("Ressources\\Emote_Ress\\CitySet1.bmp"))
{
	/*grass(Surface("Ressources\\Gazon.bmp")),
	asphalt(Surface("Ressources\\Asphalte.bmp")),
	sidewalk(Surface("Ressources\\Trottoir.bmp"))*/
}

Surface& BackgroundContainer::getCitySet1()
{
	return citySet1;
}

//Surface& BackgroundContainer::getGrass()
//{
//	return grass;
//}
//
//Surface& BackgroundContainer::getAsphalt()
//{
//	return asphalt;
//}
//
//Surface& BackgroundContainer::getSidewalk()
//{
//	return sidewalk;
//}

DecorObjectContainer::DecorObjectContainer()
	: walkSign(Surface("Ressources\\Emote_Ress\\TraversePiéton62x133.bmp"))
{
	
}

Surface& DecorObjectContainer::getWalkSign()
{
	return walkSign;
}
