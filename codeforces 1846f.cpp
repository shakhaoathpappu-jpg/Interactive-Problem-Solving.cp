#include<bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() 
{
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int t; cin >> t;

    auto solve = [&]() {
        int n; cin >> n;

        auto read = [&]() {
            vector<int> a(n);
            map<int, int> cnt;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
                cnt[a[i]]++;
            }
            return pair(a, cnt);
        };

        auto [a, cnt] = read();

        vector<int> bad;
        int diff = -1;

        for (int i = 0; i < 5; i++) {
            if (n - int(bad.size()) == 1) {
                cout << "! " << diff + 1 << endl;
                return;
            }

            cout << "- " << bad.size();
            for (int i = 0; i < int(bad.size()); i++) {
                cout << ' ' << bad[i] + 1;
            }
            cout << endl;

            n -= bad.size();
            bad.clear();
            
            auto [na, ncnt] = read();

            int col = -1;
            
            for (auto [x, y] : ncnt) {
                if (y > cnt[x]) {
                    col = x;
                }
            }

            if (col != -1) {
                for (int i = 0; i < n; i++) {
                    if (na[i] != col) {
                        bad.push_back(i);
                    } else {
                        diff = i;
                    }
                }
                ncnt = {{col, ncnt[col]}};
            }

            swap(na, a);
            swap(ncnt, cnt);
        }
    };

    while (t--) {
        solve();
    }
    
    return 0;
}
