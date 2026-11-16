#include<bits/stdc++.h>
using namespace std;

int n;

inline int ask (int l, int r) {
  cout << "? " << l << " " << r << endl;
  int p; cin >> p; return p;
}

int main() {
  cin >> n;
  int sec = ask(1, n);
  if (sec > 1 and ask(1, sec) == sec) {
    int lo = 1, hi = sec - 1;
    while (lo < hi) {
      int mid = lo + hi + 1 >> 1;
      if (ask(mid, sec) == sec) lo = mid;
      else hi = mid - 1;
    }
    cout << "! " << lo << endl;
    return 0;
  }
  int lo = sec + 1, hi = n;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ask(sec, mid) == sec) hi = mid;
    else lo = mid + 1;
  }
  cout << "! " << lo << endl;
  return 0;
}

