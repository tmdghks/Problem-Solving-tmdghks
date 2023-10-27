#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, m, i, j;
    cin >> n >> m;

    vector<vector<int>> g(m, vector<int> (n, 0));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> g[j][i];
        }
    }

    int max = 0, tmp = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 3; j++) {
            tmp = g[j][i] + g[j + 1][i] + g[j + 2][i] + g[j + 3][i];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 3; i++) {
        for (j = 0; j < m; j++) {
            tmp = g[j][i] + g[j][i + 1] + g[j][i + 2] + g[j][i + 3];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 1; j++) {
            tmp = g[j][i] + g[j + 1][i] + g[j][i + 1] + g[j + 1][i + 1];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < m - 1; j++) {
            tmp = g[j][i] + g[j][i + 1] + g[j][i + 2] + g[j + 1][i + 2];
            if (tmp > max) max = tmp;
            tmp = g[j][i] + g[j][i + 1] + g[j][i + 2] + g[j + 1][i];
            if (tmp > max) max = tmp;
            tmp = g[j][i] + g[j + 1][i + 1] + g[j + 1][i + 2] + g[j + 1][i];
            if (tmp > max) max = tmp;
            tmp = g[j][i + 2] + g[j + 1][i + 1] + g[j + 1][i + 2] + g[j + 1][i];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 2; j++) {
            tmp = g[j][i] + g[j][i + 1] + g[j + 1][i] + g[j + 2][i];
            if (tmp > max) max = tmp;
            tmp = g[j][i] + g[j + 2][i + 1] + g[j + 1][i] + g[j + 2][i];
            if (tmp > max) max = tmp;
            tmp = g[j][i] + g[j][i + 1] + g[j + 1][i + 1] + g[j + 2][i + 1];
            if (tmp > max) max = tmp;
            tmp = g[j + 2][i] + g[j][i + 1] + g[j + 1][i + 1] + g[j + 2][i + 1];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < m - 1; j++) {
            tmp = g[j][i] + g[j][i + 1] + g[j + 1][i + 1] + g[j + 1][i + 2];
            if (tmp > max) max = tmp;
            tmp = g[j + 1][i] + g[j][i + 1] + g[j + 1][i + 1] + g[j][i + 2];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 2; j++) {
            tmp = g[j][i + 1] + g[j + 2][i] + g[j + 1][i + 1] + g[j + 1][i];
            if (tmp > max) max = tmp;
            tmp = g[j][i] + g[j + 1][i] + g[j + 1][i + 1] + g[j + 2][i + 1];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m - 2; j++) {
            tmp = g[j][i] + g[j + 1][i] + g[j + 2][i] + g[j + 1][i + 1];
            if (tmp > max) max = tmp;
            tmp = g[j][i + 1] + g[j + 1][i] + g[j + 2][i + 1] + g[j + 1][i + 1];
            if (tmp > max) max = tmp;
        }
    }

    for (i = 0; i < n - 2; i++) {
        for (j = 0; j < m - 1; j++) {
            tmp = g[j][i] + g[j][i + 1] + g[j][i + 2] + g[j + 1][i + 1];
            if (tmp > max) max = tmp;
            tmp = g[j + 1][i] + g[j][i + 1] + g[j + 1][i + 2] + g[j + 1][i + 1];
            if (tmp > max) max = tmp;
        }
    }

    cout << max;
}