#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace Solve{
	const int N=2510,M=10010;
	int n,m,k;
	int head[N],ver[M<<1],ne[M<<1],idx=2;
	void add(int x,int y){
		ver[idx]=y,ne[idx]=head[x],head[x]=idx++;
	}
	int dis[N][N];
	queue<int>q;
	void bfs(int s){
		memset(dis[s],-1,sizeof dis[s]);
		q.push(s);dis[s][s]=0;
		while(q.size()){
			int x=q.front();q.pop();
			for(int i=head[x];i;i=ne[i])
				if(dis[s][ver[i]]==-1){
					dis[s][ver[i]]=dis[s][x]+1;
					q.push(ver[i]);
				}
		}
		for(int i=1;i<=n;i++)dis[s][i]--;
	}
	ll a[N],ans;
	ll f[N][3];
	void main(){
		cin>>n>>m>>k;
		for(int i=2;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			add(x,y),add(y,x);
		}
		for(int i=1;i<=n;i++)bfs(i);
		
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++)
				if(j!=i&&dis[1][j]<=k&&dis[i][j]<=k){
					if(a[j]>a[f[i][2]]){
						f[i][2]=j;
						if(a[f[i][2]]>a[f[i][1]]){
							swap(f[i][2],f[i][1]);
							if(a[f[i][1]]>a[f[i][0]]){
								swap(f[i][1],f[i][0]);
							}
						}
					}
				}
		}
		for(int i=2;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(dis[i][j]<=k)
					for(int x=0;x<3;x++)
						for(int y=0;y<3;y++)
							if(f[i][x]&&f[j][y]&&i!=f[j][y]&&f[i][x]!=j&&f[i][x]!=f[j][y]){
								ans=max(ans,a[i]+a[j]+a[f[i][x]]+a[f[j][y]]);
//								if(a[i]+a[j]+a[f[i][x]]+a[f[j][y]]==30){
//									cerr<<i<<' '<<j<<' '<<f[i][x]<<' '<<f[j][y]<<'\n';
//								}
							}
							
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	Solve::main();
}
