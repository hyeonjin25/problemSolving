#include <iostream>
#include <stack>
#include <memory.h>
#include <set>

using namespace std;

// �޼��� ���� ���� ��� �� ���ϱ�
// �ߺ� ���ŵǴ� set�̿��ؼ� �ؿ��� ���� ���� ��� �� ����
// ���� ���� ��� �� ���ؾ� �ϹǷ� n -  ���� ��� �� ����

int sender[500001]; // �޼��� ������ ����
int n, m; // �ο� ��, �޼��� ��
int no_read[500001]; // ���� ��� �� ���� ���� (�ڿ��� ����)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n >> m;
        for (int i = 1; i < m + 1; i++) { // �޼��� ������ �Է¹ޱ�
            cin >> sender[i];
        }
        
        set<int> readers;

        for (int i = m; i > 0; i--) { // ���� �ֱٿ� �޼��� ���� ������� ����
            readers.insert(sender[i]); // �ش� �޼����� �� ��� set�� ���� (�ߺ� ���ŵ�)
            no_read[i] = n - readers.size(); // �ش� �ż����� ���� ���� ��� �� ����
        }

        for (int i = 1; i < m + 1; i++) { // �޼��� ���� ��� �� ���
            cout << no_read[i] << "\n";
        }
    }
}