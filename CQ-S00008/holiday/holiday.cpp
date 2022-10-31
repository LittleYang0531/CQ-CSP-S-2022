#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	register int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int dp[2501][4];
int s[2501];
int k,n,m;
int dis[2501][2501];
void solve1(){
	int ans=0;
	for(int i=2;i<=n;i++){
		if(dis[1][i]<=k){
			for(int j=2;j<=n;j++){
				if(i!=j&&dis[i][j]<=k){
					for(int p=2;p<=n;p++){
						if(p!=j&&p!=i&&dis[p][j]<=k){
							for(int q=2;q<=n;q++){
								if(q!=p&&q!=j&&q!=i&&dis[q][p]<=k&&dis[q][1]<=k){
									ans=max(ans,s[i]+s[j]+s[p]+s[q]);
								}
							}
						}
		
					}
				}
			}
		}
	}
	printf("%lld",ans);
}
int ans[2501];
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=2;i<=n;i++)s[i]=read();
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		dis[u][v]=dis[v][u]=1;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
				dis[i][j]--;
				else
				dis[i][j]=0;
			}
		}
		solve1();
		return 0;
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)
			dis[i][j]--;
			else
			dis[i][j]=0;
		}
	}
	solve1();
	return 0;
}
