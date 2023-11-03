// ��ǥ���� ���� ��ĭ�� ��������
// ��ֹ��� ������ �ִܰŸ� ���ϱ�

// [���ѻ���]
// maps�� n x m ũ���� ���� ���� ���°� ����ִ� 2���� �迭��,
// n�� m�� ���� 1 �̻� 100 ������ �ڿ����Դϴ�.
// n�� m�� ���� ���� ����, �ٸ� ���� ������, n�� m�� 
// ��� 1�� ���� �Է����� �־����� �ʽ��ϴ�.
// maps�� 0�� 1�θ� �̷���� ������, 0�� ���� �ִ� �ڸ�,
// 1�� ���� ���� �ڸ��� ��Ÿ���ϴ�.
// ó���� ĳ���ʹ� ���� ���� ���� �����(1, 1) ��ġ�� ������, 
// ���� ������ ���� ���� ���� �ϴ���(n, m) ��ġ�� �ֽ��ϴ�.

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

            // pass ����
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny])
                continue;
            if (maps[nx][ny]==0)
                continue;

            // �� �̿��� ���
            visited[nx][ny] = true;        // �湮���� ���� ������Ʈ 
            q.push({ nx,ny });             // �湮 ��� ������Ʈ
            dist[nx][ny] = dist[x][y] + 1; // �Ÿ� ������Ʈ

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