#include<bits/stdc++.h>
using namespace std;
int n,m;
int g[1001][1001];
int used[1001];
int ans=0x7fffff;
void dfs(int u,int sum)
{
	if(u==n)
	{
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[u][i]==-1) continue;
		if(used[i]==1) continue;
		used[i]=1;
		dfs(i,sum+g[u][i]);
		used[i]=0;
	}
}
int main()
{
	freopen("Back.in","r",stdin);
//	freopen("Back.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(g,-1,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		scanf("%d",&g[x][y]);
	}
	used[1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[i][j]==-1) continue;
			int temp=g[i][j];
			g[i][j]=0;
			dfs(1,0);
			g[i][j]=temp;
		}
	}
	cout<<ans;
	return 0;
}
