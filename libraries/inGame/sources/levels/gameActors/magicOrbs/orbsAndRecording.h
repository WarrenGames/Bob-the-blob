#ifndef BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_RECORDING_H
#define BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_RECORDING_H

#include <cstdlib>

class OrbsPackage;
namespace demos{ struct DataPackage; struct ItemData; struct GameEvent; template<typename>class Stack; }
class PlayerAbilities;

namespace recordOrb{
	
	void stackOrbCreationAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage);
	
	void stackOrbCreation(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& stack, demos::DataPackage* demoDataPackage);
	
	void stackOrbDestructionAccordingToColorIndex(OrbsPackage& orbsPackage, demos::DataPackage* demoDataPackage);
	
	void stackOrbDestruction(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& stack);
	
	void stackOrbPowerForPlayer(PlayerAbilities& playerAbilities, demos::Stack< demos::GameEvent >& stack, std::size_t abilityIndex, unsigned playerPower);
}

#endif //BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_RECORDING_H