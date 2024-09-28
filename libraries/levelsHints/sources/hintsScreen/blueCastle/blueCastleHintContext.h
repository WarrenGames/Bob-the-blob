#ifndef LEVELS_HINTS_BLUE_CASTLE_CONTEXT_H
#define LEVELS_HINTS_BLUE_CASTLE_CONTEXT_H

struct Essentials;
class BlueCastleHintsScreen;

namespace hintScreen{

void displayBlueCastleLevelHelp(Essentials& essentials);

void carryOnToBlueCastleGame(Essentials& essentials, BlueCastleHintsScreen& blueCastleHintsScreen);

void drawBlueCastleScreenElements(Essentials& essentials, const BlueCastleHintsScreen& blueCastleHintsScreen);

}

#endif //LEVELS_HINTS_BLUE_CASTLE_CONTEXT_H