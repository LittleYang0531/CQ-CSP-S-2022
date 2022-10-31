#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
} 
const int N=1e5+10;
int to[N<<1],net[N<<1],hed[N],cnt,dp[N],val[N];
void add(int x,int y){
	to[++cnt]=y,net[cnt]=hed[x],hed[x]=cnt;
}
void dfs(int x,int f,int k){
	for(int i=hed[x];i;i=net[i]){
		int y=to[i];
		if(y==f)continue;
		if(!dp[y])dp[y]=dp[x]+val[y];
		else dp[y]=min(dp[y],dp[x]+dp[y]);
		dfs(y,x);
	}
}
void solve1(int n,int q,int k){
	while(q--){
		int x=read(),y=read();
		for(int i=1;i<=n;i++)dp[n]=0;
		dp[x]=val[x];
		dfs(x,0,k);
		printf("%lld\n",dp[y]);
	}
}

signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++){
		val[i]=read();
	}
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
//	if(n<=200&&q<=200){
		solve1(n,q,k);
//	}
	return 0;
}
