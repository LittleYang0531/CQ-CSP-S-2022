#include<bits/stdc++.h>
using namespace std;
long long n,q,k,v[200005],a,b,s,t,ans,vis[200005],head[400005],nxt[400005],to[400005],tot;
void add(long long u,long long v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void f(long long x,long long y,long long K,long long S,long long o){
	if(S>=ans&&ans!=-1) return;
	if(x==y&&o==1){
		if(ans==-1) ans=S;
		else ans=min(ans,S);
		return;
	}
	if(K==0) return;
	for(int i=head[x];i;i=nxt[i]){
		if(!vis[to[i]]){
			vis[to[i]]=1;
			f(to[i],y,K-1,S,0);
			f(to[i],y,K,S+v[to[i]],1);
			vis[to[i]]=0;
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<n;i++){
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		ans=-1;
		vis[s]=1;
		f(s,t,k,v[s],1);
		cout<<ans<<endl;
		vis[s]=0;
	}
	return 0;
}
