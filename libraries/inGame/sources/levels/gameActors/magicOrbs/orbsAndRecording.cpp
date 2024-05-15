#include "levels/gameActors/magicOrbs/orbsAndRecording.h"
#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/gameActors/playerThings/singlePlayerData.h"
#include "levels/demos/soundsEventsWithDemos.h"
#include "levels/gameActors/playerThings/playerMapRelativeAbilities.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "levels/maps/bonusesConsts.h"
#include "consts/soundsConsts.h"

void recordOrb::stackOrbCreationAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		switch( orbsPackage.getColorIndex() )
		{
			case bonuses::OrbGreen:
				recordOrb::stackOrbCreation(orbsPackage, demoDataPackage->greenOrbRelatedItemsData.greenOrb, demoDataPackage);
				break;
		}
	}
}

void recordOrb::stackOrbCreation(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& stack, demos::DataPackage* demoDataPackage)
{
	for( auto &orb : orbsPackage )
	{
		if( orb.status == OrbStatusCreated )
		{
			orb.status = OrbStatusCreatedAndRecorded;
			demos::recordSoundEvent(demoDataPackage, sounds::Chunk_FluxWow, sounds::Channel_ItemsAppearance);
			stack.emplaceElement( demos::ItemData{ stack.getCurrentElapsedMicroSecondsTime(), orb.orbCoordinates, demos::eventItem::Creation, orb.itemId } );
		}
	}
}

void recordOrb::stackOrbDestructionAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		switch( orbsPackage.getColorIndex() )
		{
			case bonuses::OrbGreen:
				recordOrb::stackOrbDestruction(orbsPackage, demoDataPackage->greenOrbRelatedItemsData.greenOrb);
				break;
		}
	}
}

void recordOrb::stackOrbDestruction(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& stack)
{
	for( auto &orb : orbsPackage )
	{
		if( orb.status == OrbStatusDestroyed )
		{
			orb.status = OrbStatusDestroyedAndRecorded;
			stack.emplaceElement( demos::ItemData{ stack.getCurrentElapsedMicroSecondsTime(), orb.orbCoordinates, demos::eventItem::Destruction, orb.itemId } );
		}
	}
}

void recordOrb::stackOrbPowerEnableForPlayer(PlayerAbilities& playerAbilities, demos::Stack< demos::GameEvent >& stack, std::size_t abilityIndex, unsigned playerPower)
{
	if( playerAbilities.getFlag(abilityIndex) == AbilityStatusOn )
	{
		stack.emplaceElement( demos::GameEvent{stack.getCurrentElapsedMicroSecondsTime(), demos::eventCat::PlayerPowerEnable, playerPower, 0 } );
		playerAbilities.setDemoFlag(abilityIndex, AbilityStatusOnAndRecorded);
	}
}

void recordOrb::stackOrbPowerDisableForPlayer(PlayerAbilities& playerAbilities, demos::Stack< demos::GameEvent >& stack, std::size_t abilityIndex, unsigned playerPower)
{
	if( playerAbilities.getFlag(abilityIndex) == AbilityStatusOff )
	{
		stack.emplaceElement( demos::GameEvent{stack.getCurrentElapsedMicroSecondsTime(), demos::eventCat::PlayerPowerDisable, playerPower, 0 } );
		playerAbilities.setDemoFlag(abilityIndex, AbilityStatusOffAndRecorded);
	}
}