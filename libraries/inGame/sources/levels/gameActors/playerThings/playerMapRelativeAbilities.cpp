#include "levels/gameActors/playerThings/playerMapRelativeAbilities.h"
#include "levels/loadings/getConfigFileNumber.h"
#include "prefPath/prefPathFinder.h"
#include "levels/gameActors/playerActorsConsts.h"
#include "consts/filesAndPaths.h"
#include <cassert>

PlayerAbilities::PlayerAbilities(const PrefPathFinder& prefPath)
{
	createData(prefPath);
	assert( data.size() == abilities::CanEatMax );
	demoFlag.resize( data.size(), false );
}

void PlayerAbilities::createData(const PrefPathFinder& prefPath)
{
	data.emplace_back( Ability{ getUnsignedIntFromFile( prefPath.getFsPath() / files::OptionsDir / files::BobsEatableDelayFile, "eatable bobs delay" ) } );
	data.emplace_back( Ability{ getUnsignedIntFromFile( prefPath.getFsPath() / files::OptionsDir / files::PlayerCanEatCacti, "eatable cacti delay" ) } );
}

void PlayerAbilities::abortAbilities()
{
	for( auto &ability : data )
	{
		ability.abortAbility();
	}
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

bool PlayerAbilities::hasDemoFlag(std::size_t index) const
{
	assert( index < demoFlag.size() );
	return demoFlag[index];
}

void PlayerAbilities::setDemoFlag(std::size_t index, bool flagStatus)
{
	assert( index < demoFlag.size() );
	demoFlag[index] = flagStatus;
}
	