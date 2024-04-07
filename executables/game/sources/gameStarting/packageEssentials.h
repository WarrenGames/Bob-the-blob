#ifndef BOB_THE_BLOB_GAME_PACKAGE_ESSENTIALS_H
#define BOB_THE_BLOB_GAME_PACKAGE_ESSENTIALS_H

class PrefPathFinder;
struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

void packageEssentials(const PrefPathFinder& prefPath, AppLogFiles& logs, sdl2::RendererWindow& rndWnd);

#endif //BOB_THE_BLOB_GAME_PACKAGE_ESSENTIALS_H