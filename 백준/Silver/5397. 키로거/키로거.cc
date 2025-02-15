// linked list

#include <iostream>
#include <list>
#include <string>

using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        string s;
        list<char> lst;
        list<char>::iterator it = lst.begin();
        cin >> s;
        for (auto c : s) {
            if (c == '-') {
                if (it != lst.begin()) it = lst.erase(--it);
            } else if (c == '<') {
                if (it != lst.begin()) it--;
            } else if (c == '>') {
                if (it != lst.end()) it++;
            } else {
                lst.insert(it, c);
            }
        }
        for (auto it : lst) cout << it;
        cout << "\n";
    }
    return 0;
}