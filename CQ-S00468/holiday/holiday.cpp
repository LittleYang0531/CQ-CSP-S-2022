#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+10;
struct G{
	int u,v,nxt;
}e[M];
int head[M],cnt;
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,m,k;
int s[M];
int dp[40000][10];
struct Node{
	int j,id;
};
queue<Node> q;
vector<int> way[M];
int check(int x,int v){
	for(int i=0;i<way[x].size();i++){
		if(way[x][i]==v)return 1;
	}
	return 0;
}
void solve(){
	for(int p=head[1];p;p=e[p].u ){
		int v=e[p].v;
		dp[v][1]=s[v];
		way[v].push_back(v);
	}
	Node aaaa;
	aaaa.id=1,aaaa.j=0;
	q.push(aaaa);
	while(q.size()){
		Node now=q.front();
		q.pop();
		if(way[now.id ].size()>5)continue;
		int x=now.id,j=now.j;
		for(int p=head[x];p;p=e[p].nxt ){
			int v=e[p].v;
			if(v==1&&way[x].size()!=4)continue;
			if(check(x,v))continue;
			if(dp[v][j+1]<dp[x][j]+s[v]){
				dp[v][j+1]=dp[x][j]+s[v];
				way[v]=way[x];
				way[v].push_back(v);
				Node ne;
				ne.j=j+1,ne.id =v;
				q.push(ne);
			}
		}
	}
}
int dis[3000][3000];
void init_zrx(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]==1)continue;
			for(int kk=1;kk<=n;kk++){
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
				if(dis[i][j]<=k+1){
					add(i,j);
					add(j,i);
				}
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dis,0x3f,sizeof dis);
	dis[1][1]=0;
	for(int i=2;i<=n;i++){
		scanf("%d",&s[i]);
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		dis[x][y]=dis[y][x]=1;
	}
	if(k)init_zrx();
	solve();
	int ans=0;
	for(int i=0;i<way[1].size();i++){
		ans+=s[way[1][i]];
//		cout<<way[1][i]<<" ";
	}
	printf("%d",ans);
} 
