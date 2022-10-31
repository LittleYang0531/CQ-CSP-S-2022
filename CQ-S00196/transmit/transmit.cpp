#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,tot,x,y,h[2005];
long long a[2005],b[2005],f[2005];
struct node{int v,ne;}e[4005];
void add(int u,int v){e[++k].v=v,e[k].ne=h[u],h[u]=k;}
void dfs(int x,int r,int c){
	if(x==y){tot=c;return;}
	for(int i=h[x];i;i=e[i].ne)if(e[i].v!=r)b[c+1]=e[i].v,dfs(e[i].v,x,c+1);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	while(m--){
		scanf("%d%d",&x,&y),memset(f,0x3f3f3f3f,sizeof(f)),b[1]=x;
		dfs(x,0,1),f[tot]=a[y];
		for(int i=tot;i>=2;i--){
			f[i-1]=min(f[i-1],f[i]+a[b[i-1]]);
			if(t>=2&&i>=3)f[i-2]=min(f[i-2],f[i]+a[b[i-2]]);
			if(t>=3&&i>=4)f[i-3]=min(f[i-3],f[i]+a[b[i-3]]);
		}
		printf("%lld\n",f[1]);
	}
	return 0;
}
