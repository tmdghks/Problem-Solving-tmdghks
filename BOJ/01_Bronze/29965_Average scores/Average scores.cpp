#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using ld = long double;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    ll M = 0, J = 0, Mcnt = 0, Jcnt = 0;
    ll P;
    char input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        cin >> P;
        switch (input) {
            case 'M':
                M += P;
                Mcnt++;
                break;
            default:
                J += P;
                Jcnt++;
                break;
        }
    }

    if (Mcnt == 0 && Jcnt == 0) {
        cout << "V";
        return 0;
    } else if (Mcnt == 0) {
        if (J > 0) {
            cout << "J";
            return 0;
        } else {
            cout << "V";
            return 0;
        }
    } else if (Jcnt == 0) {
        if (M > 0) {
            cout << "M";
            return 0;
        } else {
            cout << "V";
            return 0;
        }
    }

    // cout << M << " " << J << endl;

    if (M / (ld)Mcnt > J / (ld)Jcnt) {
        cout << "M";
    } else if (M / (ld)Mcnt < J / (ld)Jcnt) {
        cout << "J";
    } else {
        cout << "V";
    }
}