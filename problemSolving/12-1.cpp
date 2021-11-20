#include <iostream>

using namespace std;

int n; //�ﰢ���� ���� ��
int arr[101][101]; //�ﰢ���� �̷�� ������ �迭 0������ ������


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n;
        // �ﰢ�� �̷�� ���ڵ� �Է� �ޱ� (0��°�� ������)
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                cin >> arr[i][j];
            }
        }
        
        for (int i = 2; i < n + 1; i++) { // �ι��� �� ���� ����
            for (int j = 1; j < i + 1; j++) {
                if (j == 1) { // ���� ������ ���
                    arr[i][j] = arr[i - 1][j] + arr[i][j]; // �׳� �ٷ� ���� ���� ���ؼ� ����
                }
                else if (j == i) {  // ���� �������� ���
                    arr[i][j] = arr[i - 1][j - 1] + arr[i][j]; // �׳� �ٷ� ���� ���� ���� ���ؼ� ����
                }
                else {
                    // ���� ��ġ�� ���� ������ ���ؼ� ������ �� �ִ� �ּ� ������ �ٲٱ� 
                    // (������ �� �ִ� ���� �� �� �� �� ���� ���� �ڽ��� ���� ������ ����)
                    arr[i][j] = min(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
                }
            }
        }

        // �� ������ �࿡�� ���� ���� �� ã��
        int min = 10000000;
        for (int i = 1; i < n + 1; i++) {
            if (min > arr[n][i]) min = arr[n][i];
        }

        cout << min << "\n";
    }
}