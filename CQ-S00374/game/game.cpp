#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5,M=20,inf=1e9+1;
int LG[N];
struct st{
	int a[M][N],b[M][N],c[N],n;
	void init(){
		for(int i=1;i<=n;i++){
			if(c[i]==inf)a[0][i]=-inf,b[0][i]=inf;
			else a[0][i]=b[0][i]=c[i];
		}
		for(int i=1;i<=LG[n];i++){
			for(int j=1;j+(1<<i)-1<=n;j++){
				a[i][j]=max(a[i-1][j],a[i-1][j+(1<<i-1)]);
				b[i][j]=min(b[i-1][j],b[i-1][j+(1<<i-1)]);
			}
		}
	}
	int ask(int l,int r,bool op){
		int x=LG[r-l+1]-1;
		if(op)return max(a[x][l],a[x][r-(1<<x)+1]);
		return min(b[x][l],b[x][r-(1<<x)+1]);
	}
}c[4];
int n,m,q,a[N],b[N],f[5],g[5];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	c[0].n=c[1].n=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=0)c[0].c[i]=a[i];
		else c[0].c[i]=inf;
		if(a[i]<=0)c[1].c[i]=a[i];
		else c[1].c[i]=inf;
	}
	c[2].n=c[3].n=m;
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(b[i]>=0)c[2].c[i]=b[i];
		else c[2].c[i]=inf;
		if(b[i]<=0)c[3].c[i]=b[i];
		else c[3].c[i]=inf;
	}
	for(int i=1;i<=n||i<=m;i++)LG[i]=LG[i>>1]+1;
	for(int i=0;i<=3;i++)c[i].init();
	int l,r;
	while(q--){
		long long ans=-1ll*inf*inf;
		scanf("%d %d",&l,&r);
		f[0]=c[0].ask(l,r,0),f[1]=c[0].ask(l,r,1);
		f[2]=c[1].ask(l,r,0),f[3]=c[1].ask(l,r,1);
		scanf("%d %d",&l,&r);
		g[0]=c[2].ask(l,r,0),g[1]=c[2].ask(l,r,1);
		g[2]=c[3].ask(l,r,0),g[3]=c[3].ask(l,r,1);
//		for(int i=0;i<=3;i++)printf("%d %d\n",f[i],g[i]);
		for(int i=0;i<=3;i++){
			if(f[i]==inf||f[i]==-inf)continue;
			long long x=1ll*inf*inf;
			for(int j=0;j<=3;j++){
				if(g[j]==inf||g[j]==-inf)continue;
				x=min(x,1ll*f[i]*g[j]);
			}
			ans=max(ans,x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
