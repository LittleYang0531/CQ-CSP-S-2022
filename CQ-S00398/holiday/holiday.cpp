#include<bits/stdc++.h>
using namespace std;
const int MAXN=2510;
char c;
inline unsigned long long read(){
	unsigned long long ans=0;
	while('0'>c||c>'9'){
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans;
}
unsigned long long dp[MAXN][100],w[MAXN];
bool g[MAXN][MAXN];
int cnt=0;
int n,m,k;
void dfs(int s,int u,int d){
	g[s][u]=g[u][s]=1;
	if(d==k)return;
	for(int i=1;i<=n;i++){
		if(i!=s&&i!=u&&g[u][i]&&!g[s][i])
		dfs(s,i,d+1);
	}
} 
unsigned long long ans=0;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	srand(time(0));
	cin.tie(0);
	for(int i=2;i<=n;i++)w[i]=read(),dp[i][0]=i;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		g[u][v]=g[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(g[i][j])
			dfs(i,j,0);
	}
	int T=30000;
	while(T--){
		int a[6];
		a[0]=1;
		for(int j=1;j<=4;j++)
			while(1){
				a[j]=rand()%(n-1)+2;
				if(a[j]!=a[j-1]&&g[a[j-1]][a[j]]){
					bool l=1;
					for(int p=0;p<j;p++){
						if(a[j]==a[p])l=0;
					}
					if(l)break;
				}
			}
		if(g[a[5]][a[0]])continue;
		if(a[5]==1)ans=max(ans,w[a[1]]+w[a[2]]+w[a[3]]+w[a[4]]);			
	}
	cout<<ans;
	return 0;
}
