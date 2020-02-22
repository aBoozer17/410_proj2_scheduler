/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "scheduler_RR.h"
#include "constants.h"
#include <queue>



bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.required_cpu_time == time_slice && ready_q->front().remaining_cpu_time == 0) {
		ready_q->pop();
		ready_q->push(p);
		time_slice = tick_count;
		return true;

	}
	return false;
}


