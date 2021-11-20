#include <iostream>

using namespace std;

int n; //�ﰢ���� ���� ��
int arr[101][101]; //�ﰢ���� �̷�� ������ �迭 0������ ������
int min_sum = 10000000;

void recur(int cur_i, int cur_j, int sum) {
    if (cur_i == n) { //������ ���̶��
        min_sum = min(min_sum, sum + arr[cur_i][cur_j]); // ����� ���� ���� ũ�ٸ� min_sum ����
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
        // �ﰢ�� �̷�� ���ڵ� �Է� �ޱ� (0��°�� ������)
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