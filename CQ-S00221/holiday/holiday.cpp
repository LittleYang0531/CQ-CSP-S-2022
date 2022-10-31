#include<bits/stdc++.h>
using namespace std;
int n,m,zc,t=10005;
long long s[2505],ans;
bool r[2505][2505],vis[2505];
void dfs(int x,int y,int s){
	if(x==y){
		t=min(t,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(r[x][i]&&!vis[i]){
			vis[i]=1;
			dfs(i,y,s+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&zc);
	zc++;
	for(int i=2;i<=n;i++)scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		r[x][y]=1;
		r[y][x]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			for(int k=2;k<=n;k++)
				for(int l=2;l<=n;l++){
					if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l){
						int l1,l2,l3,l4,l5;
						vis[1]=1;
						dfs(1,i,0);
						l1=t;
						t=10005;
						memset(vis,0,sizeof(vis));
						
						vis[i]=1;
						dfs(i,j,0);
						l2=t;
						t=10005;
						memset(vis,0,sizeof(vis));
						
						vis[j]=1;
						dfs(j,k,0);
						l3=t;
						t=10005;
						memset(vis,0,sizeof(vis));
						
						vis[k]=1;
						dfs(k,l,0);
						l4=t;
						t=10005;
						memset(vis,0,sizeof(vis));
						
						vis[l]=1;
						dfs(l,1,0);
						l5=t;
						t=10005;
						memset(vis,0,sizeof(vis));
						
						if(l1<=zc&&l2<=zc&&l3<=zc&&l4<=zc&&l5<=zc){
							ans=max(ans,s[i]+s[j]+s[k]+s[l]);
						}
					}
				}
	printf("%lld",ans);
	return 0;
}
