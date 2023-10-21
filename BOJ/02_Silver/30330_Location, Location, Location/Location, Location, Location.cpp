#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n, 0);
    vector<int> y(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    stable_sort(x.begin(), x.end());
    stable_sort(y.begin(), y.end());

    if (n % 2 == 1)
        cout << x[(n - 1) / 2] << " " << y[(n - 1) / 2];
    else
        cout << x[(n - 1) / 2] << " " << y[(n - 1) / 2];
}