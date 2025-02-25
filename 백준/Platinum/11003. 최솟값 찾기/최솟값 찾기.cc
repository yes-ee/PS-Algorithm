#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

deque<pii> dq;
int n, l;
int num;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> num;
        while (!dq.empty()) {
            if (dq.front().second < i - l + 1) dq.pop_front();
            else break;
        }
        while (!dq.empty()) {
            if (dq.back().first >= num) dq.pop_back();
            else break;
        }
        dq.push_back({num, i});
        cout << dq.front().first << " ";
    }
    return 0;
}