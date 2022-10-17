#include<iostream>
#include<vector>

using namespace std;

// 양팔저울
// 그래프

vector<int> graph[105];
int visit[105] = { 0, };

void dfs(int ball) {
	visit[ball] = 1;
	for (int i = 0; i < graph[ball].size(); i++) {
		if (!visit[graph[ball][i]]) {
			dfs(graph[ball][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m, a, b;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		for (int i = 0; i < 105; i++) { // 그래프 초기화
			graph[i].clear();
		}
		for (int i = 0; i < m; i++) { // 자신보다 가벼운 공들 가리키기
			cin >> a >> b;
			graph[a].push_back(b); 
		}
		for (int i = 1; i < n + 1; i++) {
			// visit함수 초기화
			memset(visit, 0, sizeof(visit));
			dfs(i);
			int count = 0;
			for (int j = 1; j < n + 1; j++) {
				if(visit[j]) count++;
			}
			cout << count - 1 << " ";
		}
		cout << "\n";
	}

}