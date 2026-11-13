#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n, sx, sy; cin >> n >> sx >> sy;
        vector<int> x(n), y(n);
        vector<set<int>> a(2);
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            x[i] &= 1;
            y[i] &= 1;
        }
        sx &= 1;
        sy &= 1;
        for(int i = 0; i < n; i++)
            a[(sx + sy + x[i] + y[i]) % 2].insert(i + 1);

        if(a[0].size() >= a[1].size()) {
            cout << "First" << endl;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                    int q = (a[1].empty() ? 0 : 1);
                    auto it = a[q].begin();

                    cout << *it << endl;
                    a[q].erase(it);
                }
                else {
                    int id; cin >> id;
                    a[0].erase(id);
                    a[1].erase(id);
                }
            }
        }
        else {
            cout << "Second" << endl;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 1) {
                    int q = (a[0].empty() ? 1 : 0);
                    auto it = a[q].begin();
                    cout << *it << endl;
                    a[q].erase(it);
                }
                else {
                    int id; cin >> id;
                    a[0].erase(id);
                    a[1].erase(id);
                }
            }
        }
    }
}