#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
deque<int> dq;
string cmd;
int num;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> cmd;
        if (cmd == "push_back") {
            cin >> num;
            dq.push_back(num);
            continue;
        } else if (cmd == "push_front") {
            cin >> num;
            dq.push_front(num);
            continue;
        } else if (cmd == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
            }
            else cout << -1;
        } else if (cmd == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
            }
            else cout << -1;
        } else if (cmd == "size") {
            cout << dq.size();
        } else if (cmd == "empty") {
            if (dq.empty()) cout << 1;
            else cout << 0;
        } else if (cmd == "front") {
            if (!dq.empty()) cout << dq.front();
            else cout << -1;
        } else if (cmd == "back") {
            if (!dq.empty()) cout << dq.back();
            else cout << -1;
        }
        cout << "\n";
    }

    return 0;
}