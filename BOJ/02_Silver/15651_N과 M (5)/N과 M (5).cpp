// BOJ 15650 N과 M (5)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int depth, int n, int m, vector<bool> v1, vector<int> v2, vector<int> num_vec) {
    if (depth == m) {
        for (auto num : v2) {
            cout << num << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (v1[i] == true) continue;

        v1[i] = true;
        v2.push_back(num_vec[i]);
        dfs(depth + 1, n, m, v1, v2, num_vec);
        v1[i] = false;
        v2.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> num_vec(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num_vec[i];
    }

    stable_sort(num_vec.begin(), num_vec.end());

    vector<bool> v1(n + 1, false);
    vector<int> v2;
    dfs(0, n, m, v1, v2, num_vec);
}