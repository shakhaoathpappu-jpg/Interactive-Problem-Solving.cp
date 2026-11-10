#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pre[200005];
int a[200005];

ll ask(int l, int r)
{
    cout << "? " << r - l + 1 << " ";
    for(int i = l; i <= r; i++) cout << i << (i == r ? '\n' : ' ');
    ll x; cin >> x;
    return x;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int l = 1, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            ll x = ask(l, mid);
            if(x == pre[mid] - pre[l - 1]) l = mid + 1;
            else r = mid;
        }
        cout << "! " << l << endl;
    }
}