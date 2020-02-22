/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */


#include "scheduler.h"
#include <queue>
#include "constants.h"



void Scheduler::add(PCB p) {
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	return ready_q->front();
}

bool Scheduler::isEmpty() {
	if (ready_q->empty()) {
		return true;
	}
	return false;
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (p.remaining_cpu_time == 0) {
		time_slice = tick_count;
		return true;
	}
	return false;
}








