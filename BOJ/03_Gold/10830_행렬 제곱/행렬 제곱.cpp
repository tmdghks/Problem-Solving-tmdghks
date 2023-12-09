// 10830 행렬 제곱
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> v(5, vector<int>(5, 0));
vector<vector<int>> identity_mat(5, vector<int>(5, 0));

vector<vector<int>> time_mat(vector<vector<int>> v1, vector<vector<int>> v2) {
    vector<vector<int>> tmp(5, vector<int>(5, 0));
    int i, j, k;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                tmp[i][j] += v1[i][k] * v2[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }

    return tmp; 
}

vector<vector<int>> power_mat(vector<vector<int>> v, ll base) {
    if (base == 0) {
        return identity_mat;
    } else if (base == 1) {
        return v;
    } else if (base % 2 == 1) {
        return time_mat(power_mat(time_mat(v, v), base / 2), v);
    } else {
        return power_mat(time_mat(v, v), base / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int i, j;
    ll r, c, tmp;
    cin >> r >> c;

    vector<vector<int>> v(5, vector<int>(5, 0));
    for (i = 0; i < 5; i++) {
        identity_mat[i][i] = 1;
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            cin >> tmp;
            v[i][j] = tmp % 1000;
        }
    }

    vector<vector<int>> result = power_mat(v, c);

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}