#ifndef BOB_THE_BLOB_IN_GAME_GLOBAL_SCORE_DISPLAY_H
#define BOB_THE_BLOB_IN_GAME_GLOBAL_SCORE_DISPLAY_H

#include "text/sdl2ttf_font.h"
#include "texturing/texturesCombo.h"

struct Essentials;
struct PlayerAttributes;
namespace sdl2{ class RendererWindow; }

struct ScoreDisplay
{
	const sdl2::Font arial;
	TextureCombo background;
	TextureCombo scoreText;
	
	explicit ScoreDisplay(Essentials& essentials, PlayerAttributes& playerAttributes);
	~ScoreDisplay() = default;
	ScoreDisplay( const ScoreDisplay& ) = delete;
	ScoreDisplay& operator= ( const ScoreDisplay& ) = delete;
	ScoreDisplay( ScoreDisplay&& ) = default;
	ScoreDisplay& operator= ( ScoreDisplay&& ) = default;
	
	void updateScoreText(Essentials& essentials, PlayerAttributes& playerAttributes);
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
};

#endif //BOB_THE_BLOB_IN_GAME_GLOBAL_SCORE_DISPLAY_H