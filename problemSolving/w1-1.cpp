#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {

		string s;
		int k; //���ڿ��� ��ġ�� ���� ����
		int n; //���ڿ��� ����

		cin >> s;
		cin >> k;
		n = s.length();

		//2���� �迭
		int arr[50][50];

		int r; //�迭�� ���α���
		r = (n % k == 0) ? (n / k) : (n / k + 1); 
		
		//arr(p,q)
		int str = 0;
		for (int q = 0; q < r; q++) {
			
			if (q % 2 == 0)//¦��
			{
				for (int p = 0; p < k; p++) {
					arr[p][q] = s[str];
					str++;
				}
			}
			else //Ȧ��
			{
				for (int p = k; p > 0; p--) {
					arr[p][q] = s[str];
					str++;
				}
			}
		}

		for (int p = 0; p < 4; p++) {
			for (int q = 0; q < 4; q++) {
				if (p == 0 && q == 3)continue;
				if (p == 1 && q == 3)continue;
				cout << arr[p][q] << " ";
			}
			cout  << "\n";
		}
	}
}