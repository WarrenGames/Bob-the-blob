#ifndef BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_TRANSFER_DEMO_STACK_H
#define BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_TRANSFER_DEMO_STACK_H

#include <optional>

struct RecordedEvents;

namespace demos{
	struct DataPackage;

void transferEventsStackInCaseOfDemo(std::optional<demos::DataPackage>& demoDataPackage, RecordedEvents& recordedEvents);

void transferEventsStackInCaseOfRecording(std::optional<demos::DataPackage>& demoDataPackage, RecordedEvents& recordedEvents);

}
#endif //BOB_THE_BLOB_IN_GAME_LEVEL_DEMOS_TRANSFER_DEMO_STACK_H