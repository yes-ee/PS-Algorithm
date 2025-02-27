#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    bool valid = true;
    stack<char> st;
    for (auto c : s) {
        if (c == '(' || c == '[') st.push(c);
        else if (!st.empty()) {
            if (c == ')' && st.top() == '(') st.pop();
            else if (c == ']' && st.top() == '[') st.pop();
        } else {
            valid = false;
            break;
        }
    }
    if (!st.empty()) valid = false;
    if (!valid) {
        cout << 0;
        return 0;
    }
    stack<pair<char, int>> stt;
    for (auto c : s) {
        if (c == '(' || c == '[') stt.push({c, 0});
        else {
            if (stt.size() == 1) {
                auto match = stt.top();
                int sum = match.second;
                if (!sum) sum = 1;
                if (c == ')') sum *= 2;
                else sum *= 3;
                ans += sum;
                stt.pop();
            } else {
                auto match = stt.top();
                int sum = match.second;
                if (!sum) sum = 1;
                if (c == ')') sum *= 2;
                else sum *= 3;
                stt.pop();

                auto pre = stt.top();
                stt.pop();
                stt.push({pre.first, pre.second + sum});
            }
        }
    }
    
    cout << ans;

    return 0;
}