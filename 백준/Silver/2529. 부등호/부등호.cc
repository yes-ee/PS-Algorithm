#include <iostream>
#include <vector>

using namespace std;

int visited[10];
int k;
char input[10];
vector<int> ans;
int fin;

void dfs_min(int cnt) {
    if (fin) return;
    if (cnt == k) {
        fin = 1;
        for (auto i : ans) cout << i;
        return;
    }

    int x = ans[cnt];
    int up = (input[cnt] == '<' ? 1 : 0);

    if (up) {
        for (int i = x+1; i <= 9; i++) {
            if (visited[i]) continue;
            visited[i]=1;
            ans.push_back(i);
            dfs_min(cnt+1);
            ans.pop_back();
            visited[i]=0;
        }
    } else {
        for (int i = 0; i < x; i++) {
            if (visited[i]) continue;
            visited[i]=1;
            ans.push_back(i);
            dfs_min(cnt+1);
            ans.pop_back();
            visited[i]=0;
        }
    }

    return;
}

void dfs_max(int cnt) {
    if (fin) return;
    if (cnt == k) {
        fin = 1;
        for (auto i : ans) cout << i;
        return;
    }

    int x = ans[cnt];
    int up = (input[cnt] == '<' ? 1 : 0);

    if (up) {
        for (int i = 9; i > x; i--) {
            if (visited[i]) continue;
            visited[i]=1;
            ans.push_back(i);
            dfs_max(cnt+1);
            ans.pop_back();
            visited[i]=0;
        }
    } else {
        for (int i = x-1; i >= 0; i--) {
            if (visited[i]) continue;
            visited[i]=1;
            ans.push_back(i);
            dfs_max(cnt+1);
            ans.pop_back();
            visited[i]=0;
        }
    }

    return;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for (int i = 0; i < k; i++) cin >> input[i];

    // get max number
    for (int i=9; i >=0; i--) {
        visited[i] = 1;
        ans.push_back(i);
        dfs_max(0);
        visited[i] =0;
        ans.pop_back();
    }

    cout << "\n";
    fin=0;
    for (int i=0; i <10; i++) visited[i]=0;

    // get min number
    for (int i=0; i <10; i++) {
        visited[i] = 1;
        ans.push_back(i);
        dfs_min(0);
        visited[i] =0;
        ans.pop_back();
    }
}
