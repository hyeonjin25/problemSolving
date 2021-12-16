#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// name_vec을 배열로 구현했더니 스택 오버플로우 남

int main() {

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n;
		cin >> n;

		vector<int> graph[50001];
		int p, c;
		for (int i = 1; i < n; i++) {
			cin >> p >> c;
			graph[p].push_back(c);
		}

		vector<int> name_vec;
		string s;
		name_vec.push_back(0);
		for (int i = 1; i < n + 1; i++) {
			cin >> s;
			name_vec.push_back(s.length());
		}
		
		queue<int> que;
		int visit[50001] = {false,};
		
		que.push(1);
		visit[1] = true;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i];
				if (!visit[next]) {
					visit[next] = 1;
					que.push(next);
					name_vec[next] = name_vec[now] + name_vec[next] + 1;
				}
			}
		}

		for (int i = 1; i < n + 1; i++) {
			cout << name_vec[i] << "\n";
		}
	}

}