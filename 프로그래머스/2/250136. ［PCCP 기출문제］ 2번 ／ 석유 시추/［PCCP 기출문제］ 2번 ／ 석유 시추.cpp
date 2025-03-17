// bfs로 그룹 짓기
// 각 그룹별 크기 저장
// x 위치 끝까지 돌면서 해당되는 그룹 크기 추가

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using pii = pair<int, int>;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[501][501]; // 그룹 저장
int ans;
int grp = 0;
vector<int> sz; // 그룹에 포함된 석유 크기 저장

int bfs(int x, int y, vector<vector<int>>& land) {
    queue<pii> q;
    int ret = 1;
    vis[x][y] = grp;
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (land[nx][ny] == 0 || vis[nx][ny] >= 0) continue;
            
            q.push({nx, ny});
            vis[nx][ny] = grp;
            ret++;
        }
    }
    return ret;
}

int solution(vector<vector<int>> land) {
    n = land.size(); m = land[0].size();
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, -1);
    
    // bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 0 || vis[i][j] >= 0) continue;
            int cnt = bfs(i, j, land);
            sz.push_back(cnt);
            grp++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        set<int> s;
        for (int j = 0; j < n; j++) {
            if (vis[j][i] < 0) continue;
            int gr = vis[j][i];
            if (s.find(gr) != s.end()) continue;
            cnt += sz[gr];
            s.insert(gr);
        }
        ans = max(cnt, ans);
    }
        
    return ans;
}