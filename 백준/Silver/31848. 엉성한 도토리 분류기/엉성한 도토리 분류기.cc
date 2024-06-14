#include <iostream>
#include <vector>


using namespace std;

int n, q;
int h[100001];
int d[100001];
int ans[100001];
vector<pair<int, int>> v;

int bn(int num) {
    int st = 0;
    int end = v.size();
    int ans = -1;

    while (st < end) {
        int mid = (st + end) / 2;

        if (num <= v[mid].first) {
            end = mid;
            ans = mid;
        }
        else st = mid + 1;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        h[i] += i - 1;
    }

    int mx = 1;
    v.push_back({h[mx], mx});

    for (int i = 2; i <= n; i++) {
        if (h[mx] < h[i]) {
            mx = i;
            v.push_back({h[mx], mx});
        }
    }
    
    for (int i = 1; i <= q; i++) {
        cout << v[bn(d[i])].second << " ";
    }

    return 0;
}
