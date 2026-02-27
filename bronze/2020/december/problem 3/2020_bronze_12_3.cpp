#include<iostream>
using namespace std;
const int Infinity = 2147483647;
struct Cow {
	char dir; 
	int x;
	int y;
	int time_stopped = Infinity;//time the cow stopped
};
Cow C[50];
int N; // actual number of cows
int when_stopped(int i, int j, int curr_time) {
	/*
	at the current time, i has not been blocked yet
	calculate when j will block i if it happens
	if not, return Infinity
	*/
	Cow I = C[i];
	Cow J = C[j];
	if (I.dir == J.dir) {
		return Infinity;
	}
	if (I.dir == 'E') {
		swap(I.x, I.y);
		swap(J.x, J.y);
	}
	if (I.y >= J.y) {
		return Infinity;
	}
	if (J.time_stopped == Infinity) {
		if (I.x < J.x - curr_time || I.x - J.x >= J.y - I.y){
			return Infinity;
		}
	} else {
		if(I.x < J.x - J.time_stopped || J.x < I.x) {
			return Infinity;
		}
	}
	return J.y - I.y + curr_time;
}
int move_to_next_event(int curr_time) {
	/*
	moves all cows to the next time a cow that hasn't stopped stops
	return the time that you have moved to
	*/
	int minimums[50];
	int minT = Infinity; // next time a new cow stops
	for (int i = 0; i < N; i++) {
		minimums[i] = Infinity;
		if(C[i].time_stopped != Infinity) {
			continue;
		}
		for (int j = 0; j < N; j++) {
			int stopped = when_stopped(i, j, curr_time);
			if (minimums[i] > stopped) {
				minimums[i] = stopped;
			}
		}
		if (minT > minimums[i]) {
			minT = minimums[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (C[i].time_stopped == Infinity) {
			if (C[i].dir == 'N') {
				C[i].y += minT - curr_time;
			} else {
				C[i].x += minT - curr_time;
			}
			if (minimums[i] == minT) {
				C[i].time_stopped = minT;
			}
		}
	}
	return minT;
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> C[i].dir >> C[i].x >> C[i].y;
		// C[i].time_stopped = Infinity;
	}
	int curr_time = 0;
	do {
		curr_time = move_to_next_event(curr_time);
	} while (curr_time != Infinity);
	for (int i = 0; i < N; i++) {
		if (C[i].time_stopped == Infinity) {
			cout << "Infinity" << "\n";
		} else {
			cout << C[i].time_stopped << "\n";
		}
	}
	return 0;
}
