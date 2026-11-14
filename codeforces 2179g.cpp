#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int n;
        cin >> n;
        auto query = [&](int i, int j) {
            cout << "? " << i + 1 << ' ' << j + 1 << endl;
            int res; cin >> res;
            return res;
        };
        vector<int> dis0(n * n), dis1(n * n), dis2(n * n);
        for (int i = 0; i < n * n; i++) {
            dis0[i] = query(0, i);
        }
        int s = max_element(dis0.begin(), dis0.end()) - dis0.begin();
        for (int i = 0; i < n * n; i++) {
            dis1[i] = query(s, i);
        }
        vector<int> cands;
        for (int i = 0; i < n * n; i++) {
            if (dis1[i] == n - 1) {
                cands.push_back(i);
            }
        }
        vector<int> dis;
        for (int &i : cands) {
            dis.push_back(query(i, cands[0]));
        }

        int t = cands[max_element(dis.begin(), dis.end()) - dis.begin()];
        for (int i = 0; i < n * n; i++) {
            dis2[i] = query(t, i);
        }
        vector b(n, vector<int>(n));
        for (int i = 0; i < n * n; i++) {
            int x = (dis1[i] - dis2[i] + n - 1) / 2;
            int y = (dis1[i] + dis2[i] - n + 1) / 2;
            b[x][y] = i;
        }
        assert(b[0][0] == s && b[n - 1][0] == t);
        cout << '!' << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << b[i][j] + 1 << " \n"[i + 1 == n];
            }
        }
        cout << flush;
    };
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
