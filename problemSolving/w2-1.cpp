#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// break, continue�� �򰥸��� ���� �� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		vector<queue<string>> stu_vec;

		int n; //ģ������ ��
		int m; //�Ǻ��� ������ �ܾ� ��
		cin >> n >> m;

		// �Ǻ��� ���� �ޱ�
		vector<string> str_vec;
		string str;

		for (int w = 0; w < m; w++) {
			cin >> str;
			str_vec.push_back(str);
		}

		int k; //ģ������ ���� �ܾ��� ��

		// ģ������ ���� �ܾ�� �ޱ�
		for (int i = 0; i < n; i++) {
			cin >> k;
			queue<string>stu_que;
			for (int j = 0; j < k; j++) {
				cin >> str;
				stu_que.push(str);
			}
			stu_vec.push_back(stu_que);
		}

		int flag = 0;
		for (int w = 0; w < m; w++) {

			str = str_vec[w]; // w��° �ܾ�

			for (int v = 0; v < n; v++) {
				if (stu_vec[v].front().compare(str) == 0) { // str�� �л��� �� �Ѹ��� ù��° ������ ���
					stu_vec[v].pop();
					flag = 1;
					break;
				}
				else flag = 0;
			}
			
			// ��� �л��� ù��° ���ҵ� �ƴ� ��� 
			if (flag == 0) {
				cout << 0 << "\n";
				break; //���� ���̽���
			}
			else if (w == m - 1) { //������ �ܾ�� ���
				cout << 1 << "\n";
			}
		}
	}
}