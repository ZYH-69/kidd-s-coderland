#include<bits/stdc++.h>
#pragma GCC optizine(2)
using namespace std;
int n;
int a[20001];
bool b[20001];
int ans;
void dfs(int pos,int l,int ansnow)
{
	if(n-pos<l)
	{
		ans=max(ans,ansnow+a[pos]);
		return;
	}
	dfs(pos+l,l,ansnow+a[pos]);
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j+i+i>n) break;
			dfs(j,i,0);
		}
	}
	cout<<ans;
	return 0;
}
