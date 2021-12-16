#include <iostream>
#include <vector>
#include <queue>

// t�� T����..
// �� Ż�� ���� - 3���� ���� ������ �� ����(��, ��, ���ڸ� �Ųٷ� �� ��ġ), �ּҰŸ�? ����
// ���� �ڱ� ����� �� �� �ִ� �ִ� �̵� �ð� �����ϰ�, �������� �������� �̵��ð� ã�Ƽ� ���
// visit�� ū ���� 10000���� �ʱ�ȭ, �� ª�� �̵��ð����� �����س���
// ���ȣ�� ���� ���� ��, temp���� ���ؾ� ��, ���� i�� �ٲٸ� �ȵ�
// �ܹ��� �׷��� ����

using namespace std;

vector<int> graph[10001];
int visit[10001];
queue<int> que;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int a, b;
    cin >> T;

    // �׷��� ����
    for (int i = 0; i < 10000; i++) {
        if (i != 9999) { // 9999 �϶� �����ϰ�
            graph[i].push_back(i + 1); // ������ �� �� ����
        }
        if (i != 0) { // 0 �϶� �����ϰ�
            graph[i].push_back(i - 1); // ������ �� �� ����
        }
        // ���ȣ�� �������� ������ ��ȣ ���ϱ�
        int num = 0;
        int temp = i; // ���� �� ��ȣ ����

        for (int j = 0; j < 4; j++) { // ������ �ڸ����� �����ְ� ������ �ϹǷ� 0���� 3���� 4�� ���ƾ� ��
            num = 10 * num + temp % 10;
            temp /= 10;
        }
        graph[i].push_back(num); // ���ȣ�� ������ �� �� �� ����
    }

    for (int t = 0; t < T; t++) {
        cin >> a >> b;

        // visit �� ū������ �ʱ�ȭ
        for (int i = 0; i < 10000; i++) {
            visit[i] = 10000;
        }

        que.push(a); // ���� �� �־��ֱ�
        visit[a] = 0; // ���� �� �湮 ó�� (�ð� 0���� ����)
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < graph[now].size(); i++) {
                // �ش� ����� ���µ� �ɸ��� �ð����� ���� ��ġ�� ���ļ� ���� �ð��� �� ª�� ��츸 ����
                if (visit[graph[now][i]] > visit[now] + 1) {
                    que.push(graph[now][i]);
                    // �������� ���� �� �ɸ��� �ð� =  ���� ��ġ���� ���µ� �ɸ� �ð� + 1
                    visit[graph[now][i]] = visit[now] + 1;
                }
            }
        }
        cout << visit[b] << "\n";
    }
}