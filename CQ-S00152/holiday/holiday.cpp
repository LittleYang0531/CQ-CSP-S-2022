#include<bits/stdc++.h>
using namespace std;
#define M1 2505
#define M2 100005
typedef long long ll;
int n,m,k,a[M1][M2],b[M1],c[M1];
int p,q;
bool f[M1],f2[M1][M1];
ll fen[M1],ans,sum;
void addn(int step,int x,int y){
	for(int i=1;i<=c[y];i++){
		if(f2[x][a[y][i]]==0 && x!=a[y][i]){
			f2[x][a[y][i]]=1;
			f2[a[y][i]][x]=1;
			a[x][++b[x]]=a[y][i];
			a[a[y][i]][++b[a[y][i]]]=x;
			if(step+1<=k)
				addn(step+1,x,a[y][i]);
			else
				return;
		}
	}
}
void dfs(int step,int now){
	if(step==5){
		if(f2[now][1]==1){
			ans=max(ans,sum);
		}
		return;
	}
	for(int i=1;i<=b[now];i++){
		if(f[a[now][i]]==0){
			sum+=fen[a[now][i]];
			f[a[now][i]]=1;
			dfs(step+1,a[now][i]);
			sum-=fen[a[now][i]];
			f[a[now][i]]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++)
		scanf("%lld",&fen[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&p,&q);
		a[p][++b[p]]=q;
		a[q][++b[q]]=p;
		f2[p][q]=1;
		f2[q][p]=1;
		c[p]=b[p];
		c[q]=b[q];
	}
	for(int i=1;i<=n && k;i++){
		for(int j=1;j<=c[i];j++){
			addn(1,i,a[i][j]);
		}
	}
	f[1]=1;
	dfs(1,1);
	printf("%lld",ans);
	return 0;
}
