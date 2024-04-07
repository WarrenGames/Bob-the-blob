#ifndef BOB_THE_BLOB_IN_GAME_TEXTURES_INFOS_BOARD_H
#define BOB_THE_BLOB_IN_GAME_TEXTURES_INFOS_BOARD_H

#include "texturing/texturesCombo.h"
#include "texturing/texturePosition.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

enum : unsigned{
	InfosBoardGreenGranit,
	InfosBoardRedGranit,
	InfosBoardMax
};

class InfosBoard
{
private:
	TexturePosition texturePosition;
	TextureCombo infosBoard;

public:
	explicit InfosBoard(Essentials& essentials, unsigned boardEnum);
	~InfosBoard() = default;
	InfosBoard( const InfosBoard& ) = delete;
	InfosBoard& operator= ( const InfosBoard& ) = delete;
	InfosBoard( InfosBoard&& ) = default;
	InfosBoard& operator= ( InfosBoard&& ) = default;
	
	void drawBoard(sdl2::RendererWindow& rndWnd) const;
};

#endif //BOB_THE_BLOB_IN_GAME_TEXTURES_INFOS_BOARD_H