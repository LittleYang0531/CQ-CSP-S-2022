#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,h[2505],To[20005],Nt[20005],vis[2505],d[2505][2505];
long long v[2505],v2[2505],mx[6],ans;
void ae(int x,int y){
	cnt++;
	To[cnt]=y;
	Nt[cnt]=h[x];
	h[x]=cnt;
}
void DFS(int x,int y){
	for(int i=h[x];i;i=Nt[i]){
		int j=To[i];
		if(d[y][x]+1<d[y][j]){
			d[y][j]=d[y][x]+1;
			DFS(j,y);
		}
	}
}
void dfs(int x,int y,long long o){
	if(o+mx[4-y]<=ans){
		return;
	}
	if(y==4){
		if(d[x][1]<=k){
			ans=o;
		}
		return;
	}
	for(int i=2;i<=n;i++){
		if(!vis[i]&&d[x][i]<=k){
			vis[i]=1;
			dfs(i,y+1,o+v[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	k++;
	for(int i=2;i<=n;i++){
		scanf("%lld",&v[i]);
		v2[i]=v[i];
	}
	sort(v2+2,v2+1+n);
	for(int i=n;i>=n-3;i--){
		mx[n-i+1]=mx[n-i]+v2[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ae(x,y);
		ae(y,x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]=0x7fffffff;
		}
		d[i][i]=0;
		DFS(i,i);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
