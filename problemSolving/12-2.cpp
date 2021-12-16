#include <iostream>
#include <algorithm>

using namespace std;

// 방 구하기
// 평점 기준 내림차순 해놓고, 순서대로 비교하며 지금까지의 최소 거리보다 작으면 탈락

struct room_info {
    int score, dist; // 평점, 거리
};

bool cmp(room_info a, room_info b) { // 내림차순 정렬
    return a.score > b.score;
}

room_info room_arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n; // 방의 수
    int count = 0;

    for (int t = 0; t < T; t++) {
        cin >> n;


        // 집의 평점과 거리 받기
        for (int i = 0; i < n; i++) {
            cin >> room_arr[i].score >> room_arr[i].dist;
        }

        // score를 기준으로 내림차순 정렬
        sort(room_arr, room_arr + n, cmp);

        // 후보 선별하기
        int dist = room_arr[0].dist; // 지금까지 후보들 중 가장 가까운 거리 저장
        count = 1; // 평점이 가장 높은 첫번째 방은 무조건 후보에 넣기
        for (int i = 1; i < n; i++) { // 두번째 방부터 시작
            if (room_arr[i].dist < dist) {// 다음 집이 지금까지의 거리보다 더 짧은 경우
                count++;
                dist = room_arr[i].dist;
            }
        }

        cout << count << "\n";
    }
}

