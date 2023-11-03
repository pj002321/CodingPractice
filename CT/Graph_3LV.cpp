// 매개변수로 주어진 edge를 인접 리스트로 바꾸어 
// graph를 생성한다.
// 1번 노드로부터 각 노드까지의 최단거리를 구하기 
// 위해 bfs를 돌려 1번 노드로부터 i번 노드까지의 
// 최단거리 dist[i]를 구해준다.
// 이후 dist[i]의 최댓값을 구한 후 dist를 순회하여 
// 최댓값과 일치하는 값이 있으면 answer을 1 증가시킨다.
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);   // 크기 n+1
  
    for (int i = 0; i < edge.size(); i++) {
        //a번 노드와 b번 노드 사이에 간선이
        int from = edge[i][0]; // vertex a
        int to = edge[i][1];   // vertex b

        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int next : graph[current])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    int far = *max_element(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == far)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> edge{ {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
    cout << solution(6, edge);
}