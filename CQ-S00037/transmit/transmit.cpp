#include <bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int f[200005][21],dep[200005],lg[200005];
int Val[200005];
int v[200005][4];
ll dis[200005];
vector <int> G[200005];
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+Val[u];
	dep[u]=dep[fa]+1; f[u][0]=fa;
	for(int i=1;i<=lg[dep[u]];i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lg[dep[x]];~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=lg[dep[x]];~i;i--)
	{
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
ll Dis(int x,int y)
{
	int Anc=LCA(x,y);
	return dis[x]+dis[y]-dis[Anc]-dis[f[Anc][0]];
}
int rt,ex;
ll F[200005][4];
void dfs2(int u,int fa,int Dep)
{
	if(Dep==3) return;
	v[rt][Dep]=min(v[rt][Dep],Val[u]);
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa||v==ex) continue;
		dfs2(v,u,Dep+1);
	}
} 
int S1[200005],S2[200005],cnt1,cnt2;
ll dp[200005];
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,k,q;
	read(n);read(q);read(k);
//	cerr<<n<<" "<<k<<" "<<q<<endl;
	for(int i=1;i<=n;i++) read(Val[i]),lg[i]=lg[i>>1]+1;
	for(int i=1,u,v;i<n;i++)
	{
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	if(k==1)
	{
		while(q--)
		{
			int x,y;
			read(x);read(y);
			printf("%lld\n",Dis(x,y));
		}
		return 0;
	}
	else if(k==2)
	{
		int x,y;
		while(q--)
		{
			read(x);read(y);
			int Anc=LCA(x,y);
			int Tmp=x;
			cnt1=cnt2=0;
			while(Tmp!=Anc)
			{
				S1[++cnt1]=Tmp;
				Tmp=f[Tmp][0];
			}
			Tmp=y;
			while(Tmp!=Anc)
			{
				S2[++cnt2]=Tmp;
				Tmp=f[Tmp][0];
			}
			S1[++cnt1]=Anc;
			for(int i=cnt2;i>=1;i--) S1[++cnt1]=S2[i];
			dp[1]=Val[S1[1]];
			for(int i=2;i<=cnt1;i++)
			{
				dp[i]=1e18;
				for(int j=1;j<=k&&j<=i-1;j++) dp[i]=min(dp[i],dp[i-j]+Val[S1[i]]);
			}
			printf("%lld\n",dp[cnt1]);
		}
	}
	else
	{
		int x,y;
		while(q--)
		{
			read(x);read(y);
			int Anc=LCA(x,y);
			int Tmp=x;
			cnt1=cnt2=0;
			while(Tmp!=Anc)
			{
				S1[++cnt1]=Tmp;
				Tmp=f[Tmp][0];
			}
			Tmp=y;
			while(Tmp!=Anc)
			{
				S2[++cnt2]=Tmp;
				Tmp=f[Tmp][0];
			}
			S1[++cnt1]=Anc;
			for(int i=cnt2;i>=1;i--) S1[++cnt1]=S2[i];
			for(int i=1;i<=cnt1;i++)
			{
				rt=S1[i];
				ex=S1[i-1];
				v[S1[i]][0]=v[S1[i]][1]=v[S1[i]][2]=1e9;
				dfs2(S1[i],S1[i+1],0);
				ex=0;
//				cerr<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
			}
			F[1][0]=Val[S1[1]];F[1][1]=F[1][2]=1e18;
			for(int i=2;i<=cnt1;i++)
			{
				F[i][0]=F[i][1]=F[i][2]=1e18;
				for(int j=0;j<=1;j++)
				{
					for(int K=1;K<=i-1&&K<=k;K++)
					{
						for(int l=0;l<=1;l++)
						{
							if(j+K+l>k) break;
							F[i][j]=min(F[i][j],F[i-K][l]+v[S1[i]][j]);
						}
					}
				}
			}
			printf("%lld\n",min(F[cnt1][0],F[cnt1][1]+Val[S1[cnt1]]));
		} 
	}
	return 0;
}
/*
清夜无尘，月色如银，酒斟时，须满十分；浮名浮利，虚苦劳神，叹隙中驹，石中火，梦中身。
虽抱文章，开口谁亲，且陶陶，乐尽天真；几时归去，作个闲人，对一张琴，一壶酒，一溪云。
*/

