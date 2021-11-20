#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct room_info {
    int score, dist; // ����, �Ÿ�
};

bool cmp(room_info a, room_info b) { // �������� ����
    return a.score < b.score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int n; // ���� ��
    int count = 0;
    room_info room_arr[500001];

    for (int t = 0; t < T; t++) {
        cin >> n;
        
        stack<room_info>candi_stack;
        count = 0;

        // ���� ������ �Ÿ� �ޱ�
        for (int i = 0; i < n; i++) {
            cin >> room_arr[i].score >> room_arr[i].dist;
        }

        // score�� �������� �������� ����
        sort(room_arr, room_arr + n, cmp);

        // �ĺ� �����ϱ�
        int c; // count ��Ƴ��� ��
        for (int i = 0; i < n; i++) {
            if (i == n - 1) { // ������ ���� ���
                c = count; // for�� �ȿ��� count�� ��ȭ�ϹǷ� ������ count�� ��ŭ �ݺ����� ���� ����
                for (int j = 0; j < c; j++) { // ���ݱ����� �ĺ��� �ٽ� ����
                    if (candi_stack.top().dist > room_arr[i].dist) { // ������ �� ������ �Ÿ����� �� �� ���
                        // �ĺ����� ����
                        candi_stack.pop();
                        count--;
                    }
                    else break; // ������ �� ������ �Ÿ��� �� ª�� ���: ������ ���� ��� �ش� �溸�� �Ÿ��� ª���Ƿ� ���̻� ���ʿ� ���� 
                }
                count++; // ������ �溸�� ������ ���� ���� �����Ƿ� ������ �ĺ��� �߰�
            }
            else if (room_arr[i].dist > room_arr[i + 1].dist) { // ������ �� ������ �Ÿ����� �� �� ���
                if (!candi_stack.empty()) {
                    c = count;
                    for (int j = 0; j < c; j++) { // ���ݱ����� �ĺ��� �ٽ� ����
                        if (candi_stack.top().dist > room_arr[i + 1].dist) { // ������ �� ������ �Ÿ����� �� �� ���
                            // �ĺ����� ����
                            candi_stack.pop();
                            count--;
                        }
                        else break; // ������ �� ������ �Ÿ��� �� ª�� ���: ������ ���� ��� �ش� �溸�� �Ÿ��� ª���Ƿ� ���̻� ���ʿ� ���� 
                    }
                }
            }
            else { // ������ �� ������ �Ÿ��� �� ª�� ���
                candi_stack.push(room_arr[i]); // �ĺ��� �߰�: �Ÿ��� �պ��� �� ª�� ��쿡 push �ǹǷ� �Ÿ� ������
                count++;
            }
        }

        cout << count << "\n";
    }
}

