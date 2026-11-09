#include<bits/stdc++.h>
using namespace std;

int n, mx;
vector<int> q[510], p;

void work(int a, int b)
{
    int x;
    for(auto id : q[b]) {
        cout << "? " << a << " 2 " << a << " " << id << endl;
        cin >> x;
        if(x == 2) {
            p.push_back(id);
            return;
        }
    }
}

int main()
{
    int t, x; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) q[i].clear();

        p.clear();
        mx = 1;
        for(int i = 1; i <= n; i++) {
            cout << "? " << i << " " << n;
            for(int j = 1; j <= n; j++) cout << " " << j;
            cout << endl;
            cin >> x;
            q[x].push_back(i);
            mx = max(mx, x);
        }
        p.push_back(q[mx][0]);
        for(int i = mx - 1; i >= 1; i--) work(p.back(), i);
        cout << "! " << mx;

        for(auto id : p) cout << " " << id;
        cout << endl;
    }
}