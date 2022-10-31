#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int f[MAXN],a[MAXN],head[MAXN],vis[MAXN],viss[MAXN];
int n,m,k;
int cnt,mxa=-1;
struct ss{
	int ds,nx,to;
}add[MAXN<<1];
void add_edge(int x,int y){
	add[++cnt].nx=head[x];
	add[cnt].to=y;
	add[cnt].ds=a[y];
	head[x]=cnt;
}
void dfs(int t,int kk,int u,int l){
//	cout<<t<<" ";
	if(kk==0&&t==1){
		mxa=max(mxa,l);
		return ;
	}
	for(int i=head[t];i;i=add[i].nx){
		int to=add[i].to;
		if(vis[to]==0&&kk>0&&viss[to]==0){
		//	cout<<to<<" ";
			vis[to]=1,viss[to]=1;
			dfs(to,kk-1,0,l+a[to]);
			vis[to]=0,viss[to]=0;
		}
		if(u<k||(to==1&&kk==0)){
			viss[to]=1;
			dfs(to,kk,u+1,l);
			viss[to]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	vis[1]=1;	
	dfs(1,4,0,0);
	printf("%d",mxa);
	return 0;
}
/*



7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

*/
