#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[1000001];
int dp[1000001]; // 최장 부분 수열에서 몇 번째에 위치하고 있는지
vector<int> v;
int mx_idx;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        int idx = iter - v.begin();
        
        if (iter == v.end()) {
            v.push_back(arr[i]);
            mx_idx = i;
        } else {
            v[idx] = arr[i];
        }
        dp[i] = idx;
    }

    cout << v.size()<< "\n";

    int idx = mx_idx;
    int cnt = v.size() - 1;
    stack<int> st;
    for (int i = idx; i > 0; i--) {
        if (dp[i] == cnt) {
            st.push(arr[i]);
            cnt--;
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}