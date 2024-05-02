#ifndef BOB_THE_BLOB_DEMOS_LIB_CONSTS_H
#define BOB_THE_BLOB_DEMOS_LIB_CONSTS_H

namespace demos{
	constexpr std::size_t DefaultReservedDataForRecording = 100000;
	
	constexpr std::size_t DefaultSmallDataReservedForRecording = 4000;
	
	constexpr std::size_t QuitEventReservedSize = 1;
	
	constexpr std::size_t PlayerDefaultNumber = 1;
	
	enum : unsigned{	GameHasPlayerInputs, 
						GameIsRecording, 
						GameIsDemo,
						GameDemoEnumMax
	};
	
	constexpr char DefaultDemoName[] = "demo.txt";
}

#endif //BOB_THE_BLOB_DEMOS_LIB_CONSTS_H