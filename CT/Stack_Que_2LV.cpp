#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>



using namespace std;
//bool solution(string s)
//{
//	bool answer = true;
//	int cnt{};
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] == '(')
//			cnt++;
//		else if (s[i] == ')')
//			cnt--;
//
//		if (cnt < 0) {
//			answer = false;
//			break;
//		}
//	}
//	if (cnt == 0)
//		answer = true;
//	else answer = false;
//	return answer;
//}
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int day;
	//��������� �ִ� �Ϸ� �� ���� ����
	int max_day{ 0 };
	for (int i = 0; i < progresses.size(); i++) {
		day = (99 - progresses[i]) / speeds[i] + 1; // �۾������� 100 �̸�
		cout << day << endl;
		if (answer.empty() || max_day < day)
			answer.push_back(1);	// 
		else
			++answer.back();		// ������ ��Ҹ� �ø�
		cout << "a : "<<answer[i]<<endl;
		if (max_day < day)
			max_day = day;
	}
	return answer;
}
int main()
{

	//string s{ ")()(" };

	solution({ 93, 30, 55 }, { 1, 30, 5 });

	//for (int i = 0; answer.size(); i++) cout << answer[i] << ' ';
}