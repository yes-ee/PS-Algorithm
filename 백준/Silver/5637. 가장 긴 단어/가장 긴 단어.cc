#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, ans, ret;
int len;

vector<string> splitStr(string s) {
    vector<string> ret;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '-' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) tmp += c;
        else {
            if (tmp != "") {
                ret.push_back(tmp);
                tmp = "";
            }
        }
    }
    if (tmp != "") ret.push_back(tmp);
    return ret;
}

int main() {
    int ed = 0;
    while (!ed) {
        cin >> s;
        vector<string> v = splitStr(s);
        for (auto s : v) {
            if (s == "E-N-D") {
                ed = 1;
                break;
            }
            if (s.length() > len) {
                len = s.length();
                ret = s;
            }
        }
    }
    string ans;
    for (char c : ret) {
        ans += tolower(c);
    }
    cout << ans;
    return 0;
}