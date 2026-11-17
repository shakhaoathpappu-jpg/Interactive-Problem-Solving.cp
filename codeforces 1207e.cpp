#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

signed main() 
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << "?";
    for (int i = 1; i < 101; i++) {
        cout << " " << i;
    }
    cout << endl;
    int x, y; cin >> x;
    cout << "?";
    for (int i = 1; i < 101; i++) {
        cout << " " << (i << 7);
    }
    cout << endl;
    cin >> y;
    cout << "! " << ((y & ((1 << 7) - 1)) | (x & (((1 << 7) - 1) << 7))) << endl;
    return 0;
}