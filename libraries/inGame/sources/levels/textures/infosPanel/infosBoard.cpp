#include "levels/textures/infosPanel/infosBoard.h"
#include "package/essentials.h"
#include "consts/screenConsts.h"
#include <cassert>

constexpr char InfosBoardPrefix[] = "textures/interface/infosBoard";

constexpr int InfosBoardHeight = SQR_SIZE;
constexpr int InfosBoardXPos = 0;

InfosBoard::InfosBoard(Essentials& essentials, unsigned boardEnum):
	texturePosition{ InfosBoardXPos, GameScreenHeight - InfosBoardHeight, false, false },
	infosBoard{ essentials.logs, essentials.rndWnd, InfosBoardPrefix + std::to_string( boardEnum ) + ".png"}
{
	if( infosBoard.texture )
	{
		infosBoard.resetSpritePosition(texturePosition);
	}
	else{
		essentials.logs.error << "Error: couldn't load 'InfosBoard' texture with enum value: " << boardEnum << " .\n";
	}
}

void InfosBoard::drawBoard(sdl2::RendererWindow& rndWnd) const
{
	infosBoard.draw(rndWnd);
}
