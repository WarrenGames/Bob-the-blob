#include "levels/textures/standardLevel/texturesSprites.h"
#include "levels/textures/standardLevel/texturesLoader.h"

StandardLevelSprites::StandardLevelSprites(const StandardLevelTexturesLoader& textures):
	commonSprites{ textures.commonTextures, textures.blobTexturesLoader },
	blobSprites{ textures.blobTexturesLoader },
	mapSprites{ textures.mapTextures }
{
	
}