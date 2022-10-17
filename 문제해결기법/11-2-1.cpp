#include <iostream>
#include <string>

using namespace std;

char paper[1025][1025];
int red_count = 0;
int blue_count = 0;
int red_size = 0;
int blue_size = 0;


void recur(int size, int st_i, int st_j) {
    // 종이가 같은 색으로 채워졌는지 검사
    char start = paper[st_i][st_j]; // 시작하는 색(기준 색)
    int is_break = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (start != paper[st_i + i][st_j + j]) { // 만약 기준 색과 다른 색 이라면
                recur(size / 2, st_i, st_j);
                recur(size / 2, st_i + (size / 2), st_j);
                recur(size / 2, st_i, st_j + (size / 2));
                recur(size / 2, st_i + (size / 2), st_j + (size / 2));
                is_break = 1;
                break;
            }
        }
        if (is_break) break; // 바깥 반복문도 종료
    }
    if (!is_break) { // 반복문을 다 돌았다면
        if (start == 'R') {
            red_count++;
            red_size += size * size;
        }
        else {
            blue_count++;
            blue_size += size * size;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n;
        // 종이 색깔 입력 받기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> paper[i][j];
            }
        }

        red_count = 0;
        blue_count = 0;
        red_size = 0;
        blue_size = 0;

        recur(n, 0, 0);

        cout << red_count << " " << red_size << " " << blue_count << " " << blue_size << "\n";
    }
}