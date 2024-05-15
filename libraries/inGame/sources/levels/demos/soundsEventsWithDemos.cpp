#include "levels/demos/soundsEventsWithDemos.h"
#include "levels/demosRecordingAndPlaying/data/dataPackage.h"
#include "soundSystem/soundsPlayer.h"
#include "levels/demosRecordingAndPlaying/data/determineGameStatus.h"

void demos::recordSoundEvent(demos::DataPackage *demoDataPackage, unsigned soundIndex, unsigned channel)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsRecording )
	{
		demoDataPackage->soundsPlaying.emplaceElement(demos::SoundPlaying{ demoDataPackage->soundsPlaying.getCurrentElapsedMicroSecondsTime(), soundIndex, channel} );
	}
}

void demos::playSoundIfAny(demos::DataPackage *demoDataPackage, const SoundPlayer& soundPlayer)
{
	if( demos::getGameStatus(demoDataPackage) == demos::GameIsDemo )
	{
		while( demoDataPackage->soundsPlaying.getCommandsNumber() > 0 && demoDataPackage->soundsPlaying.hasLastTimeElapsed() )
		{
			demos::playSoundChunk(soundPlayer, demoDataPackage->soundsPlaying.getLastElement() );
			demoDataPackage->soundsPlaying.pop_back();
		}
	}
}

void demos::playSoundChunk(const SoundPlayer& soundPlayer, const demos::SoundPlaying& soundData)
{
	soundPlayer.playSoundOnGroup(soundData.soundIndex, soundData.group);
}