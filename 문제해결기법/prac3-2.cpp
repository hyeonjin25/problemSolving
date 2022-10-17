#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> graph[2001];
int visit[2001] = { 0, };
int max_dis = 0;
int end_house = 0;

void DFS(int start, int dis) {

	if (visit[start]) return;

	visit[start] = 1;

	if (dis > max_dis) {
		max_dis = dis;
		end_house = start;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		DFS(graph[start][i].first, dis + graph[start][i].second);
	}
}

int main() {

	int T;
	cin >> T;
	int n, u, v, d;

	for (int t = 0; t < T; t++) {

		cin >> n;

		max_dis = 0;
		end_house = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < n - 1; i++){
			cin >> u >> v >> d;

			graph[u].push_back(make_pair(v,d));
			graph[v].push_back(make_pair(u,d));
		}

		DFS(1, 0);

		max_dis = 0;
		memset(visit, 0, sizeof(visit));

		DFS(end_house, 0);

		cout << max_dis << "\n";
	}

}