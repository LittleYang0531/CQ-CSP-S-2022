#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 200005
#define ll long long
#define INF_INT 0x3f3f3f3f
using namespace std;
char c;
inline void rd(ll &x){
	x=0;
	c=getchar();
	while((c<'0'||c>'9'))c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
}
int n,Q,K,x,y;
int dep[N],prt[N],p[N][32];
ll a[N],sum[N];
vector<int>v[N];
void dfs(int x){
	for(auto y:v[x]){
		if(y!=prt[x]){
			prt[y]=x;
			dep[y]=dep[x]+1;
			sum[y]=sum[x]+a[y];
			dfs(y);
		}
	}
}
void ST(){
	memset(p,-1,sizeof(p));
	for(int i=1;i<=n;i++)p[i][0]=prt[i];
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i<=n;i++)
			if(p[i][j-1]!=-1)
				p[i][j]=p[p[i][j-1]][j-1];
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int dx=dep[x],dy=dep[y];
	int k=log2(dx-dy);
	for(int i=k;i>=0;i--){
		if(dx-(1<<i)>=dy)
			x=p[x][i],dx=dep[x];
	}
//	cout<<"dep:"<<dep[x]<<" "<<dep[y]<<endl;
	if(x==y)return x;
	k=log2(dx);
	for(int i=k;i>=0;i--){
		if(p[x][i]!=p[y][i]&&p[x][i]!=-1&&p[y][i]!=-1)
			x=p[x][i],y=p[y][i];
	}
	return p[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>K;
	for(int i=1;i<=n;i++)
		rd(a[i]);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sum[1]=a[1];
	dfs(1);
	ST();
//	for(int i=1;i<=n;i++)
//		cout<<sum[i]<<" ";
//	puts("");
	while(Q--){
		scanf("%d %d",&x,&y);
		if(K==1){
			int z=lca(x,y);
			printf("%lld\n",sum[x]+sum[y]-2*sum[z]+a[z]);
		}
	}
	return 0;
}
/*
7 3 1
1 2 3 4 5 6 7
1 2
1 3
2 7
3 4
3 5
5 6
2 6
1 5
4 5
*/
