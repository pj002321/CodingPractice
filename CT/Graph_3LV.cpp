// �Ű������� �־��� edge�� ���� ����Ʈ�� �ٲپ� 
// graph�� �����Ѵ�.
// 1�� ���κ��� �� �������� �ִܰŸ��� ���ϱ� 
// ���� bfs�� ���� 1�� ���κ��� i�� �������� 
// �ִܰŸ� dist[i]�� �����ش�.
// ���� dist[i]�� �ִ��� ���� �� dist�� ��ȸ�Ͽ� 
// �ִ񰪰� ��ġ�ϴ� ���� ������ answer�� 1 ������Ų��.
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n + 1);   // ũ�� n+1
  
    for (int i = 0; i < edge.size(); i++) {
        //a�� ���� b�� ��� ���̿� ������
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