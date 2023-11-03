#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;

struct process {
    int prio;
    int idx;
};
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<process> q;
    priority_queue<int> prio; // 우선순위 큐
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i],i });
        prio.push(priorities[i]);
    }
    while (!q.empty()) {
        if (q.front().prio == prio.top()) { // q에 담긴 우선순위가 
            answer++;
            if (q.front().idx == location) break;
            q.pop();
            prio.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}

int main()
{
    solution({ 1, 1, 9, 1, 1, 1 },0);
}