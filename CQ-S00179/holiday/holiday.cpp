#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long int w[2505],ans=-1e9;
int a[505][505],h[505];
long long int b[505];
//priority_queue<>
vector<int>to[2505];
void dfs(int x,int d,long long int sum){
	if(d==6&&x==1){
		ans=max(ans,sum);
		return;
	}
	if(d==6)return;
	sum+=w[x];
	for(int i=0;i<to[x].size();i++)dfs(to[x][i],d+1,sum);
	return;
}
int main(){
	freopen("holiday.in","r",stdin);//´òfreopen!!!
	freopen("holiday.out","w",stdout);//´òfreopen!!!
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)scanf("%lld",&w[i]);
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		dfs(1,1,0);
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)a[i][j]=1e9;
	for(int i=2;i<=n;i++)b[i]=-1e9;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		a[u][v]=a[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int kk=1;kk<=n;kk++)
				a[j][kk]=min(a[j][kk],a[j][i]+a[i][kk]);
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(i!=j&&(a[1][j]-1<=k)&&(a[i][j]-1<=k)&&(w[j]>b[i]))b[i]=w[j],h[i]=j;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(j==i||j==h[i]||(a[i][j]-1>k))continue;
			for(int kk=2;kk<=n;kk++){
				if(kk==i||kk==j||kk==h[i]||(a[kk][j]-1>k)||(a[kk][1]-1>k))continue;
				ans=max(ans,w[i]+b[i]+w[j]+w[kk]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
