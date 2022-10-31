#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
	putchar(k%10+'0');
}
ll n,q,k,cnt,first[200005],val[200005],dp[200005];
struct q1{
	ll u,w,nex;
}a[400005];
void add(ll u1,ll w1){
	a[++cnt].u=u1;
	a[cnt].w=w1;
	a[cnt].nex=first[u1];
	first[u1]=cnt;
}
bool dfs(int u,int w,int dad,int dad1,int dad2,int f){
	if(!f&&k==3)
		dp[u]=min(dp[dad],min(dp[dad1],dp[dad2]))+val[u];
	else if(!f&&k==2)
		dp[u]=min(dp[dad],dp[dad1])+val[u];
	else if(!f)
		dp[u]=dp[dad]+val[u];
	if(u==w)
		return 1;
	for(int i=first[u];i;i=a[i].nex){
		if(a[i].w==dad)
			continue;
		if(dfs(a[i].w,w,u,dad,dad1,0))
			return 1;
	}
	return 0;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();
	q=read();
	k=read();
	for(ll i=1;i<=n;i++){
		val[i]=read();
	}
	for(ll i=1,x,y;i<n;i++){
		x=read();
		y=read();
		add(x,y);
		add(y,x);
	}
	while(q--){
		memset(dp,127,sizeof(dp));
		int x,y;
		x=read();
		y=read();
		dp[x]=val[x];
		dfs(x,y,0,0,0,1);
		work(dp[y]);
		puts("");
	}
	return 0;
}
