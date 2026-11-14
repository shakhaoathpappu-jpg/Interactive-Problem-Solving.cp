#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];

int main()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);reverse(a+1,a+1+n);
    int pos=0;
    for(int i=2;i<=n;i++){
        if(a[i]*i>m){
            pos=i;
            break;
        }
    }
    if(pos==0){
        cout<<"Alessia"<<endl;
        set<pair<int,int>>s;
        s.insert({m,1});
        for(int i=1;i<=n;i++){
            if(s.lower_bound({a[i],0})!=s.end()){
                auto cur=s.lower_bound({a[i],0});
                cout<<min(cur->first,a[i])<<" "<<cur->second<<endl;
                cin>>pos;
                s.insert({pos-cur->second,cur->second});
                s.insert({cur->first-(pos-cur->second)-1,pos+1});
                s.erase(cur);   
            }
            else{
                assert(0);
            }
        }
    }
    else{
        cout<<"Bernardo"<<endl;
        set<int>s;
        int len=a[pos];
        for(int i=len;i<=m;i+=len){
            s.insert(i);
        }
        for(int i=1;i<=n;i++){
            int len,pos; cin>>len>>pos;
            if(s.lower_bound(pos)!=s.end()){
                auto cur=s.lower_bound(pos);
                if(*cur<=len+pos-1)cout<<*cur<<endl;
                else cout<<pos<<endl;
            }
            else{
                cout<<pos<<endl;
            }

        }
    }
    
}