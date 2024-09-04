#include "levels/gameActors/magicOrbs/orbsPackage.h"
#include "levels/maps/gameMap.h"
#include "levels/loadings/getConfigFileNumber.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"
#include "exceptions/readErrorExcept.h"
#include "soundSystem/soundsPlayer.h"
#include "prefPath/prefPathFinder.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/filesAndPaths.h"
#include "levels/demosRecordingAndPlaying/consts/gameEventsConsts.h"
#include "consts/soundsConsts.h"
#include <algorithm>

OrbsPackage::OrbsPackage(std::size_t orbColor, int orbWorthValue, std::chrono::milliseconds creationDelay, std::chrono::milliseconds durationDelay):
	orbDurationDelay{ durationDelay },
	orbCreationDelay{ creationDelay },
	orbColorIndex{ orbColor },
	orbWorth{ orbWorthValue },
	orbsIdentityNumber{ 0 },
	isLoadingPerfect{true}
{

}

void OrbsPackage::createOrbs(const Coord2D& newCoordinates, const GameMap& gameMap, std::optional<demos::DataPackage>& demoDataPackage, const SoundPlayer& soundPlayer)
{
	switch( demos::getGameStatus(demoDataPackage) )
	{
		case demos::GameIsRecording:
			createNewOrbIfTimeHasElapsed(newCoordinates, gameMap, soundPlayer);
			break;
		case demos::GameHasPlayerInputs:
			createNewOrbIfTimeHasElapsed(newCoordinates, gameMap, soundPlayer);
			break;
		case demos::GameIsDemo:
		
			break;
	}
}

std::size_t OrbsPackage::getColorIndex() const
{
	return orbColorIndex;
}

int OrbsPackage::getOrbScoreValue() const
{
	return orbWorth;
}

unsigned OrbsPackage::getCurrentIdentityNumber() const
{
	return orbsIdentityNumber;
}

void OrbsPackage::createWithDemo(demos::Stack< demos::ItemData >& orbsStack)
{
	if( orbsStack.getCommandsNumber() > 0 && orbsStack.hasLastTimeElapsed() && orbsStack.getLastElement().event == demos::eventItem::Creation )
	{
		findPlaceAndCreate(orbsStack.getLastElement().position, orbsStack.getLastElement().itemId);
		orbsStack.pop_back();
	}
}

void OrbsPackage::destroyWithDemo(demos::Stack< demos::ItemData >& orbsStack)
{
	if( orbsStack.getCommandsNumber() > 0 && orbsStack.hasLastTimeElapsed() && orbsStack.getLastElement().event == demos::eventItem::Destruction )
	{
		auto it = std::find_if( std::begin( orbs ) , std::end( orbs ), [&orbsStack](auto &orb){ return orbsStack.getLastElement().itemId == orb.itemId; } );
		
		if( it != orbs.end() )
		{
			it->isPresent = false;
			orbsStack.pop_back();
		}
	}
}

void OrbsPackage::abortOrbsIfAny()
{
	for( auto &orb : orbs )
	{
		orb.abortOrbPresenceIfAny(orbDurationDelay);
	}
}

std::vector< SingleOrb >::const_iterator OrbsPackage::begin() const
{
	return orbs.cbegin();
}

std::vector< SingleOrb >::const_iterator OrbsPackage::end() const
{
	return orbs.cend();
}

std::vector< SingleOrb >::iterator OrbsPackage::begin()
{
	return orbs.begin();
}

std::vector< SingleOrb >::iterator OrbsPackage::end()
{
	return orbs.end();
}

void OrbsPackage::findAndDestroyAccordingToPlayerCoordinates(const Coord2D& playerCoordinates)
{
	auto it = std::ranges::find_if( orbs, [&playerCoordinates](auto const &orb){ return coords::are2DCoordsTheSame(orb.orbCoordinates, playerCoordinates); } );
	
	if( it != orbs.end() )
	{
		it->isPresent = false;
	}
}

void OrbsPackage::findPlaceAndCreate(const Coord2D& newCoordinates, unsigned idNumber)
{
	auto newOrbIterator = std::ranges::find_if( orbs, [](auto const &orb){ return orb.isPresent == false; } );
	
	if( newOrbIterator != orbs.end() )
	{
		newOrbIterator->createOrb(orbColorIndex, newCoordinates, idNumber);
	}
	else{
		orbs.emplace_back( SingleOrb{orbColorIndex, newCoordinates, idNumber} );
	}
}

void OrbsPackage::createNewOrbIfTimeHasElapsed(const Coord2D& newCoordinates, const GameMap& gameMap, const SoundPlayer& soundPlayer)
{
	if( gameMap.matrix.isInsideBoundaries(newCoordinates) )
	{
		if( creationDelayMeasure.hasTimeElapsed(orbCreationDelay) )
		{
			creationDelayMeasure.joinTimePoints();
			
			findPlaceAndCreate(newCoordinates, orbsIdentityNumber);
			soundPlayer.playSoundOnGroup(sounds::Chunk_FluxWow, sounds::Channel_ItemsAppearance);
			incrementIdentityNumber();
		}
	}
}

void OrbsPackage::incrementIdentityNumber()
{
	orbsIdentityNumber++;
}
