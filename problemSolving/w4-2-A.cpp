#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ccw(pair<int, int>a, pair<int, int>b , pair<int,int>c) {
	int res = (a.first*b.second + b.first*c.second + c.first*a.second) - (a.second*b.first + b.second*c.first + c.second*a.first);

	if (res == 0) return 0; //��ĥ ��
	else if (res > 0) return 1; //�ݽð� ������ ��
	else return -1; //�ð������ ��
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {
		
		pair<int, int> one[2]; //ù��° ����
		pair<int, int> two[2]; //�ι�° ����

		cin >> one[0].first >> one[0].second >> one[1].first >> one[1].second;
		cin >> two[0].first >> two[0].second >> two[1].first >> two[1].second;

		int cc1 = ccw(one[0], one[1], two[0]) * ccw(one[0], one[1], two[1]); // ù��° ���� ����
		int cc2 = ccw(two[0], two[1], one[0]) * ccw(two[0], two[1], one[1]); // �ι�° ���� ����

		int ax1 = one[0].first; int ay1 = one[0].second;
		int ax2 = one[1].first; int ay2 = one[1].second;
		int bx1 = two[0].first; int by1 = two[0].second;
		int bx2 = two[1].first; int by2 = two[1].second;

		if (cc1 < 0 && cc2 < 0) // �� ������ ����
			cout << 2 << "\n";

		else if ((cc1 == 0 && cc2 == -1) || (cc1 == -1 && cc2 == 0)) //�� ������ �� ������ ������ ����
			cout << 2 << "\n";

		else if (cc1 == 1 && cc2 == 1) //�� ������ ���� �����̸� ��ġ�� ����
			cout << 1 << "\n";

		else if ((cc1 == 1 && cc2 == -1) || (cc1 == -1 && cc2 == 1)) //�� ������ ���� �����̸� ��ġ�� ����
			cout << 1 << "\n";

		else if ((cc1 == 1 && cc2 == 0) || (cc1 == 0 && cc2 == 1)) //�� ������ "��" ��������� ��ġ�� ����
			cout << 1 << "\n";

		else if (cc1 == 0 && cc2 == 0) {

			int a1, a2, b1, b2;
			if (ay1 == ay2 && by1 == by2) {// �� ������ x�࿡ ������ ���
				a1 = ax1; a2 = ax2;
				b1 = bx1; b2 = bx2;
			}
			else if (ax1 == ax2 && bx1 == bx2) { // �� ������ y�࿡ ������ ���
				a1 = ay1; a2 = ay2;
				b1 = by1; b2 = by2;
			}
			//��� �׽�Ʈ ���̽��� ��������� �־�� ��
			else { //�� ������ �����̸� ���� ���� ��ħ
				cout << 2 << "\n";
				continue;
			}

			if (a1 > a2) swap(a1, a2);	
			if (b1 > b2) swap(b1, b2);	

			//�� ������ ������ �� (ab + cd)
			int len_sum = abs(a1 - a2) + abs(b1 - b2);
			// �� ������ �� ���� �� ���� �� ���� ������ ����(ad || cb)
			int max_len = max(abs(a1 - b2), abs(b1 - a2));

			if (max_len > len_sum) { // �� ������ �� ���� �ȿ� ������ ������ ����
				cout << 1 << "\n";
			}
			else if (a1 <= b1 && a2 >= b2) {
				// ù��° ������ �ι�° ������ ������
				cout << 4 << "\n";
			}
			else if (a1 >= b1 && a2 <= b2) {
				// �ι�° ������ ù��° ������ ������
				cout << 4 << "\n";
			}
			else if (a1 == b2 || a2 == b1) { 
				//�� ������ �� ������ �̾���
				cout << 2 << "\n";
			}
			else {
				// �� ������ �Ϻΰ� ��ħ
				cout << 3 << "\n";
			}
		}
	}
}