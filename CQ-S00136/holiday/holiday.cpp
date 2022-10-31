#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
int n,m,k,v[N][N],vis[N];
ll a[N],f[N][N],ans=0;

void dfs(int pos,int id,ll s){
	if(pos==5){
		if(f[id][1]-1<=k)
			ans=max(s,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(f[id][i]-1<=k){
			vis[i]=1;
			dfs(pos+1,i,s+a[i]);
			vis[i]=0;
		}
	}
}

int rd(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=rd();m=rd();k=rd();
	for(int i=2;i<=n;i++) cin>>a[i];
	for(int i=1,x,y;i<=m;i++){
		x=rd();y=rd();
		v[x][y]=v[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)  f[i][j]=2e16;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(v[i][j]) f[i][j]=min(f[i][j],(ll)1);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(f[1][i]-1<=k){
			vis[i]=1;
			dfs(2,i,a[i]);
			vis[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
