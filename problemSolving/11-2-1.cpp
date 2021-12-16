#include <iostream>
#include <string>

using namespace std;

char paper[1025][1025];
int red_count = 0;
int blue_count = 0;
int red_size = 0;
int blue_size = 0;


void recur(int size, int st_i, int st_j) {
    // ���̰� ���� ������ ä�������� �˻�
    char start = paper[st_i][st_j]; // �����ϴ� ��(���� ��)
    int is_break = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (start != paper[st_i + i][st_j + j]) { // ���� ���� ���� �ٸ� �� �̶��
                recur(size / 2, st_i, st_j);
                recur(size / 2, st_i + (size / 2), st_j);
                recur(size / 2, st_i, st_j + (size / 2));
                recur(size / 2, st_i + (size / 2), st_j + (size / 2));
                is_break = 1;
                break;
            }
        }
        if (is_break) break; // �ٱ� �ݺ����� ����
    }
    if (!is_break) { // �ݺ����� �� ���Ҵٸ�
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
        // ���� ���� �Է� �ޱ�
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