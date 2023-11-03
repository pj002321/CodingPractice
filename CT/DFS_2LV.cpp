//n개의 음이 아닌 정수들이 있습니다.이 정수들을 순서를 바꾸지 않고 적절히 
//더하거나 빼서 타겟 넘버를 만들려고 합니다.예를 들어[1, 1, 1, 1, 1]로
//숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.
//
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 
//숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 
//return 하도록 solution 함수를 작성해주세요.
// <solution>
//주어진 수가[a, b, c, d, e]가 있다고 하면
//이 수들로 더하기 또는 빼기를 반복하여 만들 수 있는 경우의 수는
//각각 수별로 + 또는 - 를 하는 방법 2가지이므로 2의 5승(= 32)가지이다.
//a부터 e까지 + 또는 - 연산을 해가며 타겟넘버가 되는지 판단하면 된다.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int cur, int index, int target) {
    // 원하는 값이 나왔으면서 && 배열에 있는 모든 원소를 사용 했을 때
    if (index == numbers.size() - 1) {
        if (cur + numbers[index] == target) answer++;
        if (cur - numbers[index] == target) answer++;
        return;
    }

    // 배열의 다음 값을 더해서 DFS 실행
    int next_plus = cur + numbers[index];
    DFS(numbers, next_plus, index + 1, target);

    // 배열의 다음 값을 빼서 DFS 실행
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