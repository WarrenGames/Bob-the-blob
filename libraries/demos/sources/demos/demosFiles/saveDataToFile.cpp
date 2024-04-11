#include "demos/demosFiles/saveDataToFile.h"
#include "demos/data/dataPackage.h"
#include "exceptions/writeErrorExcept.h"
#include "demos/consts/dataRecordingConsts.h"
#include <fstream>

void saveDemo::openFile(const fs::path& demoFilePath, const demos::DataPackage& dataPackage)
{
	if( std::ofstream demoFile{ demoFilePath } )
	{
		demoFile << std::fixed << std::setprecision(6);
		saveDemo::saveData(demoFilePath, dataPackage, demoFile);
	}
	else{
		throw WriteError{"Couldn't open '" + demoFilePath.string() + "' demo file in order to save a demo."};
	}
}

void saveDemo::saveData(const fs::path& demoFilePath, const demos::DataPackage& dataPackage, std::ofstream& demoFile)
{
	saveDemo::saveGameAmbience(demoFilePath, dataPackage.gameAmbience, demoFile);
	saveDemo::saveMatrixSize(demoFilePath, dataPackage.mapsElements.gameMap, demoFile);
	saveDemo::savePlayedMatrix(demoFilePath, dataPackage.mapsElements.gameMap, demoFile);
	saveDemo::saveMapSubdivisionsNumber(demoFilePath, dataPackage.mapsElements.subDivisionFileData, demoFile);
	saveDemo::saveMapSubdivisionLink(demoFilePath, dataPackage.mapsElements.subDivisionFileData, demoFile);
	saveDemo::saveStartingPositions(demoFilePath, dataPackage.spritesPositions.protagonistsStartingPosition, demoFile, demosData::ProtagonistsStartPosition);
	saveDemo::saveStartingPositions(demoFilePath, dataPackage.spritesPositions.itemsStartingPosition, demoFile, demosData::ItemElementPos);
	saveDemo::saveBonusesMatrix(demoFilePath, dataPackage.mapsElements.bonusesMap, demoFile);
	saveDemo::saveActionDataStack(demoFilePath, dataPackage.playerInputsData.playerInputs, demoFile, demosData::PlayerInputs);
	saveDemo::saveSpecificActionDataIfAny(demoFilePath, dataPackage.playerInputsData.escapeCommand, demoFile, demosData::PlayerEscapeKeyInputs);
	saveDemo::saveSpecificActionDataIfAny(demoFilePath, dataPackage.playerInputsData.sdlQuitEvent, demoFile, demosData::PlayerSdlQuitEvent);
	saveDemo::saveSoundEvent(demoFilePath, dataPackage.soundsPlaying, demoFile, demosData::SoundsPlayingEvent);
	saveDemo::saveProtagonistsNumber(demoFilePath, dataPackage.spritesPositions.playersMoves.size(), demoFile, demosData::PlayerNumber);
	saveDemo::saveAllPlayersData(demoFilePath, dataPackage.spritesPositions.playersMoves, demoFile, demosData::PlayerMoves);
	saveDemo::saveProtagonistsNumber(demoFilePath, dataPackage.spritesPositions.enemyBobsMoves.size(), demoFile, demosData::EnemyBobsNumber);
	saveDemo::saveIdRelatedMoves(demoFilePath, dataPackage.spritesPositions.enemyBobsMoves, demoFile, demosData::EnemyBobsMoves);
	saveDemo::saveGameEvents(demoFilePath, dataPackage.spritesPositions.enemyBobsRespawn, demoFile, demosData::EnemyBobsRespawn);
	saveDemo::saveGameEvents(demoFilePath, dataPackage.gameEvents, demoFile, demosData::GameEvents);
	saveDemo::saveItemsData(demoFilePath, dataPackage.greenOrbRelatedItemsData.greenOrb, demoFile, demosData::GreenOrb);
	saveDemo::saveGameEvents(demoFilePath, dataPackage.greenOrbRelatedItemsData.greenOrbsAndPlayer, demoFile, demosData::GreenOrbPlayerPower);
	saveDemo::saveGameEvents(demoFilePath, dataPackage.greenOrbRelatedItemsData.cactiLife, demoFile, demosData::CactusEvent);
}

void saveDemo::saveGameAmbience(const fs::path& demoFilePath, unsigned gameAmbience, std::ofstream& demoFile)
{
	if( ! ( demoFile << demosData::GameAmbience << " " << gameAmbience << '\n' ) )
	{
		saveDemo::throwWriteError(demoFilePath, demosData::GameAmbience);
	}
}

