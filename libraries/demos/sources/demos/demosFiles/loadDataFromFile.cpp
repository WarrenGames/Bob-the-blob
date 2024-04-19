#include "demos/demosFiles/loadDataFromFile.h"
#include "demos/data/dataPackage.h"
#include "exceptions/readErrorExcept.h"
#include "demos/consts/dataRecordingConsts.h"
#include "demos/consts/gameEventsConsts.h"
#include <fstream>

void loadDemo::openFile(const fs::path& demoFilePath, demos::DataPackage& dataPackage)
{
	if( std::ifstream demoFile{ demoFilePath } )
	{
		loadDemo::loadData(demoFilePath, demoFile, dataPackage);
	}
	else{
		throw ReadError{ "Couldn't open '" + demoFilePath.string() + "' demo file in order to load a demo." };
	}
}

void loadDemo::loadData(const fs::path& demoFilePath, std::ifstream& demoFile, demos::DataPackage& dataPackage)
{
	std::size_t fileLineNumber{1};
	std::string fileLine;
	int lineIndex{0};
	while( std::getline( demoFile, fileLine ) )
	{
		std::istringstream lineStream{ fileLine };
		if( lineStream >> lineIndex )
		{
			loadDemo::actAccordingToIndex(demoFilePath, dataPackage, lineStream, fileLineNumber, lineIndex);
		}
		else{
			loadDemo::throwReadError(demoFilePath, fileLineNumber);
		}
		fileLineNumber++;
	}
}

void loadDemo::actAccordingToIndex(const fs::path& demoFilePath, demos::DataPackage& dataPackage, std::istringstream& lineStream, std::size_t fileLineNumber, int lineIndex)
{
	switch( lineIndex )
	{
		case demosData::GameAmbience:
			loadDemo::loadGameAmbience(demoFilePath, lineStream, dataPackage.gameAmbience, fileLineNumber);
			break;
		case demosData::MatrixSizeData:
			loadDemo::loadMatrixSizeData(demoFilePath, lineStream, dataPackage, fileLineNumber);
			break;
		case demosData::MatrixElementData:
			loadDemo::loadMatrixElement(demoFilePath, lineStream, dataPackage.mapsElements.gameMap, fileLineNumber);
			break;
		case demosData::MatrixSubdivisionsNumber:
			loadDemo::loadMapSubdivisionNumber(demoFilePath, lineStream, dataPackage.mapsElements.subDivisionFileData, fileLineNumber);
			break;
		case demosData::MatrixSubdivisionLink:
			loadDemo::loadMapSubdivisionLink(demoFilePath, lineStream, dataPackage.mapsElements.subDivisionFileData, fileLineNumber);
			break;
		case demosData::ProtagonistsStartPosition:
			loadDemo::loadStartingPositions(demoFilePath, lineStream, dataPackage.spritesPositions.protagonistsStartingPosition, fileLineNumber);
			break;
		case demosData::ItemElementPos:
			loadDemo::loadStartingPositions(demoFilePath, lineStream, dataPackage.spritesPositions.itemsStartingPosition, fileLineNumber);
			break;
		case demosData::BonusesMatrixElement:
			loadDemo::loadBonusesMatrixElement(demoFilePath, lineStream, dataPackage.mapsElements.bonusesMap, fileLineNumber);
			break;
		case demosData::PlayerInputs:
			loadDemo::loadPlayerInputs(demoFilePath, lineStream, dataPackage.playerInputsData.playerInputs, fileLineNumber);
			break;
		case demosData::PlayerEscapeKeyInputs:
			loadDemo::loadActionData(demoFilePath, lineStream, dataPackage.playerInputsData.escapeCommand, fileLineNumber);
			break;
		case demosData::PlayerSdlQuitEvent:
			loadDemo::loadActionData(demoFilePath, lineStream, dataPackage.playerInputsData.sdlQuitEvent, fileLineNumber);
			break;
		case demosData::SoundsPlayingEvent:
			loadDemo::loadSoundEvent(demoFilePath, lineStream, dataPackage.soundsPlaying, fileLineNumber);
			break;
		case demosData::PlayerNumber:
			loadDemo::loadPlayerNumber(demoFilePath, lineStream, dataPackage.spritesPositions.playersMoves, fileLineNumber);
			break;
		case demosData::PlayerMoves:
			loadDemo::loadPlayerMoveData(demoFilePath, lineStream, dataPackage.spritesPositions.playersMoves, fileLineNumber);
			break;
		case demosData::EnemyBobsNumber:
			loadDemo::loadProtagonistsNumber(demoFilePath, lineStream, dataPackage.spritesPositions.enemyBobsMoves, fileLineNumber);
			break;
		case demosData::EnemyBobsMoves:
			loadDemo::loadProtagonistsMoves(demoFilePath, lineStream, dataPackage.spritesPositions.enemyBobsMoves, fileLineNumber);
			break;
		case demosData::EnemyBobsRespawn:
			loadDemo::loadGameEvents(demoFilePath, lineStream, dataPackage.spritesPositions.enemyBobsRespawn, fileLineNumber);
			break;
		case demosData::GameEvents:
			loadDemo::loadGameEvents(demoFilePath, lineStream, dataPackage.gameEvents, fileLineNumber);
			break;
		case demosData::LevelWonEvents:
			loadDemo::loadGameEvents(demoFilePath, lineStream, dataPackage.levelWonEvents, fileLineNumber);
			break;
		case demosData::GreenOrb:
			loadDemo::loadItemData(demoFilePath, lineStream, dataPackage.greenOrbRelatedItemsData.greenOrb, fileLineNumber);
			break;
		case demosData::GreenOrbPlayerPower:
			loadDemo::loadGameEvents(demoFilePath, lineStream, dataPackage.greenOrbRelatedItemsData.greenOrbsAndPlayer, fileLineNumber);
			break;
		case demosData::CactusEvent:
			loadDemo::loadGameEvents(demoFilePath, lineStream, dataPackage.greenOrbRelatedItemsData.cactiLife, fileLineNumber);
			break;
	}
}

