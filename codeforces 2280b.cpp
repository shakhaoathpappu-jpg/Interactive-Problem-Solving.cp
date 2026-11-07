#include<bits/stdc++.h>
using namespace std;

int ask(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    if(x == -1) exit(0);
    return x;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int c = ask(1, n);
        bool ok = false;
        if(c != 0) {
            int d = ask(1, c);
            if(d != c) ok = true;
        }
        if(ok) cout << "! YES" << endl;
        else cout << "! NO" << endl;
    }
}