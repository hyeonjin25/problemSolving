#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

using namespace std;

// �񱳿����� �� ���� ��쵵 ���� ���� �� ����ϱ� -> ������ ������ �����ϴ� ���

int ccw(pair<int, int>a, pair<int, int>b, pair<int, int>c) {
	int res = (a.first * b.second + b.first * c.second + c.first * a.second) - (a.second * b.first + b.second * c.first + c.second * a.first);

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

		pair<int, int> a; 
		pair<int, int> b;
		pair<int, int> c; 
		pair<int, int> d; 

		cin >> a.first >> a.second >> b.first >> b.second;
		cin >> c.first >> c.second >> d.first >> d.second;

		if (b > a) { // ���� ���� a
			swap(a, b);
		}
		if (d > c) { // ���� ���� c
			swap(c, d);
		}

		int cc1 = ccw(a, b, c) * ccw(a, b, d); // ù��° ���� ����
		int cc2 = ccw(c, d, a) * ccw(c, d, b); // �ι�° ���� ����


		if (cc1 == 0 && cc2 == 0) {

			// ���� a�� ����
			int a_len = sqrt(pow(ax2 - ax1, 2) + pow(ay2 - ay1, 2));
			// ���� b�� ����
			int b_len = sqrt(pow(bx2 - bx1, 2) + pow(by2 - by1, 2));
			//�� ������ ������ ��
			int len_sum = a_len + b_len;

			// ���� a�� �տ� ���� �� a�� ó������ b�� �������� ����
			int ab_len = sqrt(pow(ax1 - bx2, 2) + pow(ay1 - by2, 2));
			// ���� b�� �տ� ���� �� b�� ó������ a�� �������� ����
			int ba_len = sqrt(pow(bx1 - ax2, 2) + pow(by1 - ay2, 2));
			// �� ������ �� ���� �� ���� �� ���� ������ ����
			int max_len = max(ab_len, ba_len);

			if (max_len > len_sum) { // �� ������ �� ���� �ȿ� ������ ������ ����
				cout << 1 << "\n";
			}
			else if (dot == 1) {
				// �� ������ �����̰ų� �����̰� �������� ���� ���
				cout << 2 << "\n";
			}
			// �� �� y�࿡ ���� �� ��� ( ���� �� ���̽��� x�� ��Һ� �ϱ� ������ x�� ��� ���� �ش� ���̽��� ���� ���)
			else if (ax1 == ax2 && bx1 == bx2) {
				if(ay1 <= by1 && by1 <= ay2 && ay1 <= by2 && by2 <= ay2) {
					// ù��° ������ �ι�° ������ ������
					cout << 4 << "\n";
				}
				else if (by1 <= ay1 && ay1 <= by2 && by1 <= ay2 && ay2 <= by2) {
					// �ι�° ������ ù��° ������ ������
					cout << 4 << "\n";
				}
				else {
					// �� ������ �Ϻΰ� ��ħ
					cout << 3 << "\n";
				}
			}
			else if (ax1 <= bx1 && bx1 <= ax2 && ax1 <= bx2 && bx2 <= ax2) {
				// ù��° ������ �ι�° ������ ������
					cout << 4 << "\n";
			}
			else if (bx1 <= ax1 && ax1 <= bx2 && bx1 <= ax2 && ax2 <= bx2) {
				// �ι�° ������ ù��° ������ ������
					cout << 4 << "\n";
			}
			else {
				// �� ������ �Ϻΰ� ��ħ
				cout << 3 << "\n";
			}
		}
		else if (cc1 <= 0 && cc2 <= 0) // �� ������ ����
			cout << 2 << "\n";

		else cout << 1 << "\n";
	}
}