#include <iostream>
#include <set>
using namespace std;

int sender[500005];
int no_read[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,n,m;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        for (int i = 1; i < m+1; i++) {// �޼��� 1������ m������
            cin >> sender[i]; // �ش� �޼����� ���� ��� ����
        }

        set<int> readers;

        for (int i = m; i > 0; i--) { // ���������� �����ϸ鼭 ����
            readers.insert(sender[i]); // �ش� �޽����� ���� ����� ���� ����׷쿡 �߰�
            no_read[i] = n - readers.size();
        }

        for (int i = 1; i < m + 1; i++) {
            cout << no_read[i] << " ";
        }
        cout << "\n";
    }
}