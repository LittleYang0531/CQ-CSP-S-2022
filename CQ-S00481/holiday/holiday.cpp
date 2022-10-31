#include<bits/stdc++.h>
#define int long long
#define inf 10000000000
//belief2022
using namespace std;
struct node{
	int to,next;
};
node e[100086];
int n,m,k,head[100086],cnt,a[2505],sum;
int dp[5][105][20005];
bool vis[20005]={0,1},v[20005];
void spfa(int s,int sm,int dep,int kl){
	if(sm<dp[dep][kl][s]){
		return;
	}
	if(kl>k)return;
	dp[dep][kl][s]=max(dp[dep][kl][s],sm);
	if(dep==4){
		if(v[s]==1)sum=max(sum,sm);
		return;
	}
	if(kl==k){
		for(int i=head[s];i!=0;i=e[i].next){
			if(vis[e[i].to]==0){
				vis[e[i].to]=1;
				spfa(e[i].to,sm+a[e[i].to],dep+1,0);
				vis[e[i].to]=0;
			}
		}
		return;
	}
	for(int i=head[s];i!=0;i=e[i].next){
		spfa(e[i].to,sm,dep,kl+1);
		if(vis[e[i].to]==0){
			vis[e[i].to]=1;
			spfa(e[i].to,sm+a[e[i].to],dep+1,0);
			vis[e[i].to]=0;
		}
	}
}
int mx(int a,int b){
	if(a<b)return b;
	return a;
}
void work(int s,int dep){
	if(dep>k)return;
	for(int i=head[s];i;i=e[i].next){
		v[e[i].to]=1;
		work(e[i].to,dep+1);
	}
}
main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		e[++cnt].next=head[x];
		e[cnt].to=y;
		head[x]=cnt;
		e[++cnt].next=head[y];
		e[cnt].to=x;
		head[y]=cnt;
	}
	work(1,0);
	spfa(1,0,0,0);
	cout<<sum;
}
