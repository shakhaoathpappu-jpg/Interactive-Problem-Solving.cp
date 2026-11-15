#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, s, q;
ll weight[1002];
ll arr[32];
vector<pair<ll, int> > vecA, vecB;

ll rnd(){
    return rand()+1;
}

int main(){
    scanf("%d %d %d", &n, &s, &q);
    for(int i=1; i<=n; i++){
        weight[i] = rnd()*rnd()*rnd()*rnd()*rnd();
    }
    for(int i=1; i<=s; i++){
        int cnt = 0;
        scanf("%d", &cnt);
        while(cnt--){
            int x;
            scanf("%d", &x);
            arr[i] ^= weight[x];
        }
    }
    int sh = min(13, s/2);
    for(int d=0; d<(1<<sh); d++){
        ll w = 0;
        for(int i=0; i<sh; i++){
            if((d>>i) & 1) w ^= arr[i+1];
        }
        vecA.push_back(make_pair(w, __builtin_popcount(d)));
    }
    for(int d=0; d<(1<<(s-sh)); d++){
        ll w = 0;
        for(int i=0; i<s-sh; i++){
            if((d>>i) & 1) w ^= arr[i+sh+1];
        }
        vecB.push_back(make_pair(w, __builtin_popcount(d)));
    }
    sort(vecB.begin(), vecB.end());
    for(int i=(int)vecB.size()-1; i>=0; i--){
        if(i<(int)vecB.size()-1 && vecB[i].first == vecB[i+1].first){
            vecB[i].second = min(vecB[i].second, vecB[i+1].second);
        }
    }
    while(q--){
        ll w = 0;
        int cnt;
        scanf("%d", &cnt);
        while(cnt--){
            int x;
            scanf("%d", &x);
            w ^= weight[x];
        }
        int ans = 100000;
        for(auto p: vecA){
            ll tmp = p.first ^ w;
            auto it = lower_bound(vecB.begin(), vecB.end(), make_pair(tmp, INT_MIN));
            if(it == vecB.end() || it->first != tmp) continue;
            ans = min(ans, it->second + p.second);
        }
        printf("%d\n", ans == 100000 ? -1 : ans);
    }
}
