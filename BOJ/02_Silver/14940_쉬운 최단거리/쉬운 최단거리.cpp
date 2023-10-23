// 14940 쉬운 최단거리

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int i, j;
    int n, m, p = 0, q = 0;
    cin >> n >> m;

    vector<vector<int>> v(m, vector<int>(n, 0));
    vector<vector<int>> dis(m, vector<int>(n, -1));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> v[j][i];
            if (v[j][i] == 2) {
                p = j;
                q = i;
            } else if (v[j][i] == 0) {
                dis[j][i] = 0;
            }
        }
    }

    queue<pair<pair<int, int>, int>> que;

    que.push(make_pair(make_pair(p, q), 0));
    while (!que.empty()) {
        int depth = que.front().second;
        int x = que.front().first.first;
        int y = que.front().first.second;

        if (x < 0 || x >= m || y < 0 || y >= n || v[x][y] == 0 || dis[x][y] > 0) {
            que.pop();
            continue;
        }

        dis[x][y] = depth;
        que.push(make_pair(make_pair(x - 1, y), depth + 1));
        que.push(make_pair(make_pair(x + 1, y), depth + 1));
        que.push(make_pair(make_pair(x, y + 1), depth + 1));
        que.push(make_pair(make_pair(x, y - 1), depth + 1));
        que.pop();
    }

    dis[p][q] = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << dis[j][i] << ' ';
        }
        cout << '\n';
    }
}