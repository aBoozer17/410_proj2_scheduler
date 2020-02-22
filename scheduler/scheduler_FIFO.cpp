/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include "scheduler_FIFO.h"
#include "constants.h"

bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time == 0) {
		time_slice = tick_count;
		return true;
	}
	return false;
}





