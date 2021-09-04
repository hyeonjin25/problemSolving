#include <iostream>
#include <vector>

using namespace std;

/* 
	스택으로 했을 때는 run-error 가 났었는데 벡터로 바꾸니까 correct됨 이유를 모르겠다
	가장 처음에 2번이 들어왔을 경우를 고려해야함. (벡터가 비었을 경우) 
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; // test case 수
	cin >> T;

	for (int t = 0; t < T; t++) {	

		vector<int> vector;

		std::vector<int> minvec;
		std::vector<int> maxvec;

		int c, n;
		int R; //질의 수
		cin >> R;
		int min = 0;
		int max = 0;

		for (int r = 0; r < R; r++) {

			cin >> c;
			if (c == 1) {
				cin >> n; // 1번이면 넣을 숫자 받기

				if (vector.empty()) { //벡터가 비어있을 경우 n으로 min과 max 초기화
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
				if (vector.empty()) continue; // 벡터가 비어있을 경우 건너뛰기

				int top = vector.back();
				vector.pop_back();

				if (top == min) { // 제거한 값이 최솟값이었을 경우 min값을 이전 최솟값으로 되돌림
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