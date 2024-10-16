#ifndef BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_DEMOS_H
#define BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_DEMOS_H

#include <optional>

class OrbsPackage;
namespace demos{ struct DataPackage; struct ItemData; template<typename>class Stack; }

namespace demosOrb{
	
	void createOrbAccordingToColorIndex(OrbsPackage& orbsPackage, std::optional<demos::DataPackage>& demoDataPackage);
	
	void createOrb(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& orbsStack);
	
	void destroyOrbAccordingToColorIndex(OrbsPackage& orbsPackage, std::optional<demos::DataPackage>& demoDataPackage);
	
	void destroyOrb(OrbsPackage& orbsPackage, demos::Stack< demos::ItemData >& orbsStack);
}

#endif //BOB_THE_BLOB_IN_GAME_MAGIC_ORBS_DEMOS_H