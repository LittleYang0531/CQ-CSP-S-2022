#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,m,k,tp[M],_tp[M],dis[M];
long long maxa[M],_maxa[M],ans,val[M];
vector<int>G[M],mem[M];
bool vis[M];
struct ac{
	int x,y;
};
void bfs(int op){
	queue<ac>q;
	ac o;
	o.x=op;
	o.y=0;
	vis[op]=1;
	q.push(o);
	while(q.size()){
		ac p=q.front();
		q.pop();
		if(p.y>=k+1) continue;
		int siz=G[p.x].size();
		for(int i=0;i<siz;i++){
			int v=G[p.x][i];
			if(vis[v]) continue;
			vis[v]=1;
			ac f;
			f.x=v;
			f.y=p.y+1;
			mem[op].push_back(v);
			q.push(f);
		}
	}
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	val[1]=0;

	for(int i=1;i<n;i++){
		scanf("%lld",&val[i+1]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	/*for(int i=1;i<=n;i++){
		int siz=mem[i].size();
		for(int j=0;j<siz;j++){
			printf("%d ",mem[i][j]);
		}
		printf("\n");
	}*/
	int siz=mem[1].size();
/*	for(int i=1;i<=n;i++){
		for(int j=0;j<=4;j++){
			dp[i][j]=-1e18;
		}
	}*/
	for(int i=1;i<=n;i++){
		maxa[i]=-1e18;_maxa[i]=-1e18;
	}
	
	for(int i=0;i<siz;i++){
		int ex=mem[1][i];
		int _siz=mem[ex].size();
		for(int j=0;j<_siz;j++){
			int fx=mem[ex][j];
			if(fx==1) continue;
		
			if(val[ex]+val[fx]>maxa[fx]){
				_maxa[fx]=maxa[fx];
				_tp[fx]=tp[fx];
				maxa[fx]=val[ex]+val[fx];
				tp[fx]=ex;
			}
			else if(val[ex]+val[fx]>_maxa[fx]){
				_maxa[fx]=val[ex]+val[fx];
				_tp[fx]=ex;
			}
		}
	}
/*	for(int i=2;i<=n;i++){
		sort(xsh[i].begin(),xsh[i].end(),cmp);
	}*/
/*	for(int i=2;i<=n;i++){
		printf("%lld %d\n",maxa[i],tp[i]);
	}*/
	for(int i=2;i<=n;i++){
		int siz=mem[i].size();
		for(int j=0;j<siz;j++){
			int ex=mem[i][j];
			if(ex==i) continue;
			if(tp[i]!=tp[ex]&&tp[i]!=ex&&tp[ex]!=i){
				ans=max(ans,maxa[i]+maxa[ex]);
			}
			if(tp[i]!=_tp[ex]&&tp[i]!=ex&&_tp[ex]!=i){
				ans=max(ans,maxa[i]+_maxa[ex]);
			}
			if(_tp[i]!=tp[ex]&&_tp[i]!=ex&&tp[ex]!=i){
				ans=max(ans,_maxa[i]+maxa[ex]);
			}
			if(_tp[i]!=_tp[ex]&&_tp[i]!=ex&&_tp[ex]!=i){
				ans=max(ans,_maxa[i]+_maxa[ex]);
			}
		
		}
	}
	printf("%lld",ans);
	return 0;
} 
