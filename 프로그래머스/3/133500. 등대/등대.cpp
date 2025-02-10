// tree dp

#include <string>
#include <vector>
#define INF 1e9

using namespace std;

int dp[2][100001];
int visited[100001];
vector<int> graph[100001];

int dfs(int cur, int state) {
    if (dp[state][cur] != INF) return dp[state][cur];
    
    dp[0][cur] = 0;
    dp[1][cur] = 1;
    
    for (auto ch : graph[cur]) {
        if (visited[ch]) continue;
        visited[ch] = 1;
        dp[0][cur] += dfs(ch, 1);
        dp[1][cur] += min(dfs(ch, 0), dfs(ch, 1));
    }
    return dp[state][cur];
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    for (int i = 0; i <= n; i++) {
        dp[0][i] = dp[1][i] = INF;
    }
    
    int a, b;
    for (auto v : lighthouse) {
        a = v[0];
        b = v[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visited[1] = 1;
    
    answer = min(dfs(1, 0), dfs(1, 1));
    
    return answer;
}