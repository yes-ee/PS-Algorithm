#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, cnt = 1;
int arr[1500][1500];
priority_queue<pii, vector<pii>, less<pii>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i =0 ;i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++) pq.push({arr[n -1][i], (n-1) * n + i});

    while (cnt++ < n) {
        int y = pq.top().second / n;
        int x = pq.top().second % n;
        pq.pop();
        if (y == 0) continue;
        int idx = (y - 1) * n + x;
        pq.push({arr[y - 1][x], idx});
    }

    cout << pq.top().first;

    return 0;
}