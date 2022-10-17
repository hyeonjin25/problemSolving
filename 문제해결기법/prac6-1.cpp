#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct counterInfo {
	int num, countTime;
};

struct customInfo {
	int price, useTime;
};

struct compare {
	bool operator()(counterInfo a, counterInfo b) {
		if (a.countTime == b.countTime) {
			return a.num > b.num;
		}
		else return a.countTime > b.countTime;
	}
};

int n, m;
int timeAns = 0;
int costAns[20001];
customInfo custom[100001];
priority_queue < counterInfo, vector<counterInfo> , compare > counter;

int main() {

	cin >> n >> m;

	for (int i = 1; i < m+1; i++) {
		cin >> custom[i].useTime >> custom[i].price;
	}


	for (int i = 1; i < n+1; i++) {
		counter.push({ i,custom[i].useTime });
		costAns[i] = custom[i].price;
		timeAns = max(timeAns, custom[i].useTime);
	}

	counterInfo temp;
	for (int i = n+1; i < m + 1; i++) {
		temp = counter.top(); // 가장 빨리 끝나는 카운터
		counter.pop();
		temp.countTime += custom[i].useTime;
		timeAns = max(timeAns, temp.countTime);
		costAns[temp.num] += custom[i].price;
		counter.push(temp);
	}

	cout << timeAns << "\n";
	for (int i = 1; i < n+1; i++) {
		cout << costAns[i] << "\n";
	}

}