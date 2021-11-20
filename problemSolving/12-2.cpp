#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct room_info {
    int score, dist; // 평점, 거리
};

bool cmp(room_info a, room_info b) { // 오름차순 정렬
    return a.score < b.score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n; // 방의 수
    int count = 0;
    room_info room_arr[500001];

    for (int t = 0; t < T; t++) {
        cin >> n;
        
        stack<room_info>candi_stack;
        count = 0;

        // 집의 평점과 거리 받기
        for (int i = 0; i < n; i++) {
            cin >> room_arr[i].score >> room_arr[i].dist;
        }

        // score를 기준으로 오름차순 정렬
        sort(room_arr, room_arr + n, cmp);

        // 후보 선별하기
        int c; // count 담아놓는 곳
        for (int i = 0; i < n; i++) {
            if (i == n - 1) { // 마지막 방일 경우
                c = count; // for문 안에서 count가 변화하므로 원래의 count값 만큼 반복위해 따로 저장
                for (int j = 0; j < c; j++) { // 지금까지의 후보들 다시 점검
                    if (candi_stack.top().dist > room_arr[i].dist) { // 점수가 더 작은데 거리마저 더 먼 경우
                        // 후보에서 제외
                        candi_stack.pop();
                        count--;
                    }
                    else break; // 점수가 더 작지만 거리는 더 짧은 경우: 나머지 방은 모두 해당 방보다 거리가 짧으므로 더이상 볼필요 없음 
                }
                count++; // 마지막 방보다 점수가 높은 방은 없으므로 무조건 후보에 추가
            }
            else if (room_arr[i].dist > room_arr[i + 1].dist) { // 점수가 더 작은데 거리마저 더 먼 경우
                if (!candi_stack.empty()) {
                    c = count;
                    for (int j = 0; j < c; j++) { // 지금까지의 후보들 다시 점검
                        if (candi_stack.top().dist > room_arr[i + 1].dist) { // 점수가 더 작은데 거리마저 더 먼 경우
                            // 후보에서 제외
                            candi_stack.pop();
                            count--;
                        }
                        else break; // 점수가 더 작지만 거리는 더 짧은 경우: 나머지 방은 모두 해당 방보다 거리가 짧으므로 더이상 볼필요 없음 
                    }
                }
            }
            else { // 점수는 더 작지만 거리는 더 짧은 경우
                candi_stack.push(room_arr[i]); // 후보에 추가: 거리가 앞보다 더 짧은 경우에 push 되므로 거리 오름차
                count++;
            }
        }

        cout << count << "\n";
    }
}

