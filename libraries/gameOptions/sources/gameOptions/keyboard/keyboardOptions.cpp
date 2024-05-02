#include "gameOptions/keyboard/keyboardOptions.h"
#include "gameOptions/consts/optionsConsts.h"
#include "pathsFunctions/pathsFunctions.h"
#include "package/essentials.h"
#include "consts/filesAndPaths.h"
#include "consts/fontsSizes.h"
#include "consts/playerInputsConsts.h"
#include "consts/screenConsts.h"
#include "keycodes/keycodesOverload.h"
#include "texturing/texturePosition.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include <cassert>

KeyboardOptions::KeyboardOptions(Essentials& essentials):
	keyboardFunctionsTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::KeyboardFuncLanguageTexts), MoveMax },
	keyboardMenusTexts{ essentials.logs.error, path::getLanguageFile(essentials.chosenLanguage, options::KeyboardMenuLanguageTexts), options::KeybColumnTxtMax },
	arialFont{ essentials.logs.error, ArialFontPath, MediumFontSize },
	keyboardInputsConfig{ essentials.logs, path::getInputsFilePath(essentials.prefPath, files::KeyboardInputsFile) },
	functionsColumn{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybFuncColumnTxt], options::BtnsInfosCol, 
						TexturePosition{ SQR_SIZE, SQR_SIZE * 3, false, true} },
	keycodesColumn{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybKeycodesColumnTxt], options::BtnsInfosCol,
						TexturePosition{ SQR_SIZE * 6, SQR_SIZE * 3, true, true } },
	pushNewKeyHint{ essentials.logs, essentials.rndWnd, arialFont, keyboardMenusTexts[options::KeybChooseNewKey], BlackCol,	
						TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SQR_SIZE, true, true } }
{
	createKeycodesButtons(essentials.logs, essentials.rndWnd);
}

void KeyboardOptions::createKeycodesButtons(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	for( std::size_t i{0} ; i < keyboardInputsConfig.size() ; ++i )
	{
		int heightCenterPosition{ SQR_SIZE * ( 4 + static_cast<int>(i) ) };
		
		keycodesButtons.emplace_back( HighLightButton{logs, rndWnd, arialFont, getNameFromKeycode(keyboardInputsConfig.getKeycode(i) ), options::BtnsTxtCol, 
						SDL_Rect{ SQR_SIZE * 6 - options::ButtonsWidth / 2, heightCenterPosition - options::ButtonsHeight / 2, 
									options::ButtonsWidth, options::ButtonsHeight }, options::BtnsHighLightCol } );
		assert( i < keyboardFunctionsTexts.size() );
		buttonsInfos.emplace_back( TextureCombo{logs, rndWnd, arialFont, keyboardFunctionsTexts[i], options::BtnsInfosCol, TexturePosition{SQR_SIZE, heightCenterPosition, false, true} } );
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

void KeyboardOptions::drawInfosTexts(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &txt : buttonsInfos )
	{
		txt.draw(rndWnd);
	}
}

void KeyboardOptions::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	drawButtons(rndWnd);
	drawInfosTexts(rndWnd);
	functionsColumn.draw(rndWnd);
	keycodesColumn.draw(rndWnd);
}

void KeyboardOptions::updateKeycodeWithUser(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	for( size_t i{0} ; i < keycodesButtons.size() ; ++i )
	{
		if( keycodesButtons[i].buttonClicked() )
		{
			waitForKeycode(logs, rndWnd, i);
		}
	}
}

void KeyboardOptions::waitForKeycode(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t clickedButtonNumber)
{
	SDL_Event event;
	bool waitForKeycode{ true };
	pushNewKeyHint.draw(rndWnd);
	rndWnd.displayRenderer();
	while( waitForKeycode )
	{
		if( SDL_PollEvent(&event) )
		{
			switch( event.type )
			{
				case SDL_KEYDOWN:
					checkKeyDown(logs, rndWnd, clickedButtonNumber, event.key.keysym.sym);
					waitForKeycode = false;
					break;
			}
		}
		SDL_Delay(1);
	}
}

void KeyboardOptions::checkKeyDown(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t clickedButtonNumber, SDL_Keycode newKeycode)
{
	if( newKeycode != SDLK_ESCAPE )
	{
		changeKeycode(logs, rndWnd, clickedButtonNumber, newKeycode);
	}
}

void KeyboardOptions::changeKeycode(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::size_t keycodeNumber, SDL_Keycode newKeycode)
{
	assert( newKeycode != SDLK_UNKNOWN );
	assert( keycodeNumber < keyboardInputsConfig.size() && keycodeNumber < keycodesButtons.size() );
	keyboardInputsConfig.setKeycode(keycodeNumber, newKeycode);
	keycodesButtons[keycodeNumber].changeText(logs, rndWnd, arialFont, getNameFromKeycode(newKeycode), options::BtnsTxtCol );
}

void KeyboardOptions::recordModificationsToFiles(Essentials& essentials) const
{
	keyboardInputsConfig.writeKeycodesInFile(essentials.logs, path::getInputsFilePath(essentials.prefPath, files::KeyboardInputsFile) );
}