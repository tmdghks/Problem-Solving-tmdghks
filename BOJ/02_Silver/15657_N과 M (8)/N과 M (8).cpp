// BOJ 15657 N과 M (8)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfs(int depth, int n, int m, int max, vector<int> v, vector<int> num_vec) {
    if (depth == m) {
        for (auto num : v) {
            cout << num << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = max; i < n; i++) {
        v.push_back(num_vec[i]);
        dfs(depth + 1, n, m, i, v, num_vec);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> num_vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num_vec[i];
    }

    stable_sort(num_vec.begin(), num_vec.end());
    vector<int> v;

    dfs(0, n, m, 0, v, num_vec);
}