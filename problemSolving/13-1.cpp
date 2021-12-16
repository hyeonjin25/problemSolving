#include <iostream>
using namespace std;

// �ܾ� ����
// kmp����

string puz[3000];
int fail[3000];

void fail_func(string p) {
    fail[0] = 0; // 0���� ���� ������ 0����
    int j = 0;
    for (int i = 1; i < p.size(); i++) { // 1��°���� ����
        while (j > 0 && p[j] != p[i]) { // ���� �Լ��� �̿��� ����Ʈ
            j = fail[j - 1];
        }
        if (p[j] == p[i]) {
            j++;
        }
        fail[i] = j;
    }
}

int kmp(string t, string p) {
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        while (j>0 && p[j]!=t[i]) { // ���� �Լ��� �̿��� ����Ʈ
            j = fail[j - 1];
        }
        if (p[j] == t[i]) {
            if (j == p.size() - 1) { // �˻� ����
                return 1;
            }
            else{ // ���� �˻�  
                j++;
            }
        }
    }
    return 0; // �ݺ������� ������ ���ϵ��� ������ ���з� ����
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // �� �ٸ��� ������ ���ĺ� ��Ʈ������ �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        cin >> puz[i];
    }
    string text, word; // �������� ��ģ ���ڿ�, ã�� �ܾ�

    // �������� ���η� ���� ���ڿ�
    for (int i = 0; i < n; i++) {
        text += puz[i];
        text += "$";
    }
    // �������� ���η� ���� ���ڿ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            text += puz[j][i];
        }
        text += "$";
    }

    // �������� �밢������ ���� ���ڿ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            text += puz[j][j+i];
        }
        text += "$";
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            text += puz[j+i][j];
        }
        text += "$";
    }

    for (int i = 0; i < m; i++) {
        cin >> word; // ã�� �ܾ� �ޱ�

        fail_func(word); // �����Լ� ���

        if (kmp(text, word)) { // �˻�����
            cout << 1 << "\n";
        }
        else cout << 0 << "\n"; //�˻�����
    }
}