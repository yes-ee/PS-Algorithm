#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[1000001];
int pre[1000001];
vector<int> v;
vector<int> v_idx;
int mx_idx;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    fill(pre, pre + n + 1, -1);

    v.push_back(-2000000000);
    v_idx.push_back(0);
    for (int i = 1; i <= n; i++) {
        auto iter = lower_bound(v.begin(), v.end(), arr[i]);
        int idx = iter - v.begin();
        
        if (iter == v.end()) {
            v.push_back(arr[i]);
            v_idx.push_back(i);
            mx_idx = i;
        } else {
            v[idx] = arr[i];
            v_idx[idx] = i;
        }
        pre[i] = v_idx[idx - 1];
    }

    cout << v.size() - 1<< "\n";

    int idx = mx_idx;
    stack<int> st;
    while (1) {
        st.push(arr[idx]);
        idx = pre[idx];
        if (idx == 0) break;
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}