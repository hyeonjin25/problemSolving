#include <iostream>
#include <vector>

using namespace std;

/* 
	�������� ���� ���� run-error �� �����µ� ���ͷ� �ٲٴϱ� correct�� ������ �𸣰ڴ�
	���� ó���� 2���� ������ ��츦 ����ؾ���. (���Ͱ� ����� ���) 
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // test case ��
	cin >> T;

	for (int t = 0; t < T; t++) {	

		vector<int> vector;

		std::vector<int> minvec;
		std::vector<int> maxvec;

		int c, n;
		int R; //���� ��
		cin >> R;
		int min = 0;
		int max = 0;

		for (int r = 0; r < R; r++) {

			cin >> c;
			if (c == 1) {
				cin >> n; // 1���̸� ���� ���� �ޱ�

				if (vector.empty()) { //���Ͱ� ������� ��� n���� min�� max �ʱ�ȭ
					min = n; max = n; 
					minvec.push_back(n); maxvec.push_back(n);
				} 
				else {
					if(n <= min){min = n; minvec.push_back(n);}
					if(n >= max){max = n; maxvec.push_back(n);}
				}

				vector.push_back(n);

				cout << min << " " << max << "\n";
			}
			else {
				if (vector.empty()) continue; // ���Ͱ� ������� ��� �ǳʶٱ�

				int top = vector.back();
				vector.pop_back();

				if (top == min) { // ������ ���� �ּڰ��̾��� ��� min���� ���� �ּڰ����� �ǵ���
					minvec.pop_back();
					min = minvec.back(); 
				}
				if (top == max) {
					maxvec.pop_back();
					max = maxvec.back();
				}
			}
		}
	}
}