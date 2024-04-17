#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 39, 102};
    int target = 40;
    int left = 0;
    int right = v.size() - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (v[mid] == target) {
            cout << "Target found at index " << mid << '\n';
            return 0;
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Target not found" << '\n';
    return 0;
}