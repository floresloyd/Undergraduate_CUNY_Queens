#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

///=================== JOB SCHEDULING Problem =====================
/// The greedy algorithm to schedule a given set of jobs
/// so that they average completion time is minimized
///
double GreedyJobScheduling1(vector<int>& jobs) {
	// Sort the jobs w.r.t. their running times
	sort(jobs.begin(), jobs.end());

	// Schedule the jobs in the sorted order with the shortest job first
	double totalCompletionTime = 0;
	int currentTime = 0;
	for (auto job: jobs) {
		currentTime += job;

		totalCompletionTime += currentTime;
	} //end-for

	return totalCompletionTime / jobs.size();
} //end-GreedyJobScheduling1

///-----------------------------------------------------------
/// Uses a min-heap and always schedules the remaining job
/// having the smallest running time
///
double GreedyJobScheduling2(vector<int>& jobs) {
	// Create a min-heap w.r.t. the jobs' running times
	priority_queue<int, vector<int>, std::greater<int>> H(jobs.begin(), jobs.end());

	// The next job to be scheduled is the one that has the min. running time.
	double totalCompletionTime = 0;
	int currentTime = 0;
	while (!H.empty()){
		currentTime += H.top();   // Get min
		H.pop();                  // Delete-min

		totalCompletionTime += currentTime;
	} //end-for

	return totalCompletionTime / jobs.size();
} //end-GreedyJobScheduling2

///------------------------------------------------------------
/// Test for the Job Scheduling problem
///
void JobSchedulingTest() {
	vector<int> jobs = {15, 8, 3, 10};
	printf("Average completion time is: %.2lf\n", GreedyJobScheduling1(jobs));

	jobs = { 15, 8, 3, 10 };
	printf("Average completion time is: %.2lf\n", GreedyJobScheduling2(jobs));
} //end-JobSchedulingTest

int main() {
	JobSchedulingTest();

	return 0;
} // end-main


