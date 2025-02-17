// stack

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using pii = pair<int,int>;

int n;
int arr[500001];
int ans[500001];
stack<pii> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = n; i > 0; i--) {
        st.push({arr[i], i});
        while (!st.empty()) {
            if (arr[i-1] > st.top().first) {
                ans[st.top().second] = i - 1;
                st.pop();
            } else break;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    return 0;
}