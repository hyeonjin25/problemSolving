#include <iostream>

using namespace std;

/*
	2���� �迭 ���� Ǭ �ڵ�

	p r o b l e m s o l v  i  n  g
	0 1 2 3 4 5 6 7 8 9 10 11 12 13

	       
	  0    p s  o
	  1    r m  l
	  2    o e  v g
	 k-1   b l  i n

	 o = i
	 e = (k + k - i - 1)        => prob�� k��ŭ�̰�, e�� 1������ k-2���̱� ����
	 v = i + 2k                 => o�� ��ġ���� prob lems ��ŭ ���ϹǷ�
	 g = (k + k - i - 1) + 2k   => e�� ��ġ���� prob lems ��ŭ ���ϹǷ�

	2���� ���� �� �������� ��, ���� ���� �������, ���� ���� �Ųٷ� �� ��.
	�� �� i���� ù ��° ���� i, �� ���� ���� k + (k-i-1) �� ����
	�� ������ ���� �Ѿ ������ 2k�� ������ (prob lems => 2*4 = 8 �ں��� ���� �˰������ٽ� �ݺ��ϹǷ�) 

	¦���϶� Ȧ���϶� ��� ����ó�� ������� (�迭�� ũ�⸦ ��� ���)
	�迭 ������ �� ���� �� ����!!!! (k����.. Ư��)

	cout << "\n"; �������� �ȵ�

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

		int idx;
		for (int p = 0; p < k; p++) {
			for (int q = 0; q < r; q++) {
				if(q % 2 == 0) { //¦���� �϶�
					idx = p + ((q / 2) * 2 * k);
					if (idx >= s.size()) {  //���ڿ� �迭�� ������ ��� ���
						continue;
					}
				}
				else { //Ȧ���� �϶�
					idx = (2 * k - p - 1) + ((q / 2) * 2 * k);
					if (idx >= s.size()) {  //���ڿ� �迭�� ������ ��� ���
						continue;
					}
				}
				cout << s[idx];
			}
		}
		cout << "\n";
	}
}