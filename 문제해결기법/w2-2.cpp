#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� �̵��� �Ǵ� �ڿ��� �������� �ϹǷ� �ڽ����׼��� �ڿ��ǰ�ġ + �������׼��� �ڿ��ǰ�ġ�� ���� ���� �ڿ� ��������

bool compare(pair <int,int> a, pair <int,int> b) {
	return a.first + a.second > b.first + b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		int n; // �ڿ��� ����
		cin >> n;

		vector<pair<int, int>> res_vec; // �ڿ� ��� ���� < ����, ���>

		int i_sum = 0;
		int b_sum = 0;


		// �� �ձ��� �ڿ��� ��ġ �Է¹ޱ�
		for (int w = 0; w < n; w++) {

			int i, b; // �ڿ��� ��ġ
			cin >> i >> b;

			res_vec.push_back({ i,b });
		}

		// ����+����� ū ������� �������� ����
		sort(res_vec.begin(), res_vec.end(), compare);

		// �ڿ� ��������
		for (int w = 0; w < n; w++) {

			if (w % 2 == 0) { // ¦����° �϶��� ���Ͽձ��� ��������
				i_sum += res_vec[w].first;
			}
			else { // Ȧ����° �϶��� ���ձ��� ��������
				b_sum += res_vec[w].second;
			}
		}
			cout << i_sum - b_sum << "\n";
	}

}