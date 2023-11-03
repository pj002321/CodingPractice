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
    
    // 각 장르별로 횟수 저장
    map<string, int> genrestoidx;
    // 고유번호에 따라 횟수 저장
    map<string, map<int, int>> genresNumberidx;
    // 반복
    for (int i = 0; i < genres.size(); i++) {
        // 장르별로 횟수 추가
        genrestoidx[genres[i]] += plays[i];
        // 고유번호와 플레이 횟수 추가
        genresNumberidx[genres[i]][i] = plays[i];
    }

    // 장르가 다 없어질 때 까지 반복
    while (genrestoidx.size() > 0) {
        string genre{""};
        int max{0};
        // 장르 중에서 횟수 젤 높은거 찾기
        for (auto g : genrestoidx) {
            if (max < g.second) {
                max = g.second;
                genre = g.first;
            }
        }

        // 2곡을 넣어야하므로 2번 반복
        for (int i = 0; i < 2; i++) {
            int max{ 0 };
            int num{ -1 };
            // 노래 중(고유번호)에서 제일 높은 것 찾기
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