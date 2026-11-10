#include<bits/stdc++.h>
using namespace std;

int ask(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    int r; cin >> r;
    if(r == -1) exit(0);
    return r;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(ask(1, 2) == 1) {
            cout << "! 1" << endl;
            continue;
        }
        if(ask(2, 3) == 1) {
            cout << "! 2" << endl;
            continue;
        }
        if(ask(1, 3) == 1) {
            cout << "! 1" << endl;
            continue;
        }
        bool ok = false;
        for(int i = 4; i <= 2 * n - 2; i += 2) {
            if(ask(i, i + 1) == 1) {
                cout << "! " << i << endl;
                ok = true;
                break;
            }
        }
        if(!ok) cout << "! " << 2 * n << endl;
    }
}