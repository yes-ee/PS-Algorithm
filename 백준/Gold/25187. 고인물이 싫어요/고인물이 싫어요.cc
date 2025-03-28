#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

using namespace std;

int n, m, q;
int g = 1;
int grp[100001];
int tankgrp[1000001];
vector<int> v[1000001];
int vis[100001];
int graph[100001];

void bfs(int idx) {
    int a, b;
    a = b = 0;
    queue<int> q;
    q.push(idx);
    tankgrp[idx] = g;
    if (graph[idx]) a++;
    else b++;
    vis[idx] = 1;


    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nxt : v[cur]) {
            if (vis[nxt]) continue;
            tankgrp[nxt] = g;
            if (graph[nxt]) a++;
            else b++;

            vis[nxt] = 1;
            q.push(nxt);
        }
    }

    if (a > b) grp[g] = 1; // 청정수가 더 많으면 1 저장
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> graph[i];
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin>>a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        bfs(i);
        g++;
    }

    // query
    for (int i = 0; i < q; i++) {
        cin >> a;
        cout << grp[tankgrp[a]] << "\n";
    }

    return 0;
}