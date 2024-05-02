#ifndef BOB_THE_BLOB_IN_GAME_LEVELS_GAME_FINISH_INTERFACE_H
#define BOB_THE_BLOB_IN_GAME_LEVELS_GAME_FINISH_INTERFACE_H

#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"
#include "advancedDrawing/texturesLoading/fileTexturesList.h"
#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "time/accurateTime.h"
#include "texts/textLoader.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

class LevelFinishInterface
{
private:
	const TextsBlocks languagesTexts;
	const sdl2::Font font;
	const TextureCombo levelComplete;
	AccurateTimeDelay wavesDelay;
	std::size_t frameNumber;
	const TexturesFilesList grayWavesTextures;
	ConstAnimDraw grayWavesSprites;
	
public:
	explicit LevelFinishInterface(Essentials& essentials);
	~LevelFinishInterface() = default;
	LevelFinishInterface( const LevelFinishInterface& ) = delete;
	LevelFinishInterface& operator= ( const LevelFinishInterface& ) = delete;
	LevelFinishInterface( LevelFinishInterface&& ) = default;
	LevelFinishInterface& operator= ( LevelFinishInterface&& ) = default;
	
	void drawLevelEndMessage(sdl2::RendererWindow& rndWnd) const;
	void updateWaves();
};

#endif //BOB_THE_BLOB_IN_GAME_LEVELS_GAME_FINISH_INTERFACE_H