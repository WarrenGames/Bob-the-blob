#include "levels/gameActors/playerThings/playerMapRelativeAbilities.h"
#include "levels/loadings/gameConfigurationData.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/filesAndPaths.h"
#include <cassert>

PlayerAbilities::PlayerAbilities(const GameConfigData& gameConfigData)
{
	createData(gameConfigData);
	assert( data.size() == abilities::CanEatMax );
	demoFlag.resize( data.size(), AbilityStatusInit );
}

void PlayerAbilities::createData(const GameConfigData& gameConfigData)
{
	data.emplace_back( Ability{ gameConfigData.bobVulnerability.count() } );
	data.emplace_back( Ability{ gameConfigData.playerCanEatCactiDelay.count() } );
}

const Ability& PlayerAbilities::operator[] ( std::size_t abilityIndex ) const
{
	assert( abilityIndex < data.size() );
	return data[abilityIndex];
}

Ability& PlayerAbilities::operator[] ( std::size_t abilityIndex )
{
	assert( abilityIndex < data.size() );
	return data[abilityIndex];
}

std::size_t PlayerAbilities::demoFlagSize() const
{
	return demoFlag.size();
}

unsigned PlayerAbilities::getFlag(std::size_t index) const
{
	assert( index < demoFlag.size() );
	return demoFlag[index];
}

void PlayerAbilities::setDemoFlag(std::size_t index, unsigned flagStatus)
{
	assert( index < demoFlag.size() );
	demoFlag[index] = flagStatus;
}
	