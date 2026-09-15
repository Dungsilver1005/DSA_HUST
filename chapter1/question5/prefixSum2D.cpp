#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Dùng n+1, m+1 d? prefix[0][*] và prefix[*][0] = 0
    vector<vector<long long>> prefix(n + 1,
        vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long x;
            cin >> x;

            prefix[i][j] =
                prefix[i - 1][j]
                + prefix[i][j - 1]
                - prefix[i - 1][j - 1]
                + x;
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        long long ans =
            prefix[r2][c2]
            - prefix[r1 - 1][c2]
            - prefix[r2][c1 - 1]
            + prefix[r1 - 1][c1 - 1];

        cout << ans << '\n';
    }

    return 0;
}
