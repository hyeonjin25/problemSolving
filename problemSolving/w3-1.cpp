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

		int n; // ���丮 ����
		cin >> n;

		// ���� ����Ʈ 
		vector<int>graph[50001];

		// �ܹ��� �׷��� �����
		int p, c;
		for (int i = 0; i < n - 1; i++) {
			cin >> p >> c;
			graph[p].push_back(c); // ���� -> ���� �ܹ���
		}

		// �̸��� ���� �� ����
		vector<int>name_vec;
		string name;
		name_vec.push_back(0); // 0������ ��� ����
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
				if (!visit[next]) { // �̹� ���� ���� �ƴ϶��
					q.push(next); // �ڽ� ���丮 ť�� �ֱ�
					visit[next] = true;
					// ���� ���丮 ���� �� + 1(/) + �ڽ��� ���� ��
					name_vec[next] = name_vec[now] + 1 + name_vec[next]; 
				}
			}
		}

		for (int i = 1; i < n + 1; i++) {
			cout << name_vec[i] << "\n";
		}
	}
}