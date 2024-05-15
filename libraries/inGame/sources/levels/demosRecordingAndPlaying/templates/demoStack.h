#ifndef DEMOS_LIB_DATA_STACK_TEMP_H
#define DEMOS_LIB_DATA_STACK_TEMP_H

#include "levels/demosRecordingAndPlaying/consts/demosConsts.h"
#include "time/accurateTime.h"
#include "logging/logsStruct.h"
#include <vector>
#include <string>
#include <cassert>

namespace demos{
	
template<typename T>
class Stack
{
using ConstReverseStackIt = typename std::vector< T >::const_reverse_iterator;
using StackIt = typename std::vector< T >::iterator;
	
private:
	std::vector< T > data;
	AccurateTimeDelay delay;
	bool isLoadingPerfect;
	bool hasEnoughSize;

public:
	explicit Stack(AppLogFiles& logs, std::size_t dataSize, unsigned demoType, const std::string& templateElement):
		isLoadingPerfect{true},
		hasEnoughSize{true}
	{
		if( demos::GameIsRecording == demoType )
		{
			data.reserve(dataSize);
			if( data.capacity() != dataSize )
			{
				logs.error << "Error: couldn't allocate '" << dataSize << "' element(s) for a demo stack with this element: " << templateElement << ".\n";
				isLoadingPerfect = false;
			}
		}
	}
	explicit Stack(unsigned demoType):
		isLoadingPerfect{true},
		hasEnoughSize{true}
	{
		assert( demoType == demos::GameIsDemo );
	}
	
	~Stack() = default;
	Stack( const Stack& ) = delete;
	Stack& operator= ( const Stack& ) = delete;
	Stack( Stack&& ) = default;
	Stack& operator= ( Stack&& ) = default;
	
	void transferDelayTimePointValue(const AccurateTimeDelay& newDelay)
	{
		delay = newDelay;
	}
	
	operator bool() const
	{
		return isLoadingPerfect;
	}
	
	const T& getLastElement() const
	{
		assert( data.empty() == false );
		return data.back();
	}
	
	void pop_back()
	{
		assert( data.empty() == false );
		data.pop_back();
	}
	
	std::size_t getCommandsNumber() const
	{
		return data.size();
	}
	
	std::size_t getCapacity() const
	{
		return data.capacity();
	}
	
	void emplaceElement(const T& element)
	{
		data.emplace_back(element);
	}
	
	ConstReverseStackIt crbegin() const
	{
		return data.crbegin();
	}
	
	ConstReverseStackIt crend() const
	{
		return data.crend();
	}
	
	StackIt begin()
	{
		return data.begin();
	}
	
	StackIt end()
	{
		return data.end();
	}
	
	void setSizeNotSufficientFlag()
	{
		hasEnoughSize = false;
	}
	
	bool getSizeFlag() const
	{
		return hasEnoughSize;
	}
	
	void setPrecedentTimePoint()
	{
		delay.joinTimePoints();
	}

	bool hasLastTimeElapsed() const
	{
		assert( data.empty() == false );
		return delay.hasTimeElapsed( data.back().delay );
	}
	
	long double getElapsedMicroSecondsTime() const
	{
		return delay.getCurrentElapsedMicrosecondsTime().count();
	}
	
	std::chrono::duration<long double, std::micro> getCurrentElapsedMicroSecondsTime() const
	{
		return delay.getCurrentElapsedMicrosecondsTime();
	}
};

}

#endif //DEMOS_LIB_DATA_STACK_TEMP_H