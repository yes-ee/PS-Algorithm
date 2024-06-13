#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int m, s, t;
string tm;
int wina, winb;
vector<pair<int, int>> v;

void print(int a) {
    if (a < 10) cout << "0";
    
    cout << a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> t >> tm;
        
        m = stoi(tm.substr(0, 2));
        s = stoi(tm.substr(3, 5));
        
        v.push_back({m * 60 + s, t});
    }
    v.push_back({48 * 60, 0});
    
    sort(v.begin(), v.end());
    
    int st = 0;
    int a = 0, b = 0;
    int pre = 0;
    
    for (pair<int, int> val : v) {
        int cnt = val.first - pre;
        pre = val.first;
        
        if (a > b) wina += cnt;
        else if (b > a) winb += cnt;
        
        // 골 넣은 팀 점수 올리기
        if (val.second == 1) a++;
        else if (val.second == 2) b++;
    }
    
    print(wina / 60);
    cout << ":";
    print(wina % 60);
    cout << "\n";
    print(winb / 60);
    cout << ":";
    print(winb % 60);
    
    return 0;
}