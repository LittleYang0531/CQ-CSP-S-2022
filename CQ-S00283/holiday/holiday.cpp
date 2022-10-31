#include<bits/stdc++.h>
#define INF 0x7fffffff
#define int long long
using namespace std;
const unsigned int N=1e5+15;
int a[315][315],b[N],n,m,k,ans=-INF,zx=INF,zzx=-INF;
bool vis[N];
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	x*=y;
}
void dfs(int x,int now,int dep){
	//printf("dfsing.. on(%lld) now=%lld dep=%lld\n",x,now,dep);
	if(dep==4&&a[x][1]<=k+1){
		ans=max(ans,now);
		zzx=zx;
		return;
	}
	for(register int i=2;i<=n;i++){
		//printf("try %lld -> %lld dis=%lld\n",x,i,a[x][i]);
		if(x!=i&&!vis[i]&&a[x][i]<=k+1){
			vis[i]=true;
			int tmp=zx;
			if(b[i]<zx)
			zx=b[i];
			if(b[i]<zzx){
				//printf("b[%lld]=%lld zzx=%lld\n",i,b[i],zzx);
				return;
			}
			dfs(i,now+b[i],dep+1);
			zx=tmp;
			vis[i]=false;
		}
	}
}
void init(){
	for(register int i=1;i<n;i++)
	for(register int j=i+1;j<=n;j++)
	a[i][j]=a[j][i]=INF;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n);
	read(m);
	read(k);
	init();
	for(register int i=2;i<=n;i++)
	read(b[i]);
	for(register int i=1;i<=m;i++){
		int u,v;
		read(u);
		read(v);
		a[u][v]=1;
		a[v][u]=1;
	}
	for(register int k=1;k<=n;k++)
	for(register int i=1;i<=n;i++)
	for(register int j=1;j<=n;j++){
		if(i!=k&&k!=j)
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
//dfs+jian zhi yyds
//hao xiang ye jiu 40pts
//wo ai Xiao Ting!
