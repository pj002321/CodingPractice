//n���� ���� �ƴ� �������� �ֽ��ϴ�.�� �������� ������ �ٲ��� �ʰ� ������ 
//���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�.���� ���[1, 1, 1, 1, 1]��
//���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.
//
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű������� �־��� �� 
//���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� 
//return �ϵ��� solution �Լ��� �ۼ����ּ���.
// <solution>
//�־��� ����[a, b, c, d, e]�� �ִٰ� �ϸ�
//�� ����� ���ϱ� �Ǵ� ���⸦ �ݺ��Ͽ� ���� �� �ִ� ����� ����
//���� ������ + �Ǵ� - �� �ϴ� ��� 2�����̹Ƿ� 2�� 5��(= 32)�����̴�.
//a���� e���� + �Ǵ� - ������ �ذ��� Ÿ�ٳѹ��� �Ǵ��� �Ǵ��ϸ� �ȴ�.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int cur, int index, int target) {
    // ���ϴ� ���� �������鼭 && �迭�� �ִ� ��� ���Ҹ� ��� ���� ��
    if (index == numbers.size() - 1) {
        if (cur + numbers[index] == target) answer++;
        if (cur - numbers[index] == target) answer++;
        return;
    }

    // �迭�� ���� ���� ���ؼ� DFS ����
    int next_plus = cur + numbers[index];
    DFS(numbers, next_plus, index + 1, target);

    // �迭�� ���� ���� ���� DFS ����
    int next_minus = cur - numbers[index];
    DFS(numbers, next_minus, index + 1, target);
}
int solution(vector<int> numbers, int target) {

    DFS(numbers,target,0,0);
    return answer;
}

int main()
{
    cout<<solution({ 1, 1, 1, 1, 1 }, 3);
}