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

        // 원래 있던 m개의 햄버거집 받기
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            que.push(burger{ x, y, sqrt(x * x + y * y) });
            if (que.size() > k) que.pop(); // 넘치면 제일 먼 햄버거집 제거
        }

        // 새로 생기는 n개의 햄버거집 받기
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            que.push(burger{ x, y, sqrt(x * x + y * y) });
            if (que.size() > k) que.pop(); // 넘치면 제일 먼 햄버거집 제거
            cout << "답: " << que.top().x << " " << que.top().y << "\n";
        }
    }
}