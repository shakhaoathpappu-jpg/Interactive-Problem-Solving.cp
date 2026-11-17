#include<bits/stdc++.h>
using namespace std;
const int N = 50010;
const int THRE = 1010;
int a[N], nxt[N];

void ask(int i)
{
    cout << "? " << i + 1 << endl;
    cout.flush();

    cin >> a[i] >> nxt[i];
    if(nxt[i] > 0) nxt[i]--;
}

int randint(int n)
{
    return (1LL * rand() << 15 | rand()) % n;
}

int main()
{
    srand(time(NULL));
    int n, st, x; cin >> n >> st >> x;
    st--;
    int mx = 0;
    for(int i = 0; i < THRE; i++) {
        int id = randint(n);
        ask(id);
        if(a[id] < x && a[id] > mx) {
            st = id;
            mx = a[id];
        }
    }
    while(st != -1) {
        ask(st);
        if(a[st] >= x) {
            cout << "! " << a[st] << endl;
            cout.flush();
            return 0;
        }
        st = nxt[st];
    }
    cout << "! -1" << endl;
    cout.flush();
    return 0;
}