#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> schedule;
int day;

int max_price(int n) {
	int max = 0;
	int sum = 0;

	if (n + schedule[n].first <= day) {
		sum += schedule[n].second;
		sum += max_price(n + schedule[n].first);
	}
	else if (n + schedule[n].first == day + 1) {
		sum += schedule[n].second;
	}
	
	max = sum;

	if (n + 1 <= day)
		sum = max_price(n + 1);

	if (sum > max)
		max = sum;

	return max;
}

int main() {
	int t, p;

	cin >> day;

	schedule.push_back({ 0, 0 });
	for (int i = 0; i < day; i++) {
		cin >> t >> p;
		schedule.push_back({ t, p });
	}

	cout << max_price(1);
}