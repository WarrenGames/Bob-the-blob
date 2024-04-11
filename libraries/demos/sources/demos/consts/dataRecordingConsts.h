#ifndef BOB_THE_BLOB_DEMOS_LIB_DATA_RECORDING_CONSTS_H
#define BOB_THE_BLOB_DEMOS_LIB_DATA_RECORDING_CONSTS_H

namespace demosData{
	
	constexpr int GameAmbience = -1;
	constexpr int MatrixSizeData = -10;
	constexpr int MatrixElementData = -11;
	constexpr int MatrixSubdivisionsNumber = -15;
	constexpr int MatrixSubdivisionLink = -16;
	constexpr int ProtagonistsStartPosition = -20;
	constexpr int ItemElementPos = -21;
	constexpr int BonusesMatrixElement = -22;
	constexpr int PlayerInputs = -30;
	constexpr int PlayerEscapeKeyInputs = -31;
	constexpr int PlayerSdlQuitEvent = -32;
	constexpr int SoundsPlayingEvent = -33;
	constexpr int PlayerNumber = -40;
	constexpr int PlayerMoves = -41;
	constexpr int EnemyBobsNumber = -50;
	constexpr int EnemyBobsMoves = -51;
	constexpr int EnemyBobsRespawn = -52;
	constexpr int GameEvents = -60;
	constexpr int GreenOrb = -70;
	constexpr int GreenOrbPlayerPower = -71;
	constexpr int CactusEvent = -72;
	
	
	//Follow 'ProtagonistStartPos' value
	//demos::StartingPosition.type enum:
	enum : unsigned{
		StartPosPlayer,
		StartPosBobby,
		StartPosMax
	};
	
	enum : unsigned{
		PlayerSubType1,
		PlayerSubTypeMax
	};
	
	//Follow 'ItemElementPos' value
	//demos::StartingPosition.type enum:
	enum : unsigned{
		ItemCactiStartPos,
		ItemMax
	};
}

#endif //BOB_THE_BLOB_DEMOS_LIB_DATA_RECORDING_CONSTS_H