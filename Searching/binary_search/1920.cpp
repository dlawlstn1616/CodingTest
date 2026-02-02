#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

static void binary_search(int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (v[mid] == target) {
            cout << 1 << "\n";
            return;
        }
        else if (v[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int target;
        cin >> target;
        binary_search(target);
    }

    return 0;
}