#ifndef BOB_THE_BLOB_IN_GAME_MEXICAN_INFOS_PANEL_H
#define BOB_THE_BLOB_IN_GAME_MEXICAN_INFOS_PANEL_H

#include "levels/textures/infosPanel/infosBoard.h"
#include "levels/textures/drawing/scoreDisplay.h"
#include "levels/textures/infosPanel/infoGradient.h"
#include "levels/textures/infosPanel/givenElementCount.h"

struct Essentials;
struct PlayerAttributes;
namespace sdl2{ class RendererWindow; }
class BonusesMap;
struct GameConfigData;
class CactiPackage;

struct MexicanInfosPanel
{
	InfosBoard infosBoard;
	ScoreDisplay scoreDisplay;
	InfoGradient canBeEatenBobsGradient;
	InfoGradient canBeEatenCactiGradient;
	ElementCountDisplay goldIngotsCountDisplay;
	ElementCountDisplay cactiCountDisplay;
	
	explicit MexicanInfosPanel(Essentials& essentials, PlayerAttributes& playerAttributes, const BonusesMap& bonusesMap, const CactiPackage& cacti, 
								const GameConfigData& gameConfigData);
	~MexicanInfosPanel() = default;
	MexicanInfosPanel( const MexicanInfosPanel& ) = delete;
	MexicanInfosPanel& operator= ( const MexicanInfosPanel& ) = delete;
	MexicanInfosPanel( MexicanInfosPanel&& ) = default;
	MexicanInfosPanel& operator= ( MexicanInfosPanel&& ) = default;
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
};

#endif //BOB_THE_BLOB_IN_GAME_MEXICAN_INFOS_PANEL_H