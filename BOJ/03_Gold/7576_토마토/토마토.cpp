#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct info {
    int x;
    int y;
    int depth;
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int i, j, m, n;
    cin >> m >> n;
    int x, y, dep, max = 0;

    vector<vector<int>> g(m, vector<int>(n, 0));
    queue<info> que;

    for (j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                que.push({i, j, 0});
            }
        }
    }

    while (!que.empty()) {
        x = que.front().x;
        y = que.front().y;
        dep = que.front().depth;

        if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] == -1 || g[x][y] == 2) {
            que.pop();
            continue;
        }

        g[x][y] = 2;

        if (max < dep) max = dep;

        que.push({x + 1, y, dep + 1});
        que.push({x - 1, y, dep + 1});
        que.push({x, y + 1, dep + 1});
        que.push({x, y - 1, dep + 1});
        que.pop();
    }

    bool f = true;

    for(j = 0; j < n; j++) {
        for (i = 0; i < m; i++) {
            if (g[i][j] == 0) {
                f = false;
                break;
            }
        }
            if (!f) break;
    }

    if (f) cout << max;
    else cout << -1;
}