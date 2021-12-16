#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct burger{
    int x;
    int y;
    double dis;
};

struct cmp {
    bool operator()(burger a, burger b) {
        if (a.dis == b.dis) {
            if (a.x == b.x) {
                return a.y < b.y;
            }
            else {
                return a.x < b.x;
            }
        }
        else return a.dis < b.dis;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, m, n, k, x, y;
    cin >> T;


    for (int t = 0; t < T; t++) {
        priority_queue<burger, vector<burger>, cmp>que;
        cin >> m >> n >> k;

        // ���� �ִ� m���� �ܹ����� �ޱ�
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            que.push(burger{ x, y, sqrt(x * x + y * y) });
            if (que.size() > k) que.pop(); // ��ġ�� ���� �� �ܹ����� ����
        }

        // ���� ����� n���� �ܹ����� �ޱ�
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            que.push(burger{ x, y, sqrt(x * x + y * y) });
            if (que.size() > k) que.pop(); // ��ġ�� ���� �� �ܹ����� ����
            cout << "��: " << que.top().x << " " << que.top().y << "\n";
        }
    }
}