void saveDemo::saveStartingPositions(const fs::path& demoFilePath, const std::vector< demos::StartingPosition >& startingPositions, std::ofstream& demoFile, int fileIndex)
{
	if( startingPositions.empty() == false )
	{
		for( auto const &data : startingPositions )
		{
			if( ! ( demoFile << fileIndex << " " << data.type << " " << data.subType << " " << data.position.width << " " << data.position.height << " " << data.id << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::saveProtagonistsNumber(const fs::path& demoFilePath, std::size_t size, std::ofstream& demoFile, int fileIndex)
{
	if( ! ( demoFile << fileIndex << " " << size << '\n' ) )
	{
		saveDemo::throwWriteError(demoFilePath, fileIndex);
	}
}

void saveDemo::saveIdRelatedMoves(const fs::path& demoFilePath, const std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, std::ofstream& demoFile, int fileIndex)
{
	if( protagonistsMoves.empty() == false )
	{
		for( auto const &stack : protagonistsMoves )
		{
			saveDemo::saveMoveAndPositionData(demoFilePath, stack, demoFile, fileIndex);
		}
	}
}

void saveDemo::saveMoveAndPositionData(const fs::path& demoFilePath, const demos::Stack< demos::MoveAndPosition >& stack, std::ofstream& demoFile, int fileIndex)
{
	if( stack.getCommandsNumber() > 0 )
	{
		for( std::vector< demos::MoveAndPosition >::const_reverse_iterator it = stack.crbegin() ; it != stack.crend() ; ++it )
		{
			if( ! ( demoFile << fileIndex << " " << static_cast<long int>(it->delay.count()) << " " << it->protagonistEnum << " " << it->currentPosition.width
					<< " " << it->currentPosition.height << " " << it->nextAction << " " << it->demoId << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::saveAllPlayersData(const fs::path& demoFilePath, const std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::ofstream& demoFile, int fileIndex)
{
	if( stacks.empty() == false )
	{
		for( auto const &stack : stacks )
		{
			saveDemo::savePlayerMoveData(demoFilePath, stack, demoFile, fileIndex);
		}
	}
}

void saveDemo::savePlayerMoveData(const fs::path& demoFilePath, const demos::Stack< demos::PlayerMove >& stack, std::ofstream& demoFile, int fileIndex)
{
	if( stack.getCommandsNumber() > 0 )
	{
		for( std::vector< demos::PlayerMove >::const_reverse_iterator it = stack.crbegin() ; it != stack.crend() ; ++it )
		{
			if( ! ( demoFile << fileIndex << " " << static_cast<long int>(it->delay.count()) << " " << it->playerId << " " << it->position.width
					<< " " << it->position.height << " " << it->action << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::saveMatrixSize(const fs::path& demoFilePath, const MatrixTemp2D< MapElement >& matrix, std::ofstream& demoFile)
{
	if( ! ( demoFile << demosData::MatrixSizeData << " " << matrix.height() << " " << matrix.width() << '\n' ) )
	{
		saveDemo::throwWriteError(demoFilePath, demosData::MatrixSizeData);
	}
}

void saveDemo::savePlayedMatrix(const fs::path& demoFilePath, const MatrixTemp2D< MapElement >& matrix, std::ofstream& demoFile)
{
	for( std::size_t height{0} ; height < matrix.height() ; ++height )
	{
		for( std::size_t width{0} ; width < matrix.width() ; ++width )
		{
			if( ! ( demoFile << demosData::MatrixElementData << " " << height << " " << width << " " << matrix(width, height).mapIndex << " " 
				<< matrix(width, height).indexProperty << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, demosData::MatrixElementData);
			}
		}
	}
}

void saveDemo::saveBonusesMatrix(const fs::path& demoFilePath, const MatrixTemp2D< BonusElement >& matrix, std::ofstream& demoFile)
{
	for( std::size_t height{0} ; height < matrix.height() ; ++height )
	{
		for( std::size_t width{0} ; width < matrix.width() ; ++width )
		{
			if( matrix(width, height).isPresent )
			{
				if( ! ( demoFile << demosData::BonusesMatrixElement << " " << height << " " << width << " " << matrix(width, height).bonusIndex << " " 
					<< matrix(width, height).bonusProperty << '\n' ) )
				{
					saveDemo::throwWriteError(demoFilePath, demosData::BonusesMatrixElement);
				}
			}
		}
	}
}

void saveDemo::saveMapSubdivisionsNumber(const fs::path& demoFilePath, const SubDivisionFileData& subDivisionFileData, std::ofstream& demoFile)
{
	if( ! ( demoFile << demosData::MatrixSubdivisionsNumber << " " << subDivisionFileData.zonesNumber.width << " " << subDivisionFileData.zonesNumber.height << '\n' ) )
	{
		saveDemo::throwWriteError(demoFilePath, demosData::MatrixSubdivisionsNumber);
	}
}

void saveDemo::saveMapSubdivisionLink(const fs::path& demoFilePath, const SubDivisionFileData& subDivisionFileData, std::ofstream& demoFile)
{
	for( auto const &pair : subDivisionFileData.subdivisionLinks )
	{
		if( ! ( demoFile << demosData::MatrixSubdivisionLink << " " << pair.first.width << " " << pair.first.height << " " << pair.second.width << " " << pair.second.height << '\n' ) )
		{
			saveDemo::throwWriteError(demoFilePath, demosData::MatrixSubdivisionLink);
		}
	}
}

void saveDemo::saveActionDataStack(const fs::path& demoFilePath, const demos::Stack< demos::ActionData >& actionDataStack, std::ofstream& demoFile, int fileIndex)
{
	if( actionDataStack.getCommandsNumber() > 0 )
	{
		for( std::vector<demos::ActionData>::const_reverse_iterator it = actionDataStack.crbegin() ; it != actionDataStack.crend() ; ++it )
		{
			saveDemo::saveActionData(demoFilePath, *it, demoFile, fileIndex);
		}
	}
}

void saveDemo::saveActionData(const fs::path& demoFilePath, const demos::ActionData& actionData, std::ofstream& demoFile, int fileIndex)
{
	if( ! ( demoFile << fileIndex << " " << static_cast<long int>(actionData.delay.count()) << " " << actionData.funcEnum << " " << actionData.actionState << '\n' ) )
	{
		saveDemo::throwWriteError(demoFilePath, fileIndex);
	}
}

void saveDemo::saveSoundEvent(const fs::path& demoFilePath, const demos::Stack< demos::SoundPlaying >& soundsStack, std::ofstream& demoFile, int fileIndex)
{
	if( soundsStack.getCommandsNumber() > 0 )
	{
		for( std::vector< demos::SoundPlaying >::const_reverse_iterator it = soundsStack.crbegin() ; it != soundsStack.crend() ; ++it )
		{
			if( ! ( demoFile << fileIndex << " " << static_cast<long int>(it->delay.count()) << " " << it->soundIndex << " " << it->group << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::saveSpecificActionDataIfAny(const fs::path& demoFilePath, const demos::ActionData& actionData, std::ofstream& demoFile, int fileIndex)
{
	if( actionData.actionState )
	{
		saveDemo::saveActionData(demoFilePath, actionData, demoFile, fileIndex);
	}
}

void saveDemo::saveGameEvents(const fs::path& demoFilePath, const demos::Stack< demos::GameEvent >& gameEventsStack, std::ofstream& demoFile, int fileIndex)
{
	if( gameEventsStack.getCommandsNumber() > 0 )
	{
		for( std::vector< demos::GameEvent >::const_reverse_iterator it = gameEventsStack.crbegin() ; it != gameEventsStack.crend() ; ++it )
		{
			if( ! ( demoFile << fileIndex << " " << static_cast<long int>(it->delay.count()) << " " << it->category << " " << it->subType << " " << it->id << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::saveItemsData(const fs::path& demoFilePath, const demos::Stack< demos::ItemData >& itemDataStack, std::ofstream& demoFile, int fileIndex)
{
	if( itemDataStack.getCommandsNumber() > 0 )
	{
		for( std::vector< demos::ItemData >::const_reverse_iterator it = itemDataStack.crbegin() ; it != itemDataStack.crend() ; ++it )
		{
			if( ! ( demoFile << fileIndex << " " << static_cast<long int>(it->delay.count()) << " " << it->position.width << " " << it->position.height << " " 
				<< it->event << " " << it->itemId << '\n' ) )
			{
				saveDemo::throwWriteError(demoFilePath, fileIndex);
			}
		}
	}
}

void saveDemo::throwWriteError(const fs::path& demoFilePath, int fileIndex)
{
	throw WriteError{"Saving data with index '" + std::to_string(fileIndex) + "' failed in '" + demoFilePath.string() + "' demo file.\n"};
}