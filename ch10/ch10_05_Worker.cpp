#pragma once

#include "ch10_05_Worker.h"
#include "ch10_05_Timer.h" //cpp 에서만 Timer class 를 알고 있으면 됨

void Worker::doSomething()
{
	Timer timer;  //start timer

				  //do some work here

	timer.elapsed(); //end timer and report elapsed time
}
