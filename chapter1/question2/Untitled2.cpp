#include <bits/stdc++.h>

using namespace std;

// Ham xu ly xau ky tu
int String_process(string line) {
    string command;
    int k;

    stringstream ss(line);
    ss >> command >> k;

    return k;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;

    // Nhap cac phan tu vao vector
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    cin.ignore();

    while (1) {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        int val = String_process(s);

        auto it = upper_bound(v.begin(), v.end(), val);

        if (it != v.end())
            cout << *it << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
