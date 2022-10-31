#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,dp[2505][2505],w[2505],ans;
inline int read(){
	int res=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<1)+(res<<3)+(ch^'0');
		ch=getchar();
	} 
	return f?-res:res;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j)
				dp[i][j]=0x3f3f3f3f;
	for(int i=1;i<=m;++i){
		int u=read(),v=read(); 
		dp[u][v]=dp[v][u]=min(dp[u][v],1ll);
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int a=2;a<=n;++a)
		if(dp[1][a]-1<=k)
			for(int b=2;b<=n;++b)
				if(dp[a][b]-1<=k&&a!=b)
					for(int c=2;c<=n;++c)
						if(dp[b][c]-1<=k&&a!=c&&b!=c)
							for(int d=2;d<=n;++d)
								if(dp[c][d]-1<=k&&dp[d][1]-1<=k&&a!=d&&b!=d&&c!=d)
									ans=max(ans,w[a]+w[b]+w[c]+w[d]);
	printf("%lld\n",ans);
	return 0;
}
