#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct customInfo {
	int useTime, cost; // 계산하는데 소요되는 시간, 계산 금액
};

struct countInfo {
	int countTime, number; // 계산이 끝나는데 걸리는 시간, 계산대 번호
};

struct cmp { // 오름차순 정렬
	bool operator()(countInfo a, countInfo b) {
		if(a.countTime == b.countTime)
			return a.number > b.number;
		else 
			return a.countTime > b.countTime;
	}
};

customInfo custom[100001]; // 손님 배열
priority_queue<countInfo, vector<countInfo>, cmp> counter; // 계산대 배열  - 구조체 오름차순 정렬 해주기
int costAns[20001]; // 각 계산대마다 계산한 총 가격
int n; // 계산대의 수
int m; // 손님의 수
int timeAns = 0; // 모든 손님들이 계산을 마치는데 소요된 시간

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// 손님별 계산시간과 가격 입력 받기 (1번부터)
	for (int i = 1; i < m + 1; i++) {
		cin >> custom[i].useTime >> custom[i].cost;
	}

	// 계산대 처음으로 이용할 손님들 시간과 계산 금액 저장
	for (int i = 1; i < n + 1; i++) { // 계산대 1번 부터
		counter.push({ custom[i].useTime, i }); // 걸리는 시간, 사용하는 계산대
		costAns[i] += custom[i].cost; // 각 계산대의 사용 시간 누적
		timeAns = max(timeAns, custom[i].useTime); // 가장 긴 시간 찾기
	}

	countInfo temp;
	// 빈 계산대 찾기
	for (int i = n + 1; i < m + 1; i++) { // 이미 계산대 이용한 손님들 다음 손님부터
		temp = counter.top(); // 우선순위 큐를 이용해 가장 빨리 끝나는 계산대 찾기
		
		counter.pop();
		temp.countTime += custom[i].useTime; // 해당 계산대에 다음 손님 들어가므로 계산시간 누적
		timeAns = max(timeAns, temp.countTime);
		costAns[temp.number] += custom[i].cost;
		counter.push(temp); // 변경된 정보 다시 큐에 삽입
	}

	cout << timeAns << "\n";
	
	for (int i = 1; i < n + 1; i++) {
		cout << costAns[i] << "\n";
	}

}