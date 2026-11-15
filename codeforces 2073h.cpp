#include<bits/stdc++.h>
using namespace std;

int n;

int ask0(int i)
{
    char s[8];
    cout << "type " << i << endl;
    cout.flush();

    cin >> s;
    if(strcmp(s, "lily") == 0) return 0;
    else return 1;
}

int ask1(int i)
{
    cout << "multi " << i << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

int solve(int j, int x, int y)
{
    if(x == 0 && y == 0) return -1;
    int a = -1, b = -1;
    if(x >= y) a = x - y;
    else b = y - x;
    if(b == -1) b = x / a;
    if(a == -1) a = x / b;
    int xx = j - a;
    return xx + b;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int l = 0, r = n + 1;
        while(l + 1 < r) {
            int mid = (l + r) / 2;
            if(ask0(mid) == 0) r = mid;
            else l = mid;
        }
        int ans = -1;
        if(l == 0) {
            int x = solve(0, ask1(0), ask1(1));
            if(x == -1) ans = 0;
            else ans = x;
        }
        else if(r == n + 1) {
            int x = solve(n - 1, ask1(n - 1), ask1(n));
            if(x == -1) ans = n;
            else ans = x;
        }
        else {
            int x = ask1(l - 1);
            int y = ask1(l);
            int z = ask1(l + 1);
            if(x != 0 || y != 0) ans = solve(l - 1, x, y);
            else if(y != 0 || z != 0) ans = solve(l, y, z);
            else ans = l;
        }
        cout << "answer " << ans << endl;
        cout.flush();
    }
}