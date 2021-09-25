#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>

using namespace std;

// 한 집에서 가장 멀리 있는 집 찾은 후 그 집에서 또 가장 멀리 있는 집 찾기
// 한 집에서 가장 멀리 있는 집이 원의 지름에 있는 집이기 때문
// 원의 지름에 있는 집에서 출발해서 또 다른 지름에 있는 집까지가 가장 먼 거리

// 테스트 케이스마다 초기화 잘 시켜주기

int T; // 테스트 케이스 개수
int n; // 집의 개수

vector<pair<int, int>>graph[2001];
int visit[2001] = { false, };

int max_dis = 0; // 가장 멀리 떨어진 거리
int end_house = 0; // start와 가장 멀리 떨어진 집

void DFS(int start, int dis) {
	if (visit[start]) return; // 이미 방문 한 경우
	
	visit[start] = true; //방문
	if (max_dis < dis) { // 지금까지 합한 거리와 최대거리 비교해서 교체
		max_dis = dis;
		end_house = start; // 가장 멀리 떨어진 집 갱신
	}

	for (int i = 0; i < graph[start].size(); i++) {
		DFS(graph[start][i].first, dis + graph[start][i].second);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		
		max_dis = 0; 
		end_house = 0;
		memset(visit, false, sizeof(visit)); // 방문기록 초기화
		// 그래프 벡터 초기화
		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
		}
		
		cin >> n;

		// 무방향 가중치 그래프 만들기
		int u, v, d;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> d;
			graph[u].push_back(make_pair(v,d));
			graph[v].push_back(make_pair(u,d));
		}

		// 가장 멀리 있는 집 구하기
		DFS(1, 0);

		max_dis = 0;
		memset(visit, false, sizeof(visit)); // 방문기록 초기화

		// 가장 멀리 있는 집에서 가장 멀리 있는 집 구하기
		DFS(end_house, 0);

		cout << max_dis << "\n";
	}
}