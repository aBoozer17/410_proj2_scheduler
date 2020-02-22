/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "stats.h"
#include "PCB.h"
#include <vector>



using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector) {
	*vec = finished_vector;
	calcStats();
}





void Stats::calcStats() {
	av_wait_time = get_av_wait_time();
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
}

void Stats::showAllProcessInfo() {
	for (PCB &p: *vec) {
		cout << "Process " << p.process_number << " Required CPU time:" << p.required_cpu_time << " arrived:" << p.arrival_time << " started:" << p.start_time << " finished:" << p.finish_time << endl;
	}

}

float Stats::get_av_response_time() {
	float average;
	for (PCB &p: *vec) {
		int start = p.start_time;
		int arrival = p.arrival_time;
		average += (start - arrival);
	}

	average = average / vec->size();
	return average;
}

float Stats::get_av_turnaround_time() {
	float average;
	for (PCB &p : *vec) {
		average += (p.finish_time - p.arrival_time);
	}
	average = average / vec->size();
	return average;
}

float Stats::get_av_wait_time() {
	float average;
	for (PCB &p : *vec) {
		average += (p.finish_time - p.arrival_time - p.required_cpu_time);
	}
	average = average / vec->size();
	return average;
}


