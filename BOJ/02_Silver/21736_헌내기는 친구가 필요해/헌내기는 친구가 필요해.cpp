#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int i, j;
    int n, m, p = 0, q = 0;
    cin >> n >> m;

    vector<vector<int>> v(m, vector<int>(n, 0));

    for (i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (j = 0; j < m; j++) {
            if (s[j] == 'P') {
                v[j][i] = 1;
            } else if (s[j] == 'I') {
                p = j;
                q = i;
            } else if (s[j] == 'X') {
                v[j][i] = -1;
            }
        }
    }

    queue<pair<int, int>> que;
    int cnt = 0;

    que.push(make_pair(p, q));
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;

        if (x < 0 || x >= m || y < 0 || y >= n || v[x][y] == -1) {
            que.pop();
            continue;
        }

        if (v[x][y] == 1) cnt++;

        v[x][y] = -1;

        que.push(make_pair(x - 1, y));
        que.push(make_pair(x + 1, y));
        que.push(make_pair(x, y - 1));
        que.push(make_pair(x, y + 1));
        que.pop();
    }

    if (cnt > 0)
        cout << cnt;
    else
        cout << "TT";
}