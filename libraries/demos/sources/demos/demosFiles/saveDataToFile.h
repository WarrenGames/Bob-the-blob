#ifndef BOB_THE_BLOB_DEMOS_LIB_SAVE_DEMOS_TO_FILE_H
#define BOB_THE_BLOB_DEMOS_LIB_SAVE_DEMOS_TO_FILE_H

#include "fileSystem/fileSystem.h"
#include <iosfwd>
#include <vector>

namespace demos{ 
	struct DataPackage; 
	struct StartingPosition; 
	struct MoveAndPosition;
	struct PlayerMove;
	struct ActionData;
	struct SoundPlaying;
	struct GameEvent;
	struct ItemData;
	template< typename T >class Stack;
}

template< typename T > class MatrixTemp2D;
struct MapElement;
struct BonusElement;
struct SubDivisionFileData;

namespace saveDemo{
	void openFile(const fs::path& demoFilePath, const demos::DataPackage& dataPackage);
	
	void saveData(const fs::path& demoFilePath, const demos::DataPackage& dataPackage, std::ofstream& demoFile);
	
	void saveGameAmbience(const fs::path& demoFilePath, unsigned gameAmbience, std::ofstream& demoFile);
	
	void saveSkillLevel(const fs::path& demoFilePath, unsigned skillLevel, std::ofstream& demoFile);
	
	void saveStartingPositions(const fs::path& demoFilePath, const std::vector< demos::StartingPosition >& startingPositions, std::ofstream& demoFile, int fileIndex);
	
	void saveProtagonistsNumber(const fs::path& demoFilePath, std::size_t size, std::ofstream& demoFile, int fileIndex);
	
	void saveIdRelatedMoves(const fs::path& demoFilePath, const std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, std::ofstream& demoFile, int fileIndex);
	
	void saveMoveAndPositionData(const fs::path& demoFilePath, const demos::Stack< demos::MoveAndPosition >& stack, std::ofstream& demoFile, int fileIndex);
	
	void saveAllPlayersData(const fs::path& demoFilePath, const std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::ofstream& demoFile, int fileIndex);
	
	void savePlayerMoveData(const fs::path& demoFilePath, const demos::Stack< demos::PlayerMove >& stack, std::ofstream& demoFile, int fileIndex);
	
	void savePlayedMatrix(const fs::path& demoFilePath, const MatrixTemp2D< MapElement >& matrix, std::ofstream& demoFile);
	
	void saveBonusesMatrix(const fs::path& demoFilePath, const MatrixTemp2D< BonusElement >& matrix, std::ofstream& demoFile);
	
	void saveMatrixSize(const fs::path& demoFilePath, const MatrixTemp2D< MapElement >& matrix, std::ofstream& demoFile);
	
	void saveMapSubdivisionsNumber(const fs::path& demoFilePath, const SubDivisionFileData& subDivisionFileData, std::ofstream& demoFile);
	
	void saveMapSubdivisionLink(const fs::path& demoFilePath, const SubDivisionFileData& subDivisionFileData, std::ofstream& demoFile);
	
	void saveActionDataStack(const fs::path& demoFilePath, const demos::Stack< demos::ActionData >& actionDataStack, std::ofstream& demoFile, int fileIndex);
	
	void saveActionData(const fs::path& demoFilePath, const demos::ActionData& actionData, std::ofstream& demoFile, int fileIndex);
	
	void saveSoundEvent(const fs::path& demoFilePath, const demos::Stack< demos::SoundPlaying >& soundsStack, std::ofstream& demoFile, int fileIndex);
	
	void saveSpecificActionDataIfAny(const fs::path& demoFilePath, const demos::ActionData& actionData, std::ofstream& demoFile, int fileIndex);
	
	void saveGameEvents(const fs::path& demoFilePath, const demos::Stack< demos::GameEvent >& gameEventsStack, std::ofstream& demoFile, int fileIndex);
	
	void saveItemsData(const fs::path& demoFilePath, const demos::Stack< demos::ItemData >& itemDataStack, std::ofstream& demoFile, int fileIndex);
	
	void throwWriteError(const fs::path& demoFilePath, int fileIndex);
}

#endif //BOB_THE_BLOB_DEMOS_LIB_SAVE_DEMOS_TO_FILE_H