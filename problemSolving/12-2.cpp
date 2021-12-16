#include <iostream>
#include <algorithm>

using namespace std;

// �� ���ϱ�
// ���� ���� �������� �س���, ������� ���ϸ� ���ݱ����� �ּ� �Ÿ����� ������ Ż��

struct room_info {
    int score, dist; // ����, �Ÿ�
};

bool cmp(room_info a, room_info b) { // �������� ����
    return a.score > b.score;
}

room_info room_arr[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n; // ���� ��
    int count = 0;

    for (int t = 0; t < T; t++) {
        cin >> n;


        // ���� ������ �Ÿ� �ޱ�
        for (int i = 0; i < n; i++) {
            cin >> room_arr[i].score >> room_arr[i].dist;
        }

        // score�� �������� �������� ����
        sort(room_arr, room_arr + n, cmp);

        // �ĺ� �����ϱ�
        int dist = room_arr[0].dist; // ���ݱ��� �ĺ��� �� ���� ����� �Ÿ� ����
        count = 1; // ������ ���� ���� ù��° ���� ������ �ĺ��� �ֱ�
        for (int i = 1; i < n; i++) { // �ι�° ����� ����
            if (room_arr[i].dist < dist) {// ���� ���� ���ݱ����� �Ÿ����� �� ª�� ���
                count++;
                dist = room_arr[i].dist;
            }
        }

        cout << count << "\n";
    }
}

