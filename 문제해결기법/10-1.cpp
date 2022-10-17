#include <iostream>
#include <vector>
#include <queue>

// t와 T조심..
// 방 탈출 문제 - 3가지 경우로 움직일 수 있음(앞, 뒤, 문자를 거꾸로 한 위치), 최소거리? 문제
// 각자 자기 방까지 올 수 있는 최단 이동 시간 저장하고, 마지막에 목적지의 이동시간 찾아서 출력
// visit은 큰 값은 10000으로 초기화, 더 짧은 이동시간으로 갱신해나감
// 방번호의 역순 구할 때, temp만들어서 구해야 함, 실제 i를 바꾸면 안됨
// 단방향 그래프 문제

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

    // 그래프 생성
    for (int i = 0; i < 10000; i++) {
        if (i != 9999) { // 9999 일때 제외하고
            graph[i].push_back(i + 1); // 다음방 갈 수 있음
        }
        if (i != 0) { // 0 일때 제외하고
            graph[i].push_back(i - 1); // 이전방 갈 수 있음
        }
        // 방번호를 역순으로 변경한 번호 구하기
        int num = 0;
        int temp = i; // 현재 방 번호 저장

        for (int j = 0; j < 4; j++) { // 마지막 자리까지 더해주고 끝내야 하므로 0부터 3까지 4번 돌아야 함
            num = 10 * num + temp % 10;
            temp /= 10;
        }
        graph[i].push_back(num); // 방번호가 역순인 방 갈 수 있음
    }

    for (int t = 0; t < T; t++) {
        cin >> a >> b;

        // visit 값 큰값으로 초기화
        for (int i = 0; i < 10000; i++) {
            visit[i] = 10000;
        }

        que.push(a); // 시작 방 넣어주기
        visit[a] = 0; // 시작 방 방문 처리 (시간 0부터 시작)
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < graph[now].size(); i++) {
                // 해당 방까지 가는데 걸리는 시간보다 현재 위치를 거쳐서 가는 시간이 더 짧을 경우만 갱신
                if (visit[graph[now][i]] > visit[now] + 1) {
                    que.push(graph[now][i]);
                    // 다음으로 가는 데 걸리는 시간 =  현재 위치까지 오는데 걸린 시간 + 1
                    visit[graph[now][i]] = visit[now] + 1;
                }
            }
        }
        cout << visit[b] << "\n";
    }
}