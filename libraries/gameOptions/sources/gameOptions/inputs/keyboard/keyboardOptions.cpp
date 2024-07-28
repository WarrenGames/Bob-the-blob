#include "gameOptions/inputs/keyboard/keyboardOptions.h"
#include "gameOptions/consts/optionsConsts.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "consts/filesAndPaths.h"
#include "text/sdl2ttf_font.h"
#include "consts/fontsSizes.h"
#include "consts/playerInputsConsts.h"
#include "consts/screenConsts.h"
#include "keycodes/keycodesOverload.h"
#include "texturing/texturePosition.h"
#include "prefPath/prefPathFinder.h"
#include "texts/textLoader.h"
#include "logging/logsStruct.h"
#include <cassert>

KeyboardOptions::KeyboardOptions(Essentials& essentials, const sdl2::Font& arialFont, const TextsBlocks keyboardMenusTexts):
	keyboardInputsConfig{ essentials.logs, path::getInputsFilePath(essentials.prefPath, files::KeyboardInputsFile) },
	pushNewKeyHint{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybChooseNewKey], BlackCol,	
						TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE, true, true } }
{
	createKeycodesButtons(essentials.logs, essentials.rndWnd, arialFont);
}

void KeyboardOptions::createKeycodesButtons(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const sdl2::Font& arialFont)
{
	for( std::size_t i{0} ; i < keyboardInputsConfig.size() ; ++i )
	{
		int heightCenterPosition{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
		
		keycodesButtons.emplace_back( HighLightButton{logs, rndWnd, arialFont, getNameFromKeycode(keyboardInputsConfig.getKeycode(i) ), options::BtnsTxtCol, 
						SDL_Rect{ SQR_SIZE * 4 - options::ButtonsWidth / 2, heightCenterPosition - options::ButtonsHeight / 2, 
									options::ButtonsWidth, options::ButtonsHeight }, options::BtnsHighLightCol } );
		
	}
}

void KeyboardOptions::updateButtons(const Offset& mousePosition, bool mouseButtonState)
{
	for( auto &btn : keycodesButtons )
	{
		btn.updateButton(mousePosition, mouseButtonState);
	}
}

void KeyboardOptions::drawButtons(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &btn : keycodesButtons )
	{
		btn.drawButton(rndWnd);
	}
}

void KeyboardOptions::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	drawButtons(rndWnd);
}

void KeyboardOptions::updateKeycodeWithUser(Essentials& essentials, const sdl2::Font& arialFont)
{
	for( size_t i{0} ; i < keycodesButtons.size() ; ++i )
	{
		if( keycodesButtons[i].buttonClicked() )
		{
			waitForKeycode(essentials, arialFont, i);
		}
	}
}

void KeyboardOptions::waitForKeycode(Essentials& essentials, const sdl2::Font& arialFont, std::size_t clickedButtonNumber)
{
	SDL_Event event;
	bool waitForKeycode{ true };
	pushNewKeyHint.draw(essentials.rndWnd);
	essentials.rndWnd.displayRenderer();
	while( waitForKeycode )
	{
		if( SDL_PollEvent(&event) )
		{
			switch( event.type )
			{
				case SDL_KEYDOWN:
					checkKeyDown(essentials, arialFont, clickedButtonNumber, event.key.keysym.sym);
					waitForKeycode = false;
					break;
			}
		}
		SDL_Delay(1);
	}
}

void KeyboardOptions::checkKeyDown(Essentials& essentials, const sdl2::Font& arialFont, std::size_t clickedButtonNumber, SDL_Keycode newKeycode)
{
	if( newKeycode != SDLK_ESCAPE )
	{
		changeKeycode(essentials, arialFont, clickedButtonNumber, newKeycode);
	}
}

void KeyboardOptions::changeKeycode(Essentials& essentials, const sdl2::Font& arialFont, std::size_t keycodeNumber, SDL_Keycode newKeycode)
{
	assert( newKeycode != SDLK_UNKNOWN );
	assert( keycodeNumber < keyboardInputsConfig.size() && keycodeNumber < keycodesButtons.size() );
	keyboardInputsConfig.setKeycode(keycodeNumber, newKeycode);
	keycodesButtons[keycodeNumber].changeText(essentials.logs, essentials.rndWnd, arialFont, getNameFromKeycode(newKeycode), options::BtnsTxtCol );
}

void KeyboardOptions::recordModificationsToFiles(Essentials& essentials) const
{
	keyboardInputsConfig.writeKeycodesInFile(essentials.logs, path::getInputsFilePath(essentials.prefPath, files::KeyboardInputsFile) );
}