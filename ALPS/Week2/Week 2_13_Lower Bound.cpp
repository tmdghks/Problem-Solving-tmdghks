#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 39, 102};
    int target = 40;
    int lowerBoundIndex = -1;
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] >= target) {
            lowerBoundIndex = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (lowerBoundIndex != -1) {
        cout << "Lower bound index: " << lowerBoundIndex << '\n';
        cout << "Lower bound value: " << v[lowerBoundIndex] << '\n';
    } else {
        cout << "Lower bound not found" << '\n';
    }
    return 0;
}
