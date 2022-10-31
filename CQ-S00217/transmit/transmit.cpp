#include<bits/stdc++.h>
#define ll long long
#define N 500012
#define mkp make_pair
#define pb push_back
using namespace std;
ll read(){
	ll x=0,fl=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-')fl=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
	return x*fl;
}
int n,q,k,a[N];
int nxt[N],to[N],head[N],tot;
int pre[N],b[N],cnt;
ll f[N];

void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int u,int fa){
	pre[u]=fa;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u);
	}
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int u,v;
	for(int i=1;i<n;i++){
		u=read(),v=read();
		add(u,v); add(v,u);
	}
	while(q--){
		u=read(),v=read();
		dfs(u,0);
		cnt=0;
		while(v!=u){
			b[++cnt]=v;
			v=pre[v];
		}
		b[++cnt]=u;
		reverse(b+1,b+1+cnt);
		/*for(int i=1;i<=cnt;i++){
			cout<<b[i]<<" ";
		}
		cout<<"\n";*/
		for(int i=1;i<=cnt;i++) f[i]=1e18;
		f[1]=0;
		for(int i=2;i<=cnt;i++){
			for(int j=1;j<=k;j++){
				if(i-j>0) f[i]=min(f[i],f[i-j]+a[b[i-j]]);
			}
		}
		printf("%lld\n",f[cnt]+a[b[cnt]]);
	}
	
	return 0;
}
