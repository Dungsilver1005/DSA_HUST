#include <bits/stdc++.h>

using namespace std;

// Segment Tree
vector<int> tree;

// Xây cây
void build(const vector<int>& v, int node, int left, int right) {
    // N?u do?n ch? có 1 ph?n t?
    if (left == right) {
        tree[node] = v[left];
        return;
    }

    int mid = (left + right) / 2;

    // Xây cây con trái
    build(v, node * 2, left, mid);

    // Xây cây con ph?i
    build(v, node * 2 + 1, mid + 1, right);

    // Node hi?n t?i luu minimum c?a 2 node con
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

// Query minimum trên do?n [queryLeft, queryRight]
int query(int node, int left, int right, int queryLeft, int queryRight) {
    // Ðo?n hi?n t?i n?m hoàn toàn trong do?n c?n query
    if (queryLeft <= left && right <= queryRight) {
        return tree[node];
    }

    int mid = (left + right) / 2;

    int result = INT_MAX;

    // Có giao v?i cây con trái
    if (queryLeft <= mid) {
        result = min(result,
                     query(node * 2, left, mid, queryLeft, queryRight));
    }

    // Có giao v?i cây con ph?i
    if (queryRight > mid) {
        result = min(result,
                     query(node * 2 + 1, mid + 1, right,
                           queryLeft, queryRight));
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Segment Tree c?n kho?ng 4*n node
    tree.resize(4 * n);

    // Build
    build(v, 1, 0, n - 1);

    int m;
    cin >> m;

    long long result = 0;

    while (m--) {
        int i, j;
        cin >> i >> j;

        result += query(1, 0, n - 1, i, j);
    }

    cout << result << '\n';

    return 0;
}

