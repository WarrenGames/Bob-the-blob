#ifndef BOB_THE_BLOB_GAME_INITIALIZE_SDL_MODULES_H
#define BOB_THE_BLOB_GAME_INITIALIZE_SDL_MODULES_H

class PrefPathFinder;
struct AppLogFiles;

void initializeSDL_Modules(const PrefPathFinder& prefPath, AppLogFiles& logs);

#endif //BOB_THE_BLOB_GAME_INITIALIZE_SDL_MODULES_H