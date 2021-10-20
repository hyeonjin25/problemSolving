#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct customInfo {
	int useTime, cost; // ����ϴµ� �ҿ�Ǵ� �ð�, ��� �ݾ�
};

struct countInfo {
	int countTime, number; // ����� �����µ� �ɸ��� �ð�, ���� ��ȣ
};

struct cmp { // �������� ����
	bool operator()(countInfo a, countInfo b) {
		if(a.countTime == b.countTime)
			return a.number > b.number;
		else 
			return a.countTime > b.countTime;
	}
};

customInfo custom[100001]; // �մ� �迭
priority_queue<countInfo, vector<countInfo>, cmp> counter; // ���� �迭  - ����ü �������� ���� ���ֱ�
int costAns[20001]; // �� ���븶�� ����� �� ����
int n; // ������ ��
int m; // �մ��� ��
int timeAns = 0; // ��� �մԵ��� ����� ��ġ�µ� �ҿ�� �ð�

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// �մԺ� ���ð��� ���� �Է� �ޱ� (1������)
	for (int i = 1; i < m + 1; i++) {
		cin >> custom[i].useTime >> custom[i].cost;
	}

	// ���� ó������ �̿��� �մԵ� �ð��� ��� �ݾ� ����
	for (int i = 1; i < n + 1; i++) { // ���� 1�� ����
		counter.push({ custom[i].useTime, i }); // �ɸ��� �ð�, ����ϴ� ����
		costAns[i] += custom[i].cost; // �� ������ ��� �ð� ����
		timeAns = max(timeAns, custom[i].useTime); // ���� �� �ð� ã��
	}

	countInfo temp;
	// �� ���� ã��
	for (int i = n + 1; i < m + 1; i++) { // �̹� ���� �̿��� �մԵ� ���� �մԺ���
		temp = counter.top(); // �켱���� ť�� �̿��� ���� ���� ������ ���� ã��
		
		counter.pop();
		temp.countTime += custom[i].useTime; // �ش� ���뿡 ���� �մ� ���Ƿ� ���ð� ����
		timeAns = max(timeAns, temp.countTime);
		costAns[temp.number] += custom[i].cost;
		counter.push(temp); // ����� ���� �ٽ� ť�� ����
	}

	cout << timeAns << "\n";
	
	for (int i = 1; i < n + 1; i++) {
		cout << costAns[i] << "\n";
	}

}