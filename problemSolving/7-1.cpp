#include <iostream>
#include <vector>
#include <memory.h>

// ���� ���� : � ���� �ڽź��� ������ ������ ����Ŵ
// �ܹ��� �׷��� ����
// dfs ����ؼ� ������ ������ ���� ������,  visit�� ������ �ڽź��� ������ ������ ����(�ڱ��ڽ� �����ϹǷ� 1 ���� ����ϱ�)
// �׷��� �ʱ�ȭ �� �� ���� �ʱ�ȭ�ϱ�! n���� ���� ����
// //// 0���� ����, 1�� ������! ����ϱ�

using namespace std;

vector<int> graph[101];
int visit[101] = { 0, };

void dfs(int ballnum) {
    visit[ballnum] = 1;
    for (int i = 0; i < graph[ballnum].size(); i++) {
        if (!visit[graph[ballnum][i]]) {
            dfs(graph[ballnum][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n, m, a, b, ans;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n >> m;     
        // �׷��� �ʱ�ȭ
        for (int i = 0; i < 101; i++) { // ���� �ʱ�ȭ
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b); // a�� ������ ������ ���鿡 b�� �� �߰�
        }

        for (int i = 1; i < n+1; i++) {
            memset(visit, 0, sizeof(visit)); // visit �迭 �ʱ�ȭ
            dfs(i);
            ans = 0;
            for (int j = 1; j < n+1; j++) {
                ans += visit[j];
            }
            cout << ans - 1 << " "; // �ڱ� �ڽ� ���� ���
        }
        cout << "\n";
    }
}