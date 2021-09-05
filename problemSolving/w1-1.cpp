#include <iostream>

using namespace std;

/*
	짝수일때 홀수일때 모두 예외처리 해줘야함 (배열의 크기를 벗어날 경우)
	배열 설정할 때 범위 잘 보기!!!! (k범위.. 특히)
*/


//2차원 배열
char arr[100][100];

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

		int r; //배열의 가로길이
		r = (n % k == 0) ? (n / k) : (n / k + 1); 


		//배열 초기화
		for (int p = 0; p < k; p++) {
			for (int q = 0; q < r; q++) {
				arr[p][q] = 0;
			}
		}
		
		//arr(p,q)
		for (int q = 0; q < r; q++) {
			
			if (q % 2 == 0)//짝수열 일때
			{
				for (int p = 0; p < k; p++) {
					int v = k * q + p;
					if (v >= s.size()) {  //문자열 배열의 범위를 벗어날 경우
						arr[p][q] = '.';
						continue; 
					} 
					arr[p][q] = s[v];
				}
			}
			else //홀수열 일때
			{
				for (int p = 0; p < k; p++) {
					int v = k * (q + 1) - (p + 1);
					if (v >= s.size()) {  //문자열 배열의 범위를 벗어날 경우
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