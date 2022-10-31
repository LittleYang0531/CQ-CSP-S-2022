#include<bits/stdc++.h>
using namespace std;
int n,m,q,k,x,y,z,v[200005],cnt,h[200005],To[400005],Nt[400005],d[200005],f[200005][30];
long long dis[200005],ans;
void ae(int x,int y){
	cnt++;
	To[cnt]=y;
	Nt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int x,int fa){
	d[x]=d[fa]+1;
	dis[x]=dis[fa]+v[x];
	for(int i=h[x];i;i=Nt[i]){
		int j=To[i];
		if(j!=fa){
			f[j][0]=x;
			dfs(j,x);
		}
	}
}
int lca(int a,int b){
	if(d[a]<d[b]){
		swap(a,b);
	}
	for(int i=m;i>=0;i--){
		if(d[f[a][i]]>=d[b]){
			a=f[a][i];
		}
	}
	if(a==b){
		return a;
	}
	for(int i=m;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i];
			b=f[b][i];
		}
	}
	return f[a][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	m=log2(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		ae(x,y);
		ae(y,x);
	}
	dfs(1,0);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		ans=dis[x]+dis[y]-(dis[z]<<1)+v[z];
		printf("%lld\n",ans);
	}
	return 0;
}
