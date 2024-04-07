#ifndef BOB_THE_BLOB_DEMOS_LIB_LOAD_DEMOS_FROM_FILE_H
#define BOB_THE_BLOB_DEMOS_LIB_LOAD_DEMOS_FROM_FILE_H

#include "fileSystem/fileSystem.h"
#include <iosfwd>
#include <sstream>
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

namespace loadDemo{
	void openFile(const fs::path& demoFilePath, demos::DataPackage& dataPackage);
	
	void loadData(const fs::path& demoFilePath, std::ifstream& demoFile, demos::DataPackage& dataPackage);
	
	void actAccordingToIndex(const fs::path& demoFilePath, demos::DataPackage& dataPackage, std::istringstream& lineStream, std::size_t fileLineNumber, int lineIndex);
	
	void loadGameAmbience(const fs::path& demoFilePath, std::istringstream& lineStream, unsigned& gameAmbience, std::size_t fileLineNumber);
	
	void loadMatrixSizeData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::DataPackage& dataPackage, std::size_t fileLineNumber);
	
	void loadMatrixElement(const fs::path& demoFilePath, std::istringstream& lineStream, MatrixTemp2D< MapElement >& gameMap, std::size_t fileLineNumber);
	
	void loadBonusesMatrixElement(const fs::path& demoFilePath, std::istringstream& lineStream, MatrixTemp2D< BonusElement >& bonusesMap, std::size_t fileLineNumber);
	
	void loadPlayerInputs(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::ActionData >& playerInputs, std::size_t fileLineNumber);
	
	void loadActionData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::ActionData& actionData, std::size_t fileLineNumber);
	
	void loadSoundEvent(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::SoundPlaying >& soundsStack, std::size_t fileLineNumber);
	
	void loadStartingPositions(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::StartingPosition >& startingPositions, std::size_t fileLineNumber);
	
	void loadProtagonistsNumber(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, std::size_t fileLineNumber);
	
	void loadProtagonistsMoves(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::MoveAndPosition > >& protagonistsMoves, std::size_t fileLineNumber);
	
	void loadMapSubdivisionNumber(const fs::path& demoFilePath, std::istringstream& lineStream, SubDivisionFileData& subDivisionFileData, std::size_t fileLineNumber);
	
	void loadMapSubdivisionLink(const fs::path& demoFilePath, std::istringstream& lineStream, SubDivisionFileData& subDivisionFileData, std::size_t fileLineNumber);
	
	void loadGameEvents(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::GameEvent >& gameEventStack, std::size_t fileLineNumber);
	
	void loadPlayerNumber(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::size_t fileLineNumber);
	
	void loadPlayerMoveData(const fs::path& demoFilePath, std::istringstream& lineStream, std::vector< demos::Stack< demos::PlayerMove > >& stacks, std::size_t fileLineNumber);
	
	void loadItemData(const fs::path& demoFilePath, std::istringstream& lineStream, demos::Stack< demos::ItemData >& stack, std::size_t fileLineNumber);
	
	void throwReadError(const fs::path& demoFilePath, std::size_t fileLineNumber);
}

#endif //BOB_THE_BLOB_DEMOS_LIB_LOAD_DEMOS_FROM_FILE_H