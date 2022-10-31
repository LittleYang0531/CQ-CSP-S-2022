#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,Q,k,a[200005],p[200005][20],d[200005];
ll s[200005][18];
vector<int>e[200005];
void dfs(int x){
	d[x]=d[p[x][0]]+1;
	for(auto y:e[x])
		if(y!=p[x][0]){
			p[y][0]=x;
			dfs(y);
		}
}
int LCA(int x,int y,ll &sum){
	if(d[x]<d[y])swap(x,y);
	for(int i=18;i>=0;i--)
		if(d[x]-d[y]>=1<<i){
			sum+=s[x][i];
			x=p[x][i];
		}
	if(x==y)return x;
	for(int i=18;i>=0;i--)
		if(p[x][i]!=p[y][i]){
			sum+=s[x][i]+s[y][i];
			x=p[x][i];
			y=p[y][i];
		}
	sum+=s[x][0]+s[y][0];
	return p[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i][0]=a[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++){
			p[i][j]=p[p[i][j-1]][j-1];
			s[i][j]=s[i][j-1]+s[p[i][j-1]][j-1];
		}
	while(Q--){
		int S,T;
		scanf("%d%d",&S,&T);
		ll ans=0;
		int res=LCA(S,T,ans);
		printf("%lld\n",ans+a[res]);
	}
	return 0;
}
