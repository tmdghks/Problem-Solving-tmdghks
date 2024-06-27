#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

struct dt {
    ll x;
    ll y;
    ll depth;
};

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

int main() {
    int N, M;
    cin >> N >> M;

    vvll graph(N, vll(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0, length = str.size(); j < length; ++j) {
            graph[i][j] = str[j] - '0';
        }
    }

    if (graph[0][0] != 1 || graph[N - 1][M - 1] != 1) {
        cout << -1;
        return 0;
    }

    queue<dt> que;
    que.push({0, 0, 1});
    visited[0][0] = true;

    while (!que.empty()) {
        auto [x, y, depth] = que.front();
        que.pop();

        if (x == N - 1 && y == M - 1) {
            cout << depth;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && graph[nx][ny] == 1) {
                que.push({nx, ny, depth + 1});
                visited[nx][ny] = true;
            }
        }
    }

    cout << -1;
    return 0;
}