void loadDemo::loadGameAmbience(const fs::path& demoFilePath, std::istringstream& lineStream, unsigned& gameAmbience, std::size_t fileLineNumber)
{
	if( ! ( lineStream >> gameAmbience ) )
	{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadMatrixSizeData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::DataPackage& dataPackage, std::size_t fileLineNumber)
{
	Coord2D matrixSize{ 0, 0 };
	if( lineStream >> matrixSize.height >> matrixSize.width )
	{
		dataPackage.mapsElements.gameMap.resize( matrixSize );
		dataPackage.mapsElements.bonusesMap.resize( matrixSize );
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadMatrixElement(const fs::path& demoFilePath, std::istringstream& lineStream, MatrixTemp2D< MapElement >& matrix, std::size_t fileLineNumber)
{
	Coord2D coords;
	MapElement mapElement;
	if( lineStream >> coords.height >> coords.width >> mapElement.mapIndex >> mapElement.indexProperty )
	{
		if( matrix.isInsideBoundaries(coords) )
		{
			matrix(coords) = mapElement;
		}
		else{
			throw ReadError{"Bad coordinates values at line number " + std::to_string( fileLineNumber ) + " in '" + demoFilePath.string() + "' demoFile."}; 
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadBonusesMatrixElement(const fs::path& demoFilePath, std::istringstream& lineStream, MatrixTemp2D< BonusElement >& bonusesMap, std::size_t fileLineNumber)
{
	Coord2D coords;
	BonusElement bonusElement;
	bonusElement.isPresent = true;
	if( lineStream >> coords.height >> coords.width >> bonusElement.bonusIndex >> bonusElement.bonusProperty )
	{
		if( bonusesMap.isInsideBoundaries(coords) )
		{
			bonusesMap(coords) = bonusElement;
		}
		else{
			throw ReadError{"Bad coordinates values at line number " + std::to_string( fileLineNumber ) + " in '" + demoFilePath.string() + "' demoFile."}; 
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadPlayerInputs(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::ActionData >& playerInputs, std::size_t fileLineNumber)
{
	demos::ActionData actionData;
	long int delay{0};
	if( lineStream >> delay >> actionData.funcEnum >> actionData.actionState )
	{
		actionData.delay = std::chrono::microseconds{delay};
		playerInputs.emplaceElement(actionData);
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadActionData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::ActionData& actionData, std::size_t fileLineNumber)
{
	long int delay{0};
	if( lineStream >> delay >> actionData.funcEnum >> actionData.actionState )
	{
		actionData.delay = std::chrono::microseconds{delay};
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadSoundEvent(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::SoundPlaying >& soundsStack, std::size_t fileLineNumber)
{
	long int delay{0};
	demos::SoundPlaying soundPlaying;
	if( lineStream >> delay >> soundPlaying.soundIndex >> soundPlaying.group )
	{
		soundPlaying.delay = std::chrono::microseconds{ delay };
		soundsStack.emplaceElement(soundPlaying);
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadStartingPositions(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::StartingPosition >& startingPositions, std::size_t fileLineNumber)
{
	demos::StartingPosition fileData;
	if( lineStream >> fileData.type >> fileData.subType >> fileData.position.width >> fileData.position.height >> fileData.id )
	{
		startingPositions.emplace_back(fileData);
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadProtagonistsNumber(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, 
										std::size_t fileLineNumber)
{
	std::size_t size{0};
	if( lineStream >> size )
	{
		protagonistsMoves.clear();
		for( std::size_t i{0} ; i < size ; ++i )
		{
			protagonistsMoves.emplace_back(demos::Stack< demos::MoveAndPosition >{demos::GameIsDemo} );
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadProtagonistsMoves(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, std::size_t fileLineNumber)
{
	demos::MoveAndPosition fileData;
	long int delay{0};
	if( lineStream >> delay >> fileData.protagonistEnum >> fileData.currentPosition.width >> fileData.currentPosition.height >> fileData.nextAction >> fileData.demoId )
	{
		assert( fileData.demoId < protagonistsMoves.size() );
		fileData.delay = std::chrono::microseconds{ delay };
		protagonistsMoves[fileData.demoId].emplaceElement(fileData);
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadMapSubdivisionNumber(const fs::path& demoFilePath, std::istringstream& lineStream, SubDivisionFileData& subDivisionFileData, std::size_t fileLineNumber)
{
	Coord2D subDivisionsNumber;
	if( lineStream >> subDivisionsNumber.width >> subDivisionsNumber.height )
	{
		subDivisionFileData.zonesNumber = subDivisionsNumber;
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadMapSubdivisionLink(const fs::path& demoFilePath, std::istringstream& lineStream, SubDivisionFileData& subDivisionFileData, std::size_t fileLineNumber)
{
	std::pair< Coord2D, Coord2D > link;
	if( lineStream >> link.first.width >> link.first.height >> link.second.width >> link.second.height )
	{
		subDivisionFileData.subdivisionLinks.emplace_back(link);
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadGameEvents(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::GameEvent >& gameEventStack, std::size_t fileLineNumber)
{
	demos::GameEvent gameEvent;
	long int delay{0};
	if( lineStream >> delay >> gameEvent.category >> gameEvent.subType >> gameEvent.id )
	{
		if( gameEvent.category < demos::eventCat::Max )
		{
			gameEvent.delay = std::chrono::microseconds{ delay };
			gameEventStack.emplaceElement(gameEvent);
		}
		else{
			loadDemo::throwReadError(demoFilePath, fileLineNumber);
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadPlayerNumber(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::size_t fileLineNumber)
{
	std::size_t playersNumber{0};
	if( lineStream >> playersNumber )
	{
		stacks.clear();
		for( std::size_t i{0} ; i < playersNumber ; ++i )
		{
			stacks.emplace_back( demos::Stack< demos::PlayerMove >{ demos::GameIsDemo } );
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadPlayerMoveData(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::size_t fileLineNumber)
{
	long int delay{0};
	demos::PlayerMove data;
	if( lineStream >> delay >> data.playerId >> data.position.width >> data.position.height >> data.action )
	{
		if( data.playerId < stacks.size() )
		{
			data.delay = std::chrono::microseconds{ delay };
			stacks[data.playerId].emplaceElement( data );
		}
		else{
			loadDemo::throwReadError(demoFilePath, fileLineNumber);
		}
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::loadItemData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::ItemData >& stack, std::size_t fileLineNumber)
{
	long int delay{0};
	demos::ItemData itemData;
	if( lineStream >> delay >> itemData.position.width >> itemData.position.height >> itemData.event >> itemData.itemId )
	{
		itemData.delay = std::chrono::microseconds{ delay };
		stack.emplaceElement( itemData );
	}
	else{
		loadDemo::throwReadError(demoFilePath, fileLineNumber);
	}
}

void loadDemo::throwReadError(const fs::path& demoFilePath, std::size_t fileLineNumber)
{
	throw ReadError{"Couldn't read demo data in '" + demoFilePath.string() + "' file at line number " + std::to_string( fileLineNumber ) + " ."};
}