#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"

class MappingTextures;
namespace sdl2{ class RendererWindow; }

class MappingSprites
{
private:
	std::vector< ConstAnimDraw > sprites;

public:
	explicit MappingSprites(const MappingTextures& mappingTextures);
	~MappingSprites() = default;
	MappingSprites( const MappingSprites& ) = delete;
	MappingSprites& operator= ( const MappingSprites& ) = delete;
	MappingSprites( MappingSprites&& ) = default;
	MappingSprites& operator= ( MappingSprites&& ) = default;
	
	void drawSprite(sdl2::RendererWindow& rndWnd, const Offset& position, std::size_t packNumber, std::size_t packIndex);
	void drawSprite(sdl2::RendererWindow& rndWnd, int xPosition, int yPosition, std::size_t packNumber, std::size_t packIndex);
	
private:
	void createSprites(const MappingTextures& mappingTextures);
};