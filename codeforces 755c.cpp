#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0; cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x == i) ans++;
        else s.insert(x);
    }
    ans += s.size() / 2;
    cout << ans << endl;
}