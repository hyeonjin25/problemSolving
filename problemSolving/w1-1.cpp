#include <iostream>

using namespace std;

/*
	¦���϶� Ȧ���϶� ��� ����ó�� ������� (�迭�� ũ�⸦ ��� ���)
	�迭 ������ �� ���� �� ����!!!! (k����.. Ư��)
*/


//2���� �迭
char arr[100][100];

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

		int r; //�迭�� ���α���
		r = (n % k == 0) ? (n / k) : (n / k + 1); 


		//�迭 �ʱ�ȭ
		for (int p = 0; p < k; p++) {
			for (int q = 0; q < r; q++) {
				arr[p][q] = 0;
			}
		}
		
		//arr(p,q)
		for (int q = 0; q < r; q++) {
			
			if (q % 2 == 0)//¦���� �϶�
			{
				for (int p = 0; p < k; p++) {
					int v = k * q + p;
					if (v >= s.size()) {  //���ڿ� �迭�� ������ ��� ���
						arr[p][q] = '.';
						continue; 
					} 
					arr[p][q] = s[v];
				}
			}
			else //Ȧ���� �϶�
			{
				for (int p = 0; p < k; p++) {
					int v = k * (q + 1) - (p + 1);
					if (v >= s.size()) {  //���ڿ� �迭�� ������ ��� ���
						arr[p][q] = '.';
						continue;
					}
					arr[p][q] = s[v];
				}
			}
		}

		for (int p = 0; p < k; p++) {
			for (int q = 0; q < r; q++) {
				if (arr[p][q] == '.') continue;
				cout << arr[p][q];
			}
		}
		//cout << "\n";
	}
}