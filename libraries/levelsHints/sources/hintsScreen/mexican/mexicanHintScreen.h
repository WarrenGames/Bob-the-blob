#ifndef MEXICAN_HINTS_SCREEN_H
#define MEXICAN_HINTS_SCREEN_H

struct Essentials;
struct MexicanHintsData;

namespace hintScreen{

void displayMexicanLevelHelp(Essentials& essentials);

void carryOnToGame(Essentials& essentials, MexicanHintsData& mexicanHintsData);

void drawScreenElements(Essentials& essentials, const MexicanHintsData& mexicanHintsData);

}

#endif //MEXICAN_HINTS_SCREEN_H