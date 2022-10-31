#include<bits/stdc++.h>
using namespace std;
long long n,m,kk,a,b,ans,vis[2505],r[2505],vis1[2505],d[2505][2];
long long tot,head[20005],nxt[20005],to[20005],w[2505];
queue<long long> Q;
void add(long long u,long long v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void f(long long x,long long k,long long s,long long s1){
	if(k<0||s1>4) return;
	if(s1==4&&k>=r[x]){
		ans=max(ans,s);
		return;
	}
	if(k==0&&vis[x]&&s1<4) return;
	if((k<r[x]&&s1==4)||vis1[x]==s1+1) return;
	vis1[x]=s1+1;
	if(!vis[x]&&d[x][0]<=s){
		d[x][0]=s;
		d[x][1]=s1;
	}
	for(int i=head[x];i;i=nxt[i]){
		if(!vis[to[i]]&&(s>=d[x][0]||s1<=d[x][1])&&x!=1){
			vis[x]=1;
			f(to[i],kk,s+w[x],s1+1);
			vis[x]=0;
		}
		f(to[i],k-1,s,s1);
	}
	vis1[x]=0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>kk;kk++;
	for(int i=2;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	Q.push(1);
	vis[1]=1;
	while(!Q.empty()){
		long long t=Q.front();
		Q.pop();
		for(int i=head[t];i;i=nxt[i]){
			if(!vis[to[i]]){
				r[to[i]]=r[t]+1;
				vis[to[i]]=1;
				Q.push(to[i]);
			}
		}
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	f(1,kk,0,0);
	cout<<ans<<endl;
	return 0;
}
