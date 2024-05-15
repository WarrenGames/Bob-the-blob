#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H

#include "levels/gameActors/playerThings/characterAbility.h"
#include <vector>

struct GameConfigData;

enum : unsigned{
	AbilityStatusInit,
	AbilityStatusOn,
	AbilityStatusOnAndRecorded,
	AbilityStatusOff,
	AbilityStatusOffAndRecorded,
	AbilityStatusMax
};

class PlayerAbilities
{
private:
	std::vector< Ability > data;
	std::vector< unsigned > demoFlag;//Has the ability ?

public:
	explicit PlayerAbilities(const GameConfigData& gameConfigData);
	~PlayerAbilities() = default;
	PlayerAbilities( const PlayerAbilities& ) = delete;
	PlayerAbilities& operator= ( const PlayerAbilities& ) = delete;
	PlayerAbilities( PlayerAbilities&& ) = default;
	PlayerAbilities& operator= ( PlayerAbilities&& ) = default;
	
	void createData(const GameConfigData& gameConfigData);
	const Ability& operator[] ( std::size_t abilityIndex ) const;
	Ability& operator[] ( std::size_t abilityIndex );
	
	std::size_t demoFlagSize() const;
	unsigned getFlag(std::size_t index) const;
	void setDemoFlag(std::size_t index, unsigned flagStatus);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_ABILITIES_H