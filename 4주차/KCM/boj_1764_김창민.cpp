#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<string> not_hear;
	vector<string> not_both;
	int n, m;
	int both = 0;
	string s;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		not_hear.insert(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		
		if (not_hear.find(s) != not_hear.end()) {
			both++;
			not_both.push_back(s);
		}
	}

	sort(not_both.begin(), not_both.end());

	cout << both << "\n";
	for (int i = 0; i < both; i++)
		cout << not_both[i] << "\n";
}