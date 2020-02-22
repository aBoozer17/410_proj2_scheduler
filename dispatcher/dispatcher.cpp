/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "constants.h"
#include "dispatcher.h"
#include "PCB.h"
#include "CPU.h"



PCB Dispatcher::get_from_CPU() {
	PCB nullProcess;
	if (is_valid_job_on_cpu) {
		is_valid_job_on_cpu = false;
		return cpu->get_process_off_core();
	}
	return nullProcess;
}

void Dispatcher::put_on_CPU(PCB  &process) {
	cpu->put_process_on_core(process);
	is_valid_job_on_cpu = true;
}

bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}


