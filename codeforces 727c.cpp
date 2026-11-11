#include<bits/stdc++.h>
using namespace std;

const int MAX=5e5+9;
int a[MAX],n,l,r;

int main()
{
    int n,x,y; cin>>n;
    for(int i=2;i<=n;i++)
	{
		cout<<"?"<<" "<<1<<" "<<i<<endl;
		cin>>a[i];
	}
	cout<<"?"<<" "<<2<<" "<<3<<endl;
	cin>>l;
	r=a[2]-l;
	r+=a[3];
	r/=2;
	cout<<"!"<<" "<<r<<" ";
	for(int i=2;i<=n;i++) cout<<a[i]-r<<" ";
}
