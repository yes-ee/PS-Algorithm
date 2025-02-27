#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (1)  {
        getline(cin, input);
        stack<char> st;
        int right = 1;

        if (input == ".") {
            return 0;
        }

        for (char c : input) {
            if (isalpha(c) || isspace(c) || c == '.') continue;
            if (c == '(' || c == '[') {
                st.push(c);
            } else if (c == ')') {
                if ((!st.empty()) && st.top() == '(') st.pop();
                else {
                    right = 0;
                    break;
                }
            } else {
                if ((!st.empty()) && st.top() == '[') st.pop();
                else {
                    right = 0;
                    break;
                }
            }
        }
        if (!st.empty()) right = 0;
        if (right) cout << "yes\n";
        else cout << "no\n";
    }   

    return 0;
}