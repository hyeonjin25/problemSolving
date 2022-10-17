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
        
        // �ﰢ�� �̷�� ���ڵ� �Է� �ޱ� (0���� ��� ����)
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                cin >> tri[i][j];
            }
        }

        // �ι��� �ٺ��� �����ϸ鼭 ���� �۰� �� �� �ִ� �Ÿ� ����
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                if (j == 1) tri[i][j] = tri[i][j] + tri[i - 1][j]; // ù��° �� ��
                else if (j == i) tri[i][j] = tri[i][j] + tri[i - 1][j - 1]; // ������ �� ��
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