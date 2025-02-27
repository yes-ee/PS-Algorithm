#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string s;
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;
        stack<char> st;

        for (auto c : s) {
            if (st.empty() || st.top() != c) st.push(c);
            else st.pop();
        }
        if (st.empty()) ans++;
    }
    cout << ans;

    return 0;
}