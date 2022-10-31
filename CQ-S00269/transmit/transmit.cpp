#include<bits/stdc++.h>
using namespace std;
int n,m,k,q;
long long df[14005];
bool lt[14005][14005];
long long zd[14005][14005];
void dfs(int zxd,int yd,int sd,long long h){
	if(sd>k+1) return ;
	h+=df[yd];
	zd[zxd][yd]=min(zd[zxd][yd],h);
	for(int i=1;i<=n;i++)
		if(lt[yd][i]) {
//			if(sd==0) dfs(zxd,i,sd+1,h);
//			else dfs(zxd,i,sd+1,h+df[yd]);	
			dfs(zxd,i,sd+1,h);
		}

}
void zdl(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			zd[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		dfs(i,i,0,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(zd[i][j]==0x3f3f3f3f){
				zd[i][j]=0;
			}
	for(int i=1;i<=n;i++) zd[i][i]=0;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	m=n-1;
	for(int i=1;i<=n;i++) scanf("%lld",&df[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		lt[x][y]=lt[y][x]=true;
	}
	zdl();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			printf("%d ",zd[i][j]);
//		printf("\n");
//	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",zd[x][y]);
	}
	return 0;
}


