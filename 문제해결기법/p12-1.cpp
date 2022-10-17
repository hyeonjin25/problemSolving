#include <iostream>

using namespace std;

int tri[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n;
        
        // 삼각형 이루는 숫자들 입력 받기 (0번쨰 사용 안함)
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                cin >> tri[i][j];
            }
        }

        // 두번쨰 줄부터 시작하면서 가장 작게 올 수 있는 거리 저장
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                if (j == 1) tri[i][j] = tri[i][j] + tri[i - 1][j]; // 첫번째 일 때
                else if (j == i) tri[i][j] = tri[i][j] + tri[i - 1][j - 1]; // 마지막 일 때
                else tri[i][j] = tri[i][j] + min(tri[i - 1][j], tri[i - 1][j - 1]);
            }
        }

        int ans = 10000000;
        for (int i = 1; i < n + 1; i++) {
            ans = min(ans, tri[n][i]);
        }

        cout << ans << "\n";
    }
}