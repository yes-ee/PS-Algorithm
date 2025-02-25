#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
queue<int> q;
string cmd;
int num;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            q.push(num);
            continue;
        } else if (cmd == "pop") {
            if (!q.empty()) {
                cout << q.front();
                q.pop();
            }
            else cout << -1;
        } else if (cmd == "size") {
            cout << q.size();
        } else if (cmd == "empty") {
            if (q.empty()) cout << 1;
            else cout << 0;
        } else if (cmd == "front") {
            if (!q.empty()) cout << q.front();
            else cout << -1;
        } else if (cmd == "back") {
            if (!q.empty()) cout << q.back();
            else cout << -1;
        }
        cout << "\n";
    }

    return 0;
}