#ifndef BOB_THE_BLOB_GAME_LEVEL_CHOICE_CONSTS_H
#define BOB_THE_BLOB_GAME_LEVEL_CHOICE_CONSTS_H

namespace levelChoice{
	constexpr int LevelsPerPage = 9;
	
	constexpr SDL_Color SelectedButtonColor = { 255, 255, 255, 255 };
	
	constexpr SDL_Color OffButtonColor = { 128, 128, 128, 255 };
	
	constexpr char LevelsListFilePath[] = "data/levelsMaps/levelsList.txt";
	
	constexpr char InterfaceTexts[] = "levelChoiceMenu/interface.txt";
	
	enum{
		TxtLevelList,
		TxtPrecedentBtn,
		TxtNextBtn,
		TxtQuit,
		TxtMax
	};
}

#endif //BOB_THE_BLOB_GAME_LEVEL_CHOICE_CONSTS_H