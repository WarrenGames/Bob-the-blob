#include "levels/textures/mappingTextures/mappingSprites.h"
#include "levels/textures/mappingTextures/mappingTextures.h"
#include "customTypes/positionTypes.h"
#include <cassert>

MappingSprites::MappingSprites(const MappingTextures& mappingTextures)
{
	createSprites(mappingTextures);
}

void MappingSprites::drawSprite(sdl2::RendererWindow& rndWnd, const Offset& position, std::size_t packNumber, std::size_t packIndex)
{
	drawSprite(rndWnd, position.x, position.y, packNumber, packIndex);
}

void MappingSprites::drawSprite(sdl2::RendererWindow& rndWnd, int xPosition, int yPosition, std::size_t packNumber, std::size_t packIndex)
{
	assert( packNumber < sprites.size() );
	assert( packIndex < sprites[packNumber].size() );
	sprites[packNumber].draw(rndWnd, xPosition, yPosition, packIndex);
}

void MappingSprites::createSprites(const MappingTextures& mappingTextures)
{
	for( auto const &texture : mappingTextures )
	{
		sprites.emplace_back( texture );
	}
}