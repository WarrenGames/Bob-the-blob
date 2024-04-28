#ifndef BOB_THE_BLOB_IN_GAME_PLAYER_ATTRIBUTES_H
#define BOB_THE_BLOB_IN_GAME_PLAYER_ATTRIBUTES_H

struct PlayerAttributes
{
	unsigned score;
	unsigned skillLevel;
	bool updateScore;
	
	PlayerAttributes(unsigned selectedSkillLevel);
	~PlayerAttributes() = default;
	PlayerAttributes( const PlayerAttributes& ) = delete;
	PlayerAttributes& operator= ( const PlayerAttributes& ) = delete;
	PlayerAttributes( PlayerAttributes&& ) = default;
	PlayerAttributes& operator= ( PlayerAttributes&& ) = default;
	
	void addToScore(unsigned add);
};

#endif //BOB_THE_BLOB_IN_GAME_PLAYER_ATTRIBUTES_H