#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
int n,m,q;
int ans;
long long c[maxn][maxn];
int dfs(int t,int x,int y){
	int mid=(x+y)/2;
	if(x==y)return c[t][x];
	return min(dfs(t,x,mid),dfs(t,mid+1,y));
}
int main(){
    freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=m;j++){
			if(c[i][j]==0&&a!=0){
				c[i][j]=1;
			}
			c[i][j]*=a;
		}
	}
	for(int i=1;i<=m;i++){
		int b;
		cin>>b;
		for(int j=1;j<=n;j++){
			c[j][i]*=b;
		}
	}
	for(int i=1;i<=q;i++){
		int r1,l1,r2,l2;
		scanf("%d%d%d%d",&r1,&l1,&r2,&l2);
		for(int j=r1;j<=l1;j++){
			if(j==r1){
				ans=dfs(j,r2,l2);
			}else
				ans=max(ans,dfs(j,r2,l2));
		}
		cout<<ans;
		if(i!=q)cout<<endl;
	}
	
}	



