/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include "scheduler_SRTF.h"
#include "constants.h"
#include <queue>
#include <algorithm>





void Scheduler_SRTF::sort() {

//fix this
	for (unsigned int i = 0; i < ready_q->size(); i++) {
		int midInd = -1;
		int maxInd = 99;

		int sortInd = ready_q->size() - 1;
		for (unsigned int j = 0; j < ready_q->size(); j++) {
			PCB current = ready_q->front();
			ready_q->pop();

			if (current.remaining_cpu_time <= maxInd && j <= sortInd) {
				midInd = j;
			    maxInd = current.remaining_cpu_time;
			}
			ready_q->push(current);
		}

		int minVal;
		for (unsigned int k = 0; k < ready_q->size(); k++) {
			PCB cur = ready_q->front();
			PCB temp;
			ready_q->pop();
			if (k != midInd) {
				ready_q->push(cur);
			}
			else {
				temp = cur;
			}
			ready_q->push(temp);

		}

	}



}



bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time == 0) {
		time_slice = tick_count;
		this->sort();
		return true;
	}
	return false;
}




