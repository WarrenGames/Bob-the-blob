#include "levels/gameActors/magicOrbs/orbsAndDemos.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "levels/maps/bonusesConsts.h"

void demosOrb::createOrbAccordingToColorIndex(OrbsPackage& orbsPackage, std::optional<demos::DataPackage>& demoDataPackage)
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

void demosOrb::destroyOrbAccordingToColorIndex(OrbsPackage& orbsPackage, std::optional<demos::DataPackage>& demoDataPackage)
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
