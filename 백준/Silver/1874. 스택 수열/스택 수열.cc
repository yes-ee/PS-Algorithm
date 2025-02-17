// stack

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int num = 1;
stack<int> st;
int arr[100001];
vector<char> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int idx = 0;
    while (num <= n) {
        while (arr[idx] >= num) {
            st.push(num++);
            ans.push_back('+');
        }
        while (!st.empty() && arr[idx] == st.top()) {
            st.pop();
            ans.push_back('-');
            idx++;
        }
        if (!st.empty() && arr[idx] < st.top()) break;
    }

    if (!st.empty()) {
        cout << "NO";
        return 0;
    }

    for (auto i : ans) {
        cout << i << "\n";
    }

    return 0;
}