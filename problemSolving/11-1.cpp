#include <iostream>
#include <string>

// ��ǰ

using namespace std;

// ���� ū ���̿��� �����ؼ� ������ ��� ������ ��ġ���� ������ 4������ �ɰ��� �ٽ� ����Ȯ�� �ݺ� -> ���

int n, w, s;
int m; // �ܾ��� ��
char alph[123]; //���ĺ� �ƽ�Ű�ڵ� 97 ~ 122 ���� ���
string words[24]; //�ܾ� ����
int score[24]; // ����ܾ� ������ ���� ���� ����
bool visit[24] = { 0, };
int max_sum = 0; // ������ ���� �ִ�

void recur(int idx, bool visit[], char alph[], int sum) { // ������ ����ܾ� �ޱ�
    visit[idx] = 1;
    for (int i = 0; i < m; i++) {
        if (visit[i]) continue; // �̹� Ȯ���� ���� �ǳʶٱ�
        // �ܾ ������ �� �ִ��� Ȯ��
        for (int j = 0; j < words[i].size(); j++) {
            if (!alph[words[i][j]]) {//���ĺ��� ������ ��� ���� ���ȣ�� ���� �ʰ� ����
                max_sum = max(max_sum, sum);
                return;
            }
            alph[words[i][j]]--; //���ĺ� ī�� ���
        }
        // �ܾ ������ �� ���� �� ���� �߰�
        sum += score[i];
        recur(i, visit, alph, sum + score[i]);
        if (i == m-1) i = 0; //���� �����ϸ� �ٽ� ó������ 
    }
    visit[alpha]
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // �� ���ĺ��� ī���� �� �Է¹ޱ�
    for (int N = 0; N < 26; N++) {
        cin >> n;
        alph[n] = n; //�ƽ�Ű�ڵ忡 �´� ��ġ�� ����
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) cin >> words[i]; // ���� �ܾ� �ޱ�
    for (int i = 0; i < m; i++) cin >> score[i]; // ���� �ܾ ���� �ޱ�


}