#include<bits/stdc++.h>
using namespace std;
struct node
{
	int wall;
	char door;
	int tpx,tpy;
};
int n,m;
char cg[101][101];
node g[101][101];
int ans=-1;
int used[101][101];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
void dfs(int x,int y,int step)
{
//	cout<<x<<" "<<y<<" "<<step<<" "<<(x==n)<<" "<<(y==m)<<" "<<(x==n&&y==m)<<endl;
	if(x==n&&y==m)
	{
		if(ans==-1) ans=step;
		ans=min(ans,step);
		return;
	}
	for(int i=0;i<4;i++)
	{
		int vx=x+dx[i],vy=y+dy[i];
		if(vx<=0||vx>n||vy<=0||vy>m) continue;
		if(g[vx][vy].wall==1) continue;
		if(used[vx][vy]==1) continue;
		used[vx][vy]=1;
		if(g[vx][vy].door!=0)
		{
			used[g[vx][vy].tpx][g[vx][vy].tpy]=1;
			dfs(g[vx][vy].tpx,g[vx][vy].tpy,step+1);
			used[g[vx][vy].tpx][g[vx][vy].tpy]=1;
		}
		else dfs(vx,vy,step+1);
		used[vx][vy]=0;
	}
}
int main()
{
//	freopen("way.in","r",stdin);
//	freopen("way.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",cg[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(cg[i][j]=='0') continue;
			else if(cg[i][j]=='1') g[i][j].wall=1;
			else 
			{
				g[i][j].door=cg[i][j];
				for(int _i=1;_i<=n;_i++)
				{
					for(int _j=1;_j<=m;_j++)
					{
						if(_i==i&&_j==j) continue;
						if(cg[_i][_j]==g[i][j].door) 
						{
							g[i][j].tpx=_i;
							g[i][j].tpy=_j;
						}
						
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(g[i][j].door!=0) cout<<g[i][j].door;
//			else cout<<g[i][j].wall;
//		}
//		cout<<endl;
//	}
	dfs(1,1,0);	
	if(ans==-1)
	{
		cout<<"No Solution";
		return 0;
	}
	cout<<ans;
	return 0;
}
//3 4
//0000
//00A0
//A000
