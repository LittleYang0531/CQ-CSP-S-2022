#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
#define ll long long
struct G{
	int v,nex;
}a[N];
int n,m,k;
int f[2501][2501]={0};
ll head[N]={0},tot=0,val[N];
void add(int u,int v){
	a[++tot].v=v;
	a[tot].nex=head[u];
	head[u]=tot;
}
void dfs(int st,int u,int fa,int dis){//dis表示转车次数 
	if(dis>k) return;
	if(dis>=0){
		f[st][u]=1;
		f[u][st]=1;
	}
	for(int i=head[u];i;i=a[i].nex){
		int v=a[i].v;
		if(v==fa) continue;
		dfs(st,v,u,dis+1);
	}
}
int ff[2501][2501]={0};
ll ans=0;
int fff[2501][2501]={0};//处理 次大的 
int ck(int i,int j,int ii,int jj){
	if(ii==0||jj==0||i==0||j==0)  return 0;
	return 1;
}
int main(){ 
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		dfs(i,i,0,-1);
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i!=j){
				if(f[1][i]&&f[i][j]){
					if(val[i]>val[ff[1][j]]||ff[1][j]==0){
						if(val[ff[1][j]]>val[fff[1][j]]||fff[1][j]==0){
							fff[1][j]=ff[1][j];
						}
						ff[1][j]=i;
						continue;
					}
					if(val[i]>val[fff[1][j]]||fff[1][j]==0){
						fff[1][j]=i;
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i!=j){
				if(f[i][j]){
					if(i!=j&&i!=ff[1][j]&&ff[1][i]!=j&&ff[1][i]!=ff[1][j]&&ck(i,j,ff[1][i],ff[1][j])){
						if(ans<val[i]+val[j]+val[ff[1][i]]+val[ff[1][j]]){
							ans=val[i]+val[j]+val[ff[1][i]]+val[ff[1][j]];
//							cout<<i<<' '<<j<<' '<<ff[1][i]<<' '<<ff[1][j]<<endl;
						}
					}
					if(i!=j&&i!=fff[1][j]&&ff[1][i]!=j&&ff[1][i]!=fff[1][j]&&ck(i,j,ff[1][i],fff[1][j])){
						if(ans<val[i]+val[j]+val[ff[1][i]]+val[fff[1][j]]){
							ans=val[i]+val[j]+val[ff[1][i]]+val[fff[1][j]];
//							cout<<i<<' '<<j<<' '<<ff[1][i]<<' '<<fff[1][j]<<endl;
						}
					}
					if(i!=j&&i!=ff[1][j]&&fff[1][i]!=j&&fff[1][i]!=ff[1][j]&&ck(i,j,fff[1][i],ff[1][j])){
						if(ans<val[i]+val[j]+val[fff[1][i]]+val[ff[1][j]]){
							ans=val[i]+val[j]+val[fff[1][i]]+val[ff[1][j]];
//							cout<<i<<' '<<j<<' '<<fff[1][i]<<' '<<ff[1][j]<<endl;
						}
					}
				}
			}
		}
	}
	
	printf("%lld",ans);
}
