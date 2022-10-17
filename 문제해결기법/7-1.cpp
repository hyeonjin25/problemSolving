#include <iostream>
#include <vector>
#include <memory.h>

// 양팔 저울 : 어떤 공은 자신보다 가벼운 공들을 가리킴
// 단방향 그래프 문제
// dfs 사용해서 가벼운 공들을 전부 가보기,  visit의 개수가 자신보다 가벼운 공들의 개수(자기자신 제외하므로 1 뺴고 출력하기)
// 그래프 초기화 할 떄 전부 초기화하기! n까지 하지 말기
// //// 0번은 없음, 1번 공부터! 기억하기

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
        // 그래프 초기화
        for (int i = 0; i < 101; i++) { // 전부 초기화
            graph[i].clear();
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b); // a번 공보다 가벼운 공들에 b번 공 추가
        }

        for (int i = 1; i < n+1; i++) {
            memset(visit, 0, sizeof(visit)); // visit 배열 초기화
            dfs(i);
            ans = 0;
            for (int j = 1; j < n+1; j++) {
                ans += visit[j];
            }
            cout << ans - 1 << " "; // 자기 자신 빼고 출력
        }
        cout << "\n";
    }
}