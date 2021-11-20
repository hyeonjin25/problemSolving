#include <iostream>

using namespace std;

int n; //삼각형의 행의 수
int arr[101][101]; //삼각형을 이루는 이차원 배열 0번쨰는 사용안함
int min_sum = 10000000;

void recur(int cur_i, int cur_j, int sum) {
    if (cur_i == n) { //마지막 행이라면
        min_sum = min(min_sum, sum + arr[cur_i][cur_j]); // 경로의 합이 가장 크다면 min_sum 갱신
        return;
    }
    recur(cur_i + 1, cur_j, sum + arr[cur_i][cur_j]);
    recur(cur_i + 1, cur_j + 1, sum + arr[cur_i][cur_j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n;
        // 삼각형 이루는 숫자들 입력 받기 (0번째는 사용안함)
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                cin >> arr[i][j];
            }
        }

        min_sum = 10000000;
        recur(1, 1, 0);
        cout << min_sum << "\n";
    }
}