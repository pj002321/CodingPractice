#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // �� �帣���� Ƚ�� ����
    map<string, int> genrestoidx;
    // ������ȣ�� ���� Ƚ�� ����
    map<string, map<int, int>> genresNumberidx;
    // �ݺ�
    for (int i = 0; i < genres.size(); i++) {
        // �帣���� Ƚ�� �߰�
        genrestoidx[genres[i]] += plays[i];
        // ������ȣ�� �÷��� Ƚ�� �߰�
        genresNumberidx[genres[i]][i] = plays[i];
    }

    // �帣�� �� ������ �� ���� �ݺ�
    while (genrestoidx.size() > 0) {
        string genre{""};
        int max{0};
        // �帣 �߿��� Ƚ�� �� ������ ã��
        for (auto g : genrestoidx) {
            if (max < g.second) {
                max = g.second;
                genre = g.first;
            }
        }

        // 2���� �־���ϹǷ� 2�� �ݺ�
        for (int i = 0; i < 2; i++) {
            int max{ 0 };
            int num{ -1 };
            // �뷡 ��(������ȣ)���� ���� ���� �� ã��
            for (auto h : genresNumberidx[genre]) {
                if (max < h.second) {
                    max = h.second;
                    num = h.first;
                }
            }
            if (num == -1)break;
            answer.push_back(num);
            genresNumberidx[genre].erase(num);
        }

        genrestoidx.erase(genre);
            
    }

    return answer;
}
int main()
{
    vector<string> genres
    { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays
    { 500, 600, 150, 800, 2500 };
    
    vector<int> answer = solution(genres, plays);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}