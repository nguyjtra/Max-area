#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int a[500][500];
void check(int n, int m, int i, int j, int& p) {
    a[i][j] = 0;
    for (int u = 0; u < 4; u++) {
        int idx = i + dx[u];
        int idy = j + dy[u];
        if (idx >= 0 && idx < n && idy >= 0 && idy < m && a[idx][idy] == 1) {
            p++;
            check(n, m, idx, idy, p);
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int p = 1;
    int k = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                check(n, m, i, j, p);
                k = max(k, p);
                p = 1;

            }
        }
    }
    cout << k;

    return 0;
}
