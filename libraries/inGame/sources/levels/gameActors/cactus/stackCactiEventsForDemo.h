#ifndef BOB_THE_BLOB_IN_GAME_RECORD_CACTI_EVENTS_WITH_DEMO_STACK_H
#define BOB_THE_BLOB_IN_GAME_RECORD_CACTI_EVENTS_WITH_DEMO_STACK_H

class CactiPackage;
namespace demos{ template<typename>class Stack; struct GameEvent; }
struct SinglePlayerData;
struct PlayerAttributes;
class BobsPackage;

namespace recordCactiEvents{
	void stackCactusEvent(CactiPackage& cactiPackage, demos::Stack< demos::GameEvent >& stack);
}

namespace demosCactiEvents{
	void actWithCactiEvents(CactiPackage& cactiPackage, demos::Stack< demos::GameEvent >& stack, SinglePlayerData& player, PlayerAttributes& playerAttributes, BobsPackage& bobsPackage);
	
	void destroyCactus(CactiPackage& cactiPackage, PlayerAttributes& playerAttributes, const demos::GameEvent& gameEvent);
	
	void resetGame(CactiPackage& cactiPackage, SinglePlayerData& player, BobsPackage& bobsPackage, const demos::GameEvent& gameEvent);
}

#endif //BOB_THE_BLOB_IN_GAME_RECORD_CACTI_EVENTS_WITH_DEMO_STACK_H