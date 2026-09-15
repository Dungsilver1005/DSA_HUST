#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;

    vector<long long> v;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    int cnt = 0;

    long long l = 0;
    long long r = n - 1;

    while (l < r) {
        long long tmp = v[l] + v[r];

        if (tmp == q) {
            cnt++;
            l++;
            r--;
        }
        else if (tmp < q) {
            l++;
        }
        else {
            r--;
        }
    }

    cout << cnt << endl;

    return 0;
}
