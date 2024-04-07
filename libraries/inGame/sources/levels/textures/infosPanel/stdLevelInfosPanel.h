#ifndef BOB_THE_BLOB_IN_GAME_STD_LVL_INFOS_PANEL_H
#define BOB_THE_BLOB_IN_GAME_STD_LVL_INFOS_PANEL_H

#include "levels/textures/infosPanel/infosBoard.h"
#include "levels/textures/drawing/scoreDisplay.h"
#include "levels/textures/infosPanel/infoGradient.h"
#include "levels/textures/infosPanel/givenElementCount.h"

struct Essentials;
struct PlayerAttributes;
namespace sdl2{ class RendererWindow; }
class BonusesMap;

struct StdLevelInfosPanel
{
	InfosBoard infosBoard;
	ScoreDisplay scoreDisplay;
	InfoGradient canBeEatenBobsGradient;
	ElementCountDisplay goldIngotsCountDisplay;
	
	explicit StdLevelInfosPanel(Essentials& essentials, PlayerAttributes& playerAttributes, const BonusesMap& bonusesMap);
	~StdLevelInfosPanel() = default;
	StdLevelInfosPanel( const StdLevelInfosPanel& ) = delete;
	StdLevelInfosPanel& operator= ( const StdLevelInfosPanel& ) = delete;
	StdLevelInfosPanel( StdLevelInfosPanel&& ) = default;
	StdLevelInfosPanel& operator= ( StdLevelInfosPanel&& ) = default;
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
};

#endif //BOB_THE_BLOB_IN_GAME_STD_LVL_INFOS_PANEL_H