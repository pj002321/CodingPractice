// 목표지점 까지 한칸씩 움직여서
// 장애물을 따지고 최단거리 구하기

// [제한사항]
// maps는 n x m 크기의 게임 맵의 상태가 들어있는 2차원 배열로,
// n과 m은 각각 1 이상 100 이하의 자연수입니다.
// n과 m은 서로 같을 수도, 다를 수도 있지만, n과 m이 
// 모두 1인 경우는 입력으로 주어지지 않습니다.
// maps는 0과 1로만 이루어져 있으며, 0은 벽이 있는 자리,
// 1은 벽이 없는 자리를 나타냅니다.
// 처음에 캐릭터는 게임 맵의 좌측 상단인(1, 1) 위치에 있으며, 
// 상대방 진영은 게임 맵의 우측 하단인(n, m) 위치에 있습니다.

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int m,n;
int dist[101][101];
int visited[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<pair<int, int>> q;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    m = maps.size();
    n = maps[0].size();

    visited[0][0] = true;
    q.push({ 0,0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            // pass 조건
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            if (maps[nx][ny]==0)
                continue;

            // 그 이외의 경우
            visited[nx][ny] = true;        // 방문가능 여부 업데이트 
            q.push({ nx,ny });             // 방문 기록 업데이트
            dist[nx][ny] = dist[x][y] + 1; // 거리 업데이트

        }
    }

    if (dist[m - 1][n - 1] == 0)
        answer -= 1;
    else
        answer = dist[m - 1][n - 1];

    return answer;
}

int main()
{

}