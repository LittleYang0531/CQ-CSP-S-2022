#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long df[2505];
bool lt[2505][2505];
int zd[2505][2505];
long long ans=-1;
bool fw[2505];
void dfs(int zxd,int yd,int sd){
	if(sd>k+1) return ;
	zd[zxd][yd]=min(zd[zxd][yd],sd);
	for(int i=1;i<=n;i++)
		if(lt[yd][i]) dfs(zxd,i,sd+1);
}
void zdl(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			zd[i][j]=105;
	for(int i=1;i<=n;i++)
		dfs(i,i,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(zd[i][j]!=105){
				lt[i][j]=true;
			}
	for(int i=1;i<=n;i++) lt[i][i]=false;
}
void ansdfs(int sd,int d,long long z){
	if(sd==5){
		if(d==1) ans=max(ans,z);
		return;
	}
	for(int i=1;i<=n;i++)
		if(lt[d][i] && !fw[i]){
			fw[i]=true;
			ansdfs(sd+1,i,z+df[d]);
			fw[i]=false;
		} 
	
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&df[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		lt[x][y]=lt[y][x]=true;
	}
	zdl();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			if(lt[i][j]) printf("1 ");
//			else printf("0 ");
//		printf("\n");
//	}
	ansdfs(0,1,0);
	printf("%d",ans);
	return 0;
}


