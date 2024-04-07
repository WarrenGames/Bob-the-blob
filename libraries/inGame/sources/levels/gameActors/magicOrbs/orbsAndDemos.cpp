#include "levels/gameActors/magicOrbs/orbsAndDemos.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "demos/data/dataPackage.h"
#include "demos/data/determineGameStatus.h"
#include "demos/consts/gameEventsConsts.h"
#include "levels/maps/bonusesConsts.h"

void demosOrb::createOrbAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		switch( orbsPackage.getColorIndex() )
		{
			case bonuses::OrbGreen:
				demosOrb::createOrb(orbsPackage, demoDataPackage->greenOrbRelatedItemsData.greenOrb);
				break;
		}
	}
}

void demosOrb::createOrb(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& orbsStack)
{
	orbsPackage.createWithDemo(orbsStack);
}

void demosOrb::destroyOrbAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		switch( orbsPackage.getColorIndex() )
		{
			case bonuses::OrbGreen:
				demosOrb::destroyOrb(orbsPackage, demoDataPackage->greenOrbRelatedItemsData.greenOrb);
				break;
		}
	}
}

void demosOrb::destroyOrb(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& orbsStack)
{
	orbsPackage.destroyWithDemo(orbsStack);
}
