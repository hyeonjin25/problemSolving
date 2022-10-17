#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n; // 디렉토리 개수
		cin >> n;

		// 인접 리스트 
		vector<int>graph[50001];

		// 단방향 그래프 만들기
		int p, c;
		for (int i = 0; i < n - 1; i++) {
			cin >> p >> c;
			graph[p].push_back(c); // 상위 -> 하위 단방향
		}

		// 이름의 문자 수 저장
		vector<int>name_vec;
		string name;
		name_vec.push_back(0); // 0번쨰는 사용 안함
		for (int i = 1; i < n+1; i++) {
			cin >> name;
			name_vec.push_back(name.length());
		}

		int visit[50001] = {false,};
		queue<int>q;

		q.push(1);
		visit[1] = true;

		// bfs
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];
				if (!visit[next]) { // 이미 갔던 곳이 아니라면
					q.push(next); // 자식 디렉토리 큐에 넣기
					visit[next] = true;
					// 상위 디렉토리 문자 수 + 1(/) + 자신의 문자 수
					name_vec[next] = name_vec[now] + 1 + name_vec[next]; 
				}
			}
		}

		for (int i = 1; i < n + 1; i++) {
			cout << name_vec[i] << "\n";
		}
	}
}