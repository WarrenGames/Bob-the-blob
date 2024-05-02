#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H

#include "levels/gameActors/playerThings/characterAbility.h"
#include <vector>

class PrefPathFinder;

class PlayerAbilities
{
private:
	std::vector< Ability > data;
	std::vector< bool > demoFlag;//Has the ability ?

public:
	explicit PlayerAbilities(const PrefPathFinder& prefPath);
	~PlayerAbilities() = default;
	PlayerAbilities( const PlayerAbilities& ) = delete;
	PlayerAbilities& operator= ( const PlayerAbilities& ) = delete;
	PlayerAbilities( PlayerAbilities&& ) = default;
	PlayerAbilities& operator= ( PlayerAbilities&& ) = default;
	
	void createData(const PrefPathFinder& prefPath);
	void abortAbilities();
	const Ability& operator[] ( std::size_t abilityIndex ) const;
	Ability& operator[] ( std::size_t abilityIndex );
	
	std::size_t demoFlagSize() const;
	bool hasDemoFlag(std::size_t index) const;
	void setDemoFlag(std::size_t index, bool flagStatus);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H