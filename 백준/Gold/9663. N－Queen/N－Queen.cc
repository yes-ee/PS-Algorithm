#include <iostream>

using namespace std;

int visited[16][16];
int n, ans;

bool check(int y, int x) {
    for (int i = 1; i < y; i++) {
        if (visited[i][x]) return false;
    }
    int len = min(y, x);
    for (int i = 1; i < len; i++) {
        if (visited[y - i][x - i]) return false;
    }
    len = min(y, n + 1 - x);
    for (int i = 1; i < len; i++) {
        if (visited[y - i][x + i]) return false;
    }
    return true;
}

void dfs(int y) {
    if (y == n) {
        ans++;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!check(y + 1, i)) continue;

        visited[y+1][i] = 1;
        dfs(y + 1);
        visited[y+1][i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n / 2; i++) {
        visited[1][i] = 1;
        dfs(1);
        visited[1][i] = 0;
    }
    ans *= 2;
    if (n % 2) {
        visited[1][n / 2 + 1] = 1;
        dfs(1);
        visited[1][n / 2 + 1] = 0;
    }
    cout << ans;

    return 0;
}