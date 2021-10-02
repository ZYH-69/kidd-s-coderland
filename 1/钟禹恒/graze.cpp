#include<bits/stdc++.h>
#pragma GCC optizine(2)
using namespace std;
int n,x,m;
int p[50001];
int a[50001];
bool check(int mid)
{
	a[1]=max(p[1]-mid,x);
	if(abs(p[1]-a[1])>mid) return 0;
	for(int i=2;i<=n;i++)
	{
		if(p[i]>=a[i-1]+2*x)
		{
			if(a[i-1]+3*x>m) return 0;
			a[i]=max(p[i]-mid,a[i-2*x]);
		}
		else if(a[i-1]+2*x-p[i]<=mid&&a[i-1]+3*x<m)
		{
			a[i]=a[i]+2*x;
		}
		else return 0;
	}
	return 1;
}
int main()
{
//	freopen("graze.in","r",stdin);
//	freopen("graze.out","w",stdout);
	cin>>n>>x>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	int l=1,r=m,mid,ans=-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		memset(a,0,sizeof(a));
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
