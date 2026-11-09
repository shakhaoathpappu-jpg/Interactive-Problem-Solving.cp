#include<bits/stdc++.h>
using namespace std;

int ask(int wh, int l, int r)
{
    cout << wh << " " << l << " " << r << endl;
    int res; cin >> res;
    return res;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int len = ask(2, 1, n) - n * (n + 1) / 2;
        int l = 1, r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(ask(1, 1, mid) != ask(2, 1, mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << "! " << l << " " << l + len - 1 << endl;
    }
}