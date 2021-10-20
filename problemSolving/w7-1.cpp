#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;


struct ball { // ��ġ������ ��ǥ�� ��Ÿ��
	int num; // ���� ��ȣ
	bool check; //���� subtree�� ���� Ȯ���� �������� true
};

bool ball_check[101] = { 1, }; // �ش��ϴ� ��ȣ�� ���� subtree�� ���� Ȯ���� �������� true
vector<int> ball_sub[101]; // �� ��ȣ�� ������ ������ ������ ��� array

int n; // ���� ����
int m; // ��������� ������ Ƚ��
int a, b; // b�� ���� ���� ���ſ� �� a

int recurse(int curball) {
	if (ball_check[curball]) // subtreeȮ���� ���� ���̸�
		return curball; // �ڽ��� ��ȣ ����

	else { // subtree Ȯ���� ������ �ʾ�����
		int sub_ball;
		for (int i = 0; i < ball_sub[curball].size(); i++) { // subtree Ȯ��
			sub_ball = recurse(ball_sub[curball][i]);
			// check �� subtree ��ġ��
			for (int j = 0; j < ball_sub[sub_ball].size(); j++) {
				ball_sub[curball].push_back(ball_sub[sub_ball][j]);
			}
			ball_check[curball] = true;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> n >> m;

		// ball_check �ʱ�ȭ
		memset(ball_check, true, size(ball_check));

		// ball_sub�� ball ������ ���� �Է¹ޱ�
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			ball_sub[a].push_back(b);
			ball_check[a] = false; // subtree�� ���� ���� ball_check �ʿ�
		}

		for (int i = 1; i < n + 1; i++) {
			recurse(i);
		}

		for (int i = 1; i < n + 1; i++) {
			cout << ball_sub[i].size();
		}
	}
}