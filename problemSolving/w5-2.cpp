#include <iostream>
#include <vector>

using namespace std;

int graph[1000001];
int n; // ���� ��
int m; // �ֹ��� ��

// ������ �Ÿ� �̻����� ������ �ξ��� ��� ��� �ֹ��� ���ְ� �����ϸ� true ����
int check(int len) {
	int cur = 1; // ���� ��ġ (���� ���� cur�̻��� �Ÿ����� ���� �� ����)
	int count = 0; // ������ �ֹ� ��

	// ���� �Ÿ� �̻��� �� �� ���� ����� �� ã��
	for (int i = 0; i < n; i++) {
		if (cur <= graph[i]) {
			cur = graph[i] + len; // ���� ������ �� ��ġ�κ��� ���ذŸ���ŭ ������ ��
			count++;
		}
		if (count == m) { // ��� �ֹ��� �������� ���
			return true;
		}
	}
	return false;
}

// ����Ž�� �̿��Ͽ� �ֹΰ��� �ִ�Ÿ� ã��
int binary(int l, int r) {

	int mid; // ��� �ε���
	int cur; // ���� Ž������ �ε���

	mid = (l + r) / 2; // �� ���� �߰� �� -  ���� �Ÿ�

	if (l == r) { // ������ 1�� ���
		return l;
	}
	if (l + 1 == r) { // ������ 2�� ��� 
		if (check(r)) return r;
		else return l;
	}

	// ����Լ��� ������ ���ذŸ� ã��
	// �ش� �Ÿ��� ���� ������ ��� �� �� �Ÿ��� �õ�
	if (check(mid)) {
		binary(mid, r);
	}
	//������ ��� �� ª�� �Ÿ��� �õ�
	else {
		binary(l, mid - 1); 
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
		
	// �� ��ġ�� �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		cin >> graph[i];
	}
		
	int asn = binary(1, graph[n - 1]);
		
	cout << asn;
}