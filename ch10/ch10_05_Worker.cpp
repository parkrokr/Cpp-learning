#pragma once

#include "ch10_05_Worker.h"
#include "ch10_05_Timer.h" //cpp ������ Timer class �� �˰� ������ ��

void Worker::doSomething()
{
	Timer timer;  //start timer

				  //do some work here

	timer.elapsed(); //end timer and report elapsed time
}
