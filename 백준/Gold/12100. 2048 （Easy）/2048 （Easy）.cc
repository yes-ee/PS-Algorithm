#include <iostream>
#include <vector>

using namespace std;

int n, ans = 2;

void init(int nv[20][20]) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++)
            nv[i][j] = 0;
    }
}

void bfs(int cnt, int v[20][20]) {
    if (cnt == 5) {
        // max 값 확인
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, v[i][j]);
            }
        }
        return;
    }

    int nv[20][20];

    init(nv);
    // 왼쪽으로 미는 경우
    for (int i = 0; i < n; i++) {
        int a = 0;
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0)
                continue;
            
            if (a == 0)
                a = v[i][j];
            else { // a 존재
                if (a != v[i][j]) { // 합쳐지지 x
                    nv[i][cur] = a;
                    a = v[i][j];
                } else { // 합쳐지는 경우
                    nv[i][cur] = a * 2;
                    a = 0;
                }
                cur++;
            }
        }
        if (a)
            nv[i][cur] = a;
    }
    bfs(cnt + 1, nv);

    init(nv);
    // 오른쪽으로 미는 경우
    for (int i = 0; i < n; i++) {
        int a = 0;
        int cur = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (v[i][j] == 0)
                continue;
            
            if (a == 0)
                a = v[i][j];
            else { // a 존재
                if (a != v[i][j]) { // 합쳐지지 x
                    nv[i][cur] = a;
                    a = v[i][j];
                } else { // 합쳐지는 경우
                    nv[i][cur] = a * 2;
                    a = 0;
                }
                cur--;
            }
        }
        if (a)
            nv[i][cur] = a;
    }
    bfs(cnt + 1, nv);

    init(nv);
    // 위로 미는 경우
    for (int i = 0; i < n; i++) {
        int a = 0;
        int cur = 0;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 0)
                continue;
            
            if (a == 0)
                a = v[j][i];
            else { // a 존재
                if (a != v[j][i]) { // 합쳐지지 x
                    nv[cur][i] = a;
                    a = v[j][i];
                } else { // 합쳐지는 경우
                    nv[cur][i] = a * 2;
                    a = 0;
                }
                cur++;
            }
        }
        if (a)
            nv[cur][i] = a;
    }
    bfs(cnt + 1, nv);

    init(nv);
    // 아래로 미는 경우
    for (int i = 0; i < n; i++) {
        int a = 0;
        int cur = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (v[j][i] == 0)
                continue;
            
            if (a == 0)
                a = v[j][i];
            else { // a 존재
                if (a != v[j][i]) { // 합쳐지지 x
                    nv[cur][i] = a;
                    a = v[j][i];
                } else { // 합쳐지는 경우
                    nv[cur][i] = a * 2;
                    a = 0;
                }
                cur--;
            }
        }
        if (a)
            nv[cur][i] = a;
    }
    bfs(cnt + 1, nv);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[20][20];
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    bfs(0, arr);

    cout << ans;

    return 0;
}