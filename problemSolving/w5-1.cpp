#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // �׽�Ʈ ���̽� ����
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n; // ���ŵ� ��ȣ�� �ð�
		cin >> n;

		vector<int>vec;

		int first, s;
		bool same = false; // ���� ��ȣ�� ���� ��ġ�ϴ� ��쿡 ��
		bool suc = false; // �ֱ�� ���� ��ġ�ϸ� ��
		bool end = false; // ���������� ���� Ȯ���ϸ� ��
		int cycle; // �ֱ��� ���� ����

		cin >> first;
		vec.push_back(first);
		for (int i = 0; i < n - 1; i++) { // �ι�° ���� �ޱ�
			cin >> s;
			vec.push_back(s);
		}

		for (int i = 1; i < n; i++) { // ù��° �ǳʶ�� ����
			s = vec[i];
			if (s == first) { // ���� ��ȣ�� �ֱ��� ù ��ȣ�� ���� ��
				same = true;
				int j = 0;
				while (same && !end) {
					for (j; j < j + i; j++) { // ù ��ȣ���� �ش� ��ȣ�� �ٷ� �ձ����� �ֱ�� ����
						if (vec[j + i] != vec[j]) { // �ش� �ֱⰡ �� �� �ֱ�� ������ Ȯ��
							same = false; 
							break;
						}
						if (j + i == n - 1) { // ���������� ��� Ȯ������ ���
							suc = true;
							cycle = i;
							end = true;
							break;
						}
					}
					j += i;
				}
				if (suc) break;
				end = false;
			}
		}

		if (suc) { 
			n = cycle;
		}
		// �ֱ⸦ ã���� �� �ֱ⸸ŭ ���, �ֱ⸦ ��ã���� �� ���� ���
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
	}
}