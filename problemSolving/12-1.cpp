#include <iostream>

using namespace std;

int n; //삼각형의 행의 수
int arr[101][101]; //삼각형을 이루는 이차원 배열 0번쨰는 사용안함


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
        
        for (int i = 2; i < n + 1; i++) { // 두번쨰 줄 부터 시작
            for (int j = 1; j < i + 1; j++) {
                if (j == 1) { // 가장 왼쪽일 경우
                    arr[i][j] = arr[i - 1][j] + arr[i][j]; // 그냥 바로 위의 값과 더해서 갱신
                }
                else if (j == i) {  // 가장 오른쪽일 경우
                    arr[i][j] = arr[i - 1][j - 1] + arr[i][j]; // 그냥 바로 위의 왼쪽 값과 더해서 갱신
                }
                else {
                    // 현재 위치의 값을 위에서 더해서 내려올 수 있는 최소 값으로 바꾸기 
                    // (내려올 수 있는 위의 두 값 중 더 작은 값과 자신을 더한 값으로 갱신)
                    arr[i][j] = min(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
                }
            }
        }

        // 맨 마지막 행에서 가장 작은 값 찾기
        int min = 10000000;
        for (int i = 1; i < n + 1; i++) {
            if (min > arr[n][i]) min = arr[n][i];
        }

        cout << min << "\n";
    }
}