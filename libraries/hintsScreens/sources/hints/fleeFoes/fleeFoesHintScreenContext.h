#ifndef HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_CONTEXT_H
#define HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_CONTEXT_H

struct Essentials;

namespace hintsScreens{
	
	class FleeFoes;
	
	namespace fleeFoes{
		void screenContext(Essentials& essentials);
	
		void drawEverything(Essentials& essentials, hintsScreens::FleeFoes& fleeFoes);
	
		void quitScreen(Essentials& essentials, bool& quit);
	}
}

#endif //HINTS_SCREENS_FLEE_FOES_HINTS_SCREEN_CONTEXT_H