#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
stack<char> st;
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    int len = s.length();
    
    for (int i = 0; i < len - 1; i++) {
        if (s[i] =='(' && s[i+1] == ')') { // 레이저
            ans += st.size();
            i++;
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else {
            st.pop();
            ans++;
        }
    }
    if (s[len-2] != '(') ans++;
    cout << ans;

    return 0;
}