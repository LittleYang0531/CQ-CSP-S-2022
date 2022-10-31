#include<cstdio>
#include<cmath>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map> 
#include<iostream>
#include<algorithm>
#include<bitset>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define LL long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y; 
}
inline int qkpow(int a,int b){
	int res=1,base=a;
	while(b){
		if(b&1)res=1ll*res*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return res;
}
int n,m,lim,dis[2505][2505];
queue<int>q;
bool vis[2505];
LL a[2505];
vector<int>G[2505];
void bfs(int s){
	for(int i=1;i<=n;i++)vis[i]=0;
	vis[s]=1;
	while(!q.empty())q.pop();
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(!vis[v]){
				vis[v]=1;
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		} 
	}
}
LL ans;
vector<int>buc[2505];
bool cmp(int x,int y){
	return a[x]>a[y];
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);	
	scanf("%d %d %d",&n,&m,&lim);
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=lim+1;
			else dis[i][j]--;
		}
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(i!=j&&dis[j][i]<=lim&&dis[1][j]<=lim)
				buc[i].push_back(j);
	for(int i=2;i<=n;i++)sort(buc[i].begin(),buc[i].end(),cmp);
	for(int y=2;y<=n;y++){
		for(int z=y+1;z<=n;z++){
			if(y!=z&&dis[y][z]<=lim){
				for(int k=0;k<min(5,(int)buc[y].size());k++){
					int x=buc[y][k];
					if(x!=y&&x!=z){
						for(int l=0;l<min(5,(int)buc[z].size());l++){
							int w=buc[z][l];
							if(w!=x&&w!=y&&w!=z)
								ans=max(ans,a[x]+a[y]+a[z]+a[w]);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
a[x] a[y] a[z] a[w]
*/
