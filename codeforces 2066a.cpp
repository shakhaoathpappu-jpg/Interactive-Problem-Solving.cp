#include<bits/stdc++.h>
using namespace std;

int n, x[200011], id[200011];

int ask(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
            id[i] = 0;
        }
        for(int i = 1; i <= n; i++) id[x[i]] = i;
        bool ok = false;
        for(int i = 1; i <= n; i++) {
            if(!id[i]) {
                ok = true;
                if(!ask(i, i % n + 1)) cout << "! A" << endl;
                else cout << "! B" << endl;
                break;
            }
        }
        if(ok) continue;
        int a = ask(id[1], id[n]);
        int b = ask(id[n], id[1]);
        if(a >= n || b >= n || (a == n - 1 && b == n - 1)) cout << "! B" << endl;
        else cout << "! A" << endl;
    }
}