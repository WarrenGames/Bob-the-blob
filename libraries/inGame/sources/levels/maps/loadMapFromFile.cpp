#include "levels/maps/loadMapFromFile.h"
#include "levels/maps/gameMap.h"
#include "exceptions/readErrorExcept.h"
#include "levels/maps/mapsConsts.h"
#include "logging/logsStruct.h"

void tryMapFileReading(AppLogFiles& logs, GameMap& gameMap, const fs::path& mapFilePath, bool& isLoadingPerfect)
{
	try{
		loadMapFromFile( gameMap, mapFilePath );
	}
	catch( const ReadError& readError )
	{
		logs.error << "Error at loading '" << mapFilePath.string() << "' map file : " << readError.what();
		isLoadingPerfect = false;
	}
	catch( const std::exception& e )
	{
		logs.error << "Error: unknown exception : " << e.what() << "\n";
		isLoadingPerfect = false;
	}
}

void loadMapFromFile(GameMap& gameMap, const fs::path& dataFilePath)
{
	if( std::ifstream mapFile{ dataFilePath } )
	{
		std::size_t fileLineNumber{1};
		readFirstFileLineForMatrixSize(gameMap, dataFilePath, mapFile, fileLineNumber);
		startLoadingMapData(gameMap, dataFilePath, mapFile, fileLineNumber);
	}
	else{
		throw ReadError{"Opening '" + dataFilePath.string() + "' data file in order to load map impossible."};
	}
}

void readFirstFileLineForMatrixSize(GameMap& gameMap, const fs::path& dataFilePath, std::ifstream& mapFile, std::size_t& fileLineNumber)
{
	std::string fileLine;
	if( std::getline( mapFile, fileLine ) )
	{
		std::istringstream lineStream{ fileLine };
		Coord2D matrixSize;
		int matrixSizeIndex{0};
		if( lineStream >> matrixSizeIndex >> matrixSize.height >> matrixSize.width )
		{
			if( matrixSizeIndex == map::MatrixSizeIndex )
			{
				gameMap.matrix.resize(matrixSize);
			}
			else{
				throw ReadError{"Expected " + std::to_string( map::MatrixSizeIndex ) + " as first index value for matrix size but value is: " + std::to_string( matrixSizeIndex ) + " .\n"};
			}
		}
		else{
			throw ReadError{"Parsing first line of '" + dataFilePath.string() + "' matrix file in order to get matrix size failed.\n"}; 
		}
		fileLineNumber++;
	}
	else{
		throw ReadError{"Reading first line of '" + dataFilePath.string() + "' matrix file in order to get matrix size failed.\n"};
	}
}

void startLoadingMapData(GameMap& gameMap, const fs::path& dataFilePath, std::ifstream& mapFile, std::size_t& fileLineNumber)
{
	std::string fileLine;
	while( std::getline( mapFile, fileLine ) )
	{
		std::istringstream lineStream{ fileLine };
		loadDataFromLineStream(gameMap, dataFilePath, lineStream, fileLineNumber);
		fileLineNumber++;
	}
}

void loadDataFromLineStream(GameMap& gameMap, const fs::path& dataFilePath, std::istringstream& lineStream, std::size_t fileLineNumber)
{
	Coord2D coords;
	MapElement mapElement;
	
	if( lineStream >> coords.height >> coords.width >> mapElement.mapIndex >> mapElement.indexProperty )
	{
		if( gameMap.matrix.isInsideBoundaries(coords) )
		{
			gameMap.matrix(coords) = mapElement;
		}
		else{
			throw ReadError{"There was an error with mapElement coordinates in '" + dataFilePath.string() + "' data file at line number " + std::to_string(fileLineNumber) + " ."};
		}
	}
	else{
		throw ReadError{"There was an error reading '" + dataFilePath.string() + "' data file at line number " + std::to_string(fileLineNumber) + " ."};
	}
}