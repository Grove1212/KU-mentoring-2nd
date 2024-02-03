#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<pair<bool, bool>> search_check;
queue<int> seq;

class Graph {
private:
	vector<list<int>> graph;
	int size;
public:
	Graph(int n) {
		this->size = n;
		list<int> l;
		for (int i = 0; i <= n; i++) {
			graph.push_back(l);
			search_check.push_back(make_pair(true, true));
		}
	}
	void connect(int, int);
	void DFS(int);
	void BFS(int);
	//void print();
};

void Graph::connect(int a, int b) {
	if (graph[a].empty()) {
		graph[a].push_back(b);
	}
	else if (graph[a].front() > b){
		graph[a].push_front(b);
	}
	else if (graph[a].back() < b) {
		graph[a].push_back(b);
	}
	else {
		list<int>::iterator i;

		for (i = graph[a].begin(); i != graph[a].end(); i++) {
			if (*i > b)
				break;
		}

		graph[a].insert(i, b);
	}

	if (graph[b].empty()) {
		graph[b].push_back(a);
	}
	else if (graph[b].front() > a) {
		graph[b].push_front(a);
	}
	else if (graph[b].back() < a) {
		graph[b].push_back(a);
	}
	else {
		list<int>::iterator i;

		for (i = graph[b].begin(); i != graph[b].end(); i++) {
			if (*i > a)
				break;
		}

		graph[b].insert(i, a);
	}
}

void Graph::DFS(int n) {
	search_check[n].first = false;
	cout << n << ' ';

	for (list<int>::iterator i = graph[n].begin(); i != graph[n].end(); i++) {
		if (search_check[*i].first)
			DFS(*i);
	}
}

void Graph::BFS(int n) {
	seq.pop();
	search_check[n].second = false;
	cout << n << ' ';

	for (list<int>::iterator i = graph[n].begin(); i != graph[n].end(); i++) {
		if (search_check[*i].second) {
			seq.push(*i);
			search_check[*i].second = false;
		}
	}

	if (!seq.empty())
		BFS(seq.front());
}

/*
void Graph::print() {
	list<int>::iterator it;

	for (int i = 1; i <= size; i++) {
		cout << i << " : ";

		for (it = graph[i].begin(); it != graph[i].end(); it++)
			cout << *it << ' ';
		cout << "\n";
	}
}
*/

int main() {
	int vertex, edge, start;
	int a, b;

	cin >> vertex >> edge >> start;

	Graph graph(vertex);

	for (int i = 0; i < edge; i++) {	
		cin >> a >> b;
		graph.connect(a, b);
	}

	graph.DFS(start);
	cout << "\n";

	seq.push(start);
	graph.BFS(start);

	//graph.print();
}