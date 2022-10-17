#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>graph[10005];
queue<int>que;
int visit[10005];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int a, b;
    cin >> T;

    // 방 그래프 만들기
    for (int i = 0; i < 10000; i++) {
        if (i != 0) graph[i].push_back(i - 1);
        if (i != 9999) graph[i].push_back(i + 1);
        // 숫자 거꾸로 구하기
        int ans = 0;
        int temp = i;
        for (int j = 0; j < 4; j++) {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        graph[i].push_back(ans);
    }

    for (int t = 0; t < T; t++) {
        // visit 초기화
        for (int i = 0; i < 10005; i++) {
            visit[i] = 10000;
        }

        cin >> a >> b;
       
        que.push(a);
        visit[a] = 0; // 시작 방은 0 시간

        while (!que.empty()) {
            int now = que.front();
            que.pop();

            for (int i = 0; i < graph[now].size(); i++) {
                if (visit[graph[now][i]] > visit[now] + 1) {
                    que.push(graph[now][i]);
                    visit[graph[now][i]] = visit[now] + 1;
                }
            }
        }
        cout << visit[b] << "\n";
    }
}