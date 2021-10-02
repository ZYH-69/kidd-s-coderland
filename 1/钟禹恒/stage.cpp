#include<bits/stdc++.h>
#pragma GCC optizine(2)
using namespace std;
int t;
typedef long long ll;
ll a,b,x,y;
int main()
{
//	freopen("stage.in","r",stdin);
//	freopen("stage.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>x>>y;
		ll ans=0;
		ll j=1;
		if(b<x)
		{
			if(x%b!=0) j=x/b+1;
			else j=x/b;
		}
		while(1)
		{
			ll l=j*a,r=j*b,lx=(j+1)*a;
			if(l>y) break;
			if(lx<r+1)
			{
				ans+=y-max(x,l)+1;
				break;
			}
			else ans+=min(y,r)-max(x,l)+1;
			j++;
		}
		cout<<ans;
	}
	return 0;
}
