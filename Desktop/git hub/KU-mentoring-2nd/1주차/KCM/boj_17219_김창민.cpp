#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<string, string> map;
	int n, m;
	string site, pw;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> site >> pw;
		map.insert({ site, pw });
	}

	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << map[site] << "\n";
	}
}