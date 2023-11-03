#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> s, int K) {
	int answer = 0;
	// �켱���� ť ����
	// greater�̸� min heap�̴�
	// s.begin()���� s.end()���� push���ִ� �Ͱ� �����ϴ�
	priority_queue<int, vector<int>, greater<int>>
		pq(s.begin(), s.end());
	priority_queue<int, vector<int>, greater<int>> copyPq = pq;

	// ����� priority_queue�� ���Ҹ� ����մϴ�.
	while (!copyPq.empty()) {
		cout << copyPq.top() << " - ";
		copyPq.pop();
	}
	cout << endl;
	while (pq.size() > 1 && pq.top() < K) {
		int one = pq.top();
		cout << one << ' ';
		pq.pop();
		int two = pq.top();
		cout << two << ' ';
		pq.pop();
		int mix = one + two * 2;
		cout << mix << ' ';
		pq.push(mix);
		answer++;
		cout <<"mixcnt : "<< answer << endl;

	}
	if (pq.top() < K) return -1;
	else return answer;
}
int main()
{
	cout<<endl<<solution({ 2, 7, 1, 4, 10, 12 }, 7);
}