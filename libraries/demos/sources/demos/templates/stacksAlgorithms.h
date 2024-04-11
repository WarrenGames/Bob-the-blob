#ifndef DEMOS_LIB_DATA_STACK_ALGORITHMS_H
#define DEMOS_LIB_DATA_STACK_ALGORITHMS_H

#include "demos/templates/demoStack.h"

//This template function is used to display demos stacks templates that were not enough in reserved size at time of saving demo data to file

namespace demos{

template<typename T>
std::size_t getGreaterStackSize(const std::vector< demos::Stack<T> >& stacksVector )
{
	if( stacksVector.empty() == false )
	{
		std::size_t maxSize{0};
		
		for( auto const& stack : stacksVector )
		{
			if( stack.getCommandsNumber() > maxSize )
			{
				maxSize = stack.getCommandsNumber();
			}
		}
		return maxSize;
	}
	else{
		return 0;
	}
}

}

#endif //DEMOS_LIB_DATA_STACK_ALGORITHMS_H