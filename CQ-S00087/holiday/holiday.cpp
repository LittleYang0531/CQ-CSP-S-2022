#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
using ll=long long;
const int Maxn=2505;
int dis[Maxn][Maxn];
ll s[Maxn];
ll f[Maxn][5];
ll g[Maxn][5][5];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m,k;cin>>n>>m>>k;
	for(int i=2;i<=n;++i)cin>>s[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int x,y;cin>>x>>y;
		dis[x][y]=dis[y][x]=1;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)if(i!=k)
			for(int j=1;j<=n;++j)if(i!=j&&j!=k)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	ll ans=0;
	if(n<=20){
		for(int a=2;a<=n;++a)if(dis[1][a]<=k+1)
			for(int b=2;b<=n;++b)if(a!=b&&dis[a][b]<=k+1)
				for(int c=2;c<=n;++c)if(a!=c&&b!=c&&dis[b][c]<=k+1)
					for(int d=2;d<=n;++d)if(a!=d&&b!=d&&c!=d&&dis[c][d]<=k+1)
						if(dis[d][1]<=k+1)ans=max(ans,s[a]+s[b]+s[c]+s[d]);
		cout<<ans<<'\n';
		return 0;
	}
	memset(f,0xcf,sizeof f);
	for(int i=2;i<=n;++i)if(dis[1][i]<=k+1)f[i][1]=s[i];
	for(int i=2;i<=4;++i)
		for(int a=2;a<=n;++a)
			for(int b=2;b<=n;++b)if(a!=b&&dis[a][b]<=k+1){
				if(f[a][i]>=f[b][i-1]+s[a])continue;
				bool fl=true;
				for(int j=1;j<i;++j)
					if(g[b][i-1][j]==a){fl=false;break;}
				if(!fl)continue;
				f[a][i]=f[b][i-1]+s[a];
				for(int j=1;j<i;++j)g[a][i][j]=g[b][i-1][j];
				g[a][i][i]=b;
			}
	for(int i=2;i<=n;++i)if(dis[1][i]<=k+1)
		ans=max(ans,f[i][4]);
	cout<<ans<<'\n';
	return 0;
}
