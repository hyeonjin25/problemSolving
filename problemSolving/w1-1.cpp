#include <iostream>

using namespace std;

/*
	2차원 배열 없이 푼 코드

	p r o b l e m s o l v  i  n  g
	0 1 2 3 4 5 6 7 8 9 10 11 12 13

	       
	  0    p s  o
	  1    r m  l
	  2    o e  v g
	 k-1   b l  i n

	 o = i
	 e = (k + k - i - 1)        => prob가 k만큼이고, e는 1열에서 k-2행이기 때문
	 v = i + 2k                 => o의 위치에서 prob lems 만큼 더하므로
	 g = (k + k - i - 1) + 2k   => e의 위치에서 prob lems 만큼 더하므로

	2개의 열을 한 묶음으로 봄, 앞의 열은 순서대로, 뒤의 열은 거꾸로 된 열.
	한 행 i에서 첫 번째 열은 i, 두 번쨰 열은 k + (k-i-1) 로 설정
	한 묶음의 열을 넘어갈 때마다 2k를 더해줌 (prob lems => 2*4 = 8 뒤부터 앞의 알고리즘을다시 반복하므로) 

	짝수일때 홀수일때 모두 예외처리 해줘야함 (배열의 크기를 벗어날 경우)
	배열 설정할 때 범위 잘 보기!!!! (k범위.. 특히)

	cout << "\n"; 빼먹으면 안됨

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

		int idx;
		for (int p = 0; p < k; p++) {
			for (int q = 0; q < r; q++) {
				if(q % 2 == 0) { //짝수열 일때
					idx = p + ((q / 2) * 2 * k);
					if (idx >= s.size()) {  //문자열 배열의 범위를 벗어날 경우
						continue;
					}
				}
				else { //홀수열 일때
					idx = (2 * k - p - 1) + ((q / 2) * 2 * k);
					if (idx >= s.size()) {  //문자열 배열의 범위를 벗어날 경우
						continue;
					}
				}
				cout << s[idx];
			}
		}
		cout << "\n";
	}
}