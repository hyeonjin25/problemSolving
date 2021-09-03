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
		int k; //문자열을 배치할 행의 개수
		int n; //문자열의 길이

		cin >> s;
		cin >> k;
		n = s.length();

		//2차원 배열
		int arr[50][50];

		int r; //배열의 가로길이
		r = (n % k == 0) ? (n / k) : (n / k + 1); 
		
		//arr(p,q)
		int str = 0;
		for (int q = 0; q < r; q++) {
			
			if (q % 2 == 0)//짝수
			{
				for (int p = 0; p < k; p++) {
					arr[p][q] = s[str];
					str++;
				}
			}
			else //홀수
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