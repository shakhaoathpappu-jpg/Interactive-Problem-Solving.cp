#include<bits/stdc++.h>
using namespace std;

int a[7], t[7];
int p[] = {4, 8, 15, 16, 23, 42};

int main()
{
    for(int i = 2; i <= 5; i++) {
        cout << "? 1 " << i << endl;
        cin >> t[i];
        if(i == 2) a[1] = t[i];
        else a[1] = __gcd(a[1], t[i]);
    }
    int x = -1;
    for(int i = 0; i < 6; i++) {
        if(a[1] % p[i] == 0)
            x = max(x, p[i]);
    }
    a[1] = x;
    for(int i = 2; i <= 5; i++) a[i] = t[i] / a[1];
    for(int i = 0; i < 6; i++) {
        if(!count(a + 1, a + 6, p[i])) {
            a[6] = p[i];
            break;
        }
    }
    cout << "!";
    for(int i = 1; i <= 6; i++) cout << " " << a[i];
    cout << endl;
}