#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	vector<string> v;
	unordered_map<string, int> m;
	string s;
	int i, t;

	v.push_back("");

	cin >> n >> p;

	for (i = 1; i <= n; i++) {
		cin >> s;
		m.insert({ s, i });
		v.push_back(s);
	}

	for (i = 0; i < p; i++) {
		cin >> s;

		if (s[0] >= 'A' && s[0] <= 'z') {
			cout << m[s] << "\n";
		}
		else {
			cout << v[stoi(s)] << "\n";
		}
	}
}