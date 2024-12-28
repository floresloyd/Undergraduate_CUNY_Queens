#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

///=================== ACTIVITY SCHEDULING PROBLEM =====================
struct Activity {
	int id;
	int start;
	int finish;

	Activity(int id, int s, int f): id(id), start(s), finish(f) {}
};

///-------------------------------------------------------------------------------
/// An O(nlogn) algorithm to schedule activities
///
void ScheduleActivities(vector<Activity>& activities, vector<Activity>& scheduledActivities) {
	if (activities.size() == 0) return;

	// Sort the activities by their finish time
	auto cmp = [](Activity& first, Activity& second) { 
		return (first.finish < second.finish);
	};
	sort(activities.begin(), activities.end(), cmp);

	// OK. Take the first activity
	scheduledActivities.push_back(activities[0]);

	for (size_t i = 1; i < activities.size(); i++) {
		if (activities[i].start >= scheduledActivities.back().finish)
			scheduledActivities.push_back(activities[i]);
	} //end-for
} //end-ScheduleActivities

///------------------------------------------------------------------
/// Test code for ScheduleActivities
///
void ActivitySchedulingTest() {
#if 1
	vector<Activity> activities = {Activity(1, 1, 4), Activity(2, 3, 5), 
		Activity(3, 0, 6), Activity(4, 5, 7), Activity(5, 3, 8), 
		Activity(6, 5, 9), Activity(7, 6, 10), Activity(8, 8, 11),
		Activity(9, 8, 12), Activity(10, 2, 13), Activity(11, 12, 14)};
#else
	vector<Activity> activities = { Activity(1, 0, 4), Activity(2, 3, 6),
		Activity(3, 4, 8), Activity(4, 8, 10)};
#endif

	vector<Activity> scheduledActivities;

	// Schedule the activities
	ScheduleActivities(activities, scheduledActivities);

	printf("We scheduled %d activities. Here they are:\n", scheduledActivities.size());
	printf("ID START FINISH\n");
	for (auto &activity: scheduledActivities) {
		printf("%2d, [%2d, %2d)\n", activity.id,
			activity.start, activity.finish);
	} // end-for
} //end-ActivitySchedulingTest

int main() {
	ActivitySchedulingTest();

	return 0;
} // end-main
