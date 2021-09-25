#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>

using namespace std;

// �� ������ ���� �ָ� �ִ� �� ã�� �� �� ������ �� ���� �ָ� �ִ� �� ã��
// �� ������ ���� �ָ� �ִ� ���� ���� ������ �ִ� ���̱� ����
// ���� ������ �ִ� ������ ����ؼ� �� �ٸ� ������ �ִ� �������� ���� �� �Ÿ�

// �׽�Ʈ ���̽����� �ʱ�ȭ �� �����ֱ�

int T; // �׽�Ʈ ���̽� ����
int n; // ���� ����

vector<pair<int, int>>graph[2001];
int visit[2001] = { false, };

int max_dis = 0; // ���� �ָ� ������ �Ÿ�
int end_house = 0; // start�� ���� �ָ� ������ ��

void DFS(int start, int dis) {
	if (visit[start]) return; // �̹� �湮 �� ���
	
	visit[start] = true; //�湮
	if (max_dis < dis) { // ���ݱ��� ���� �Ÿ��� �ִ�Ÿ� ���ؼ� ��ü
		max_dis = dis;
		end_house = start; // ���� �ָ� ������ �� ����
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
		memset(visit, false, sizeof(visit)); // �湮��� �ʱ�ȭ
		// �׷��� ���� �ʱ�ȭ
		for (int i = 0; i < 2001; i++) {
			graph[i].clear();
		}
		
		cin >> n;

		// ������ ����ġ �׷��� �����
		int u, v, d;
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> d;
			graph[u].push_back(make_pair(v,d));
			graph[v].push_back(make_pair(u,d));
		}

		// ���� �ָ� �ִ� �� ���ϱ�
		DFS(1, 0);

		max_dis = 0;
		memset(visit, false, sizeof(visit)); // �湮��� �ʱ�ȭ

		// ���� �ָ� �ִ� ������ ���� �ָ� �ִ� �� ���ϱ�
		DFS(end_house, 0);

		cout << max_dis << "\n";
	}
}