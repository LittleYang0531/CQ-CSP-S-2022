#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,Q,K,dep[200005],f[19][200005],G[19][200005],a[200005],dis[200005],t1,t2,cnt,head[200005],nxt[400005],txt[400005];
struct ok{
	int d,z;
	bool operator < (const ok &A) const{
		return z>A.z;
	}
};
vector<ok> e[200005];
priority_queue<ok> q;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	int O=0;char f[20];
	if(x<0) x=-x,putchar('-');
	if(!x) {putchar('0');return;}
	while(x) f[++O]=x%10,x/=10;
	while(O) putchar(f[O--]+'0');
}
inline void dfs(int k,int F){
	dep[k]=dep[F]+1;
	f[0][k]=F;G[0][k]=a[k];
	for(int i=head[k];i;i=nxt[i]){
		if(txt[i]==F) continue;
		dfs(txt[i],k);
	}
}
inline int LCA(int x,int y){
	int t=18;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		if(dep[f[t][x]]<dep[y]) t--;
		else x=f[t][x];
	}
	if(x==y) return x;
	t=18;
	while(x!=y){
		if(f[t][x]==f[t][y]) t--;
		else x=f[t][x],y=f[t][y];
		if(t<0) break;
	}
	return f[0][x];
}
inline int LCAs(int x,int y){
	int t=18,tot=0;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		if(dep[f[t][x]]<dep[y]) t--;
		else tot+=G[t][x],x=f[t][x];
	}
	if(x==y) return tot+a[y];
	t=18;
	while(x!=y){
		if(f[t][x]==f[t][y]) t--;
		else tot+=G[t][x],tot+=G[t][y],x=f[t][x],y=f[t][y];
		if(t<0) break;
	}
	return tot+G[0][x]+G[0][y]+a[f[0][x]];
}
inline int solve(int x,int y){
	for(int i=1;i<=n;i++) dis[i]=1e15;
	dis[x]=0;
	q.push((ok){x,dis[x]});
	while(!q.empty()){
		ok t=q.top();q.pop();
		if(t.z>dis[t.d]) continue;
		int sz=e[t.d].size()-1;
		for(int i=0;i<=sz;i++){
			int v=e[t.d][i].d,z=e[t.d][i].z;
			if((dis[t.d]+z)<dis[v]){
				dis[v]=dis[t.d]+z;
				q.push((ok){v,dis[v]});
			}
		}
	}
	return dis[y]+a[x];
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),Q=read(),K=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<n;i++){
		t1=read(),t2=read();
		nxt[++cnt]=head[t1],head[t1]=cnt,txt[cnt]=t2;
		nxt[++cnt]=head[t2],head[t2]=cnt,txt[cnt]=t1;
	}
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			G[i][j]=G[i-1][j]+G[i-1][f[i-1][j]];
			f[i][j]=f[i-1][f[i-1][j]];
		}
	}
	if(K==1){
		for(int i=1;i<=Q;i++){
			t1=read(),t2=read();
			write(LCAs(t1,t2));
			putchar('\n');
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int d=LCA(i,j);
			int s=abs(dep[i]-dep[d])+abs(dep[j]-dep[d]);
			if(s<=K){
				e[i].push_back((ok){j,a[j]});
			}
		}
	}
	for(int i=1;i<=Q;i++){
		t1=read(),t2=read();
		write(solve(t1,t2));
		putchar('\n');
	}
	return 0;
}

