#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> s;
    for (int i = 0; i < numbers.size(); i++) {
        s.push_back(to_string(numbers[i]));
        // "6" "10" "2"
    }
    sort(s.begin(), s.end(), [](const string& x, const string& y) { return x + y > y + x; });
    // 2, 6, 10
    for (int i = 0; i < numbers.size(); i++) {
        cout << s[i]<<' ';
    }
    for (int i = 0; i < numbers.size(); i++)
        answer += s[i];

    if (answer[0] == '0') answer = "0";

    return answer;
}

int main()
{
    string s = solution({ 6, 10, 2 });
    for (auto v : s) cout << ' ' << v;
}