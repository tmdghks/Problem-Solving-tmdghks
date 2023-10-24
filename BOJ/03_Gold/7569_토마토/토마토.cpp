// BOJ 7569 토마토
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct info {
    int x;
    int y;
    int z;
    int depth;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j, k;
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> g(m, vector<vector<int>>(n, vector<int>(h, 0)));
    queue<info> que;

    for (i = 0; i < h; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                cin >> g[k][j][i];
                if (g[k][j][i] == 1) {
                    que.push({k, j, i, 0});
                }
            }
        }
    }

    int ans = 0;

    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int z = que.front(). z;
        int depth = que.front().depth;

        if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= h || g[x][y][z] == -1 || g[x][y][z] == 2) {
            que.pop();
            continue;
        }

        g[x][y][z] = 2;
        que.push({x+1, y, z, depth+1});
        que.push({x-1, y, z, depth+1});
        que.push({x, y+1, z, depth+1});
        que.push({x, y-1, z, depth+1});
        que.push({x, y, z+1, depth+1});
        que.push({x, y, z-1, depth+1});
        
        if (ans < depth) ans = depth;

        que.pop();
    }

    bool f = false;
    for (i = 0; i < h; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (g[k][j][i] == 0) {
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f) break;
    }

    if (f) ans = -1;

    cout << ans;
}