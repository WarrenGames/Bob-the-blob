#ifndef BOB_THE_BLOB_GAME_MAIN_MENU_CONTEXT_H
#define BOB_THE_BLOB_GAME_MAIN_MENU_CONTEXT_H

struct Essentials;
struct PlayerAttributes;

namespace mainMenu{

struct MenuThings;

void context(Essentials& essentials);

void update(Essentials& essentials, MenuThings& menuThings);

void drawEverything(Essentials& essentials, const MenuThings& menuThings);

void runLevelChoiceMenu(Essentials& essentials, const MenuThings& menuThings);

void runDemoRecording(Essentials& essentials, const MenuThings& menuThings);

void runDemoPlaying(Essentials& essentials, const MenuThings& menuThings);

void runOptionsMenu(Essentials& essentials, const MenuThings& menuThings);

void quitMenu(Essentials& essentials, MenuThings& menuThings);

}

#endif //BOB_THE_BLOB_GAME_MAIN_MENU_CONTEXT_H