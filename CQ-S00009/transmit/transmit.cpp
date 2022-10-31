#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,k,v[N],v1[N];
int dep[N],fa[N];vector<int>E[N];
int L,p[N],L1,p1[N];ll f[N],f1[N];
void dfs(int x){
	v1[x]=1e9;
	for(auto y:E[x])
	if(y^fa[x]){
		dep[y]=dep[x]+1;
		v1[x]=min(v1[x],v[y]);
		fa[y]=x;dfs(y);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",v+i);
	for(int i=2;i<=n;i++){
		int x,y;scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dep[1]=1;dfs(1);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		if(dep[x]<dep[y])swap(x,y);
		for(L=0;dep[x]>dep[y];x=fa[x])
		p[++L]=x;
		for(L1=0;x!=y;x=fa[x],y=fa[y])
		p[++L]=x,p1[++L1]=y;
		for(p[++L]=x;L1;)p[++L]=p1[L1--];
		for(int i=1;i<=L;i++){
			f[i]=i^1?1e18:v[p[1]];f1[i]=1e18;
			for(int j=1;j<=k&&j<i;j++)
			f[i]=min(f[i],f[i-j]+v[p[i]]);
			if(i>=3&&k==3){
				f1[i]=min(f1[i-1],f[i-2])+min(p[i]==x&&x!=1?v[fa[x]]:v1[p[i]],v1[p[i]]);
				f[i]=min(f[i],f1[i-2]+v[p[i]]);
			}
		}
		printf("%lld\n",f[L]);
	}
	return 0;
}
