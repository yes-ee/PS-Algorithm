
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[501][501];
vector<vector<int>> arr;
vector<vector<int>> triangle;
int n;

int dfs(int cur, int idx) {
    if (dp[cur][idx] != -1) return dp[cur][idx];
    if (cur == n - 1) return arr[cur][idx];
    
    return dp[cur][idx] = max(dfs(cur + 1, idx), dfs(cur + 1, idx + 1)) + arr[cur][idx];
}

int solution(vector<vector<int>> triangle) {
    arr = triangle;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = -1;
        }
    }
    
    return dfs(0, 0);
}

int main() {
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j <= i; j++) {
            cin >> a;
            v.push_back(a);
        }
        triangle.push_back(v);
    }
    cout << solution(triangle);
    return 0;
}