#include<cstdio>
#include<bitset>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN=2505;
const int MAXM=1e4+5;
#define ull unsigned long long
struct kk{
	int now,dep;
	kk(){};
	kk(int N,int D){now=N;dep=D;}
};
queue<kk> q;
int top,n,m,k,u,p,siz[MAXN][3];
bool vis[MAXN];
vector<int> v[MAXN],jj[MAXN];
ull s[MAXN],dp[MAXN][3],res,va[MAXN][3];
ull Max(ull x,ull y){return x>y?x:y;
}
bitset<2501> b[MAXN][3];
void bfs(){
	vis[top]=1;
	q.push(kk(top,0));
	while(q.size()){
		kk x=q.front();q.pop();
		if(x.dep>k) continue;
		for(int i=0;i<v[x.now].size();i++){
			int u=v[x.now][i];
			if(vis[u]) continue;
			vis[u]=1;
			q.push(kk(u,x.dep+1));
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%llu",&s[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		top=i;
		bfs();
		for(int j=1;j<=n;j++){
			if(j==i||(!vis[j])) continue;
			jj[i].push_back(j);
		}
	}
	for(int i=0;i<jj[1].size();i++){
		u=jj[1][i];
		for(int j=0;j<jj[u].size();j++){
			p=jj[u][j];
			if(p==1) continue;
			ull val=s[u]+s[p];
			if(val>dp[p][0]){
				dp[p][2]=dp[p][1];dp[p][1]=dp[p][0];dp[p][0]=val;
				continue;
			}
			if(val>dp[p][1]){
				dp[p][2]=dp[p][1];dp[p][1]=val;
				continue;
			}
			if(val>dp[p][2]){
				dp[p][2]=val;
			}
		}
	}
	for(int i=0;i<jj[1].size();i++){
		u=jj[1][i];
		for(int j=0;j<jj[u].size();j++){
			p=jj[u][j];
			if(p==1) continue;
			ull val=s[u]+s[p];
			if(val==dp[p][0]){
				b[p][0][u]=1;
				continue;
			}
			if(val==dp[p][1]){
				b[p][1][u]=1;continue;
			}
			if(val==dp[p][2]){
				b[p][2][u]=1;continue;
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<3;j++){
			siz[i][j]=b[i][j].count();
		}
	}
	for(int i=0;i<jj[1].size();i++){
		u=jj[1][i];
		for(int j=0;j<jj[u].size();j++){
			p=jj[u][j];
			if(p==1) continue;
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					bool k1=0,k2=0;
					if(siz[u][k]-b[u][k][p]>=2||siz[p][l]-b[p][l][u]>=2){
						res=max(res,dp[u][k]+dp[p][l]);
					}
//					if(b[u][k][p]==1) k1=1;
//					if(b[p][l][u]==1) k2=1;
//					if(k1) b[u][k][p]=0;
//					if(k2) b[p][l][u]=0;
					if(siz[u][k]-b[u][k][p]>=1&&siz[p][l]-b[p][l][u]>=1&&((b[u][k][p]&b[p][l][u])==0)){
						res=max(res,dp[u][k]+dp[p][l]);
					}
//					if(k1) b[u][k][p]=1;
//					if(k2) b[p][l][u]=1;
				}
			}
		}
	}
	printf("%lld",res);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
