#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, i, j, k;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> score(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int min_node = -1;
    int min_score = INT_MAX;

    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false);
        queue<int> q;

        int cnt = 0;
        q.push(i);
        visited[i] = true;

        k = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                int tmp = q.front();
                q.pop();

                for (auto s : g[tmp]) {
                    if (!visited[s]) {
                        q.push(s);
                        visited[s] = true;
                        cnt += k;
                    }
                }
            }
            k++;
        }

        score[i] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        if (min_score > score[i]) {
            min_score = score[i];
            min_node = i;
        }
    }

    cout << min_node << '\n';
    return 0;
}