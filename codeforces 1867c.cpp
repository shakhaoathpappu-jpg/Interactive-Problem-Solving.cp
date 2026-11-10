#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = n;
        for(int i = 1; i <= n; i++) {
            if(a[i] != i - 1) {
                ans = i - 1;
                break;
            }
        }
        cout << ans << endl;
        while(true) {
            int x; cin >> x;
            if(x == -1) break;
            cout << x << endl;
        }
    }
}