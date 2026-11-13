#include<bits/stdc++.h>
using namespace std;

int n, a[610];

int ask(vector<int> v)
{
    cout << "? " << v.size() << " ";
    for(auto x : v) cout << x + 1 << " ";
    cout << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < 2 * n; i++) a[i] = -1;
        vector<int> v;
        for(int i = 0; i < 2 * n; i++) {
            v.push_back(i);
            int x = ask(v);
            if(x > 0) {
                a[i] = x;
                v.pop_back();
            }
        }
        v.clear();
        for(int i = 2 * n - 1; i >= 0; i--) {
            v.push_back(i);
            if(a[i] == -1) {
                a[i] = ask(v);
                v.pop_back();
            }
        }
        cout << "! ";
        for(int i = 0; i < 2 * n; i++) cout << a[i] << " ";
        cout << endl;
        cout.flush();
    }
}