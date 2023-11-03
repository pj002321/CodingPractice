#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // 중복제거
    answer = arr;
    return answer;
}
int main()
{
   
    vector<int> arr
    { 1,1,3,3,0,1,1 };

    vector<int> answer = solution(arr);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}


