#include<bits/stdc++.h>
using namespace std;
const int N=2505,M=15005;
int n,m,k;
long long a[N];
struct edge{
	int to,next;
}e[N*N];
int fir[N],np=0;
bool vis[N],con[N][N];
void add(int x,int y){
	e[++np]=(edge){y,fir[x]};
	fir[x]=np;
}
void bfs(int x){
	int dep=0;
	queue<int>q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()&&dep<=k+1){
		int len=q.size();
		for(int i=1;i<=len;i++){
			int y=q.front();
			q.pop();
			con[x][y]=1;
			for(int j=fir[y];j;j=e[j].next){
				if(vis[e[j].to])continue;
				q.push(e[j].to);
		    }
		}
		dep++;
	}
}
int maxn[N][5];//1 2 3 记录下标 
void dfs2(int x,int d){
	if(d>1){
		if(a[d]<=a[maxn[x][3]])return;
		for(int i=3;i>=1;i--){
			if(a[d]>a[maxn[x][i]])maxn[x][i+1]=maxn[x][i];
			if(a[d]<=a[maxn[x][i-1]]||i==1){
				maxn[x][i]=d;
				break;
			}
		}
		return;
	}
	for(int i=fir[x];i;i=e[i].next){
		int j=e[i].to;
		if(j==1)continue;
		dfs2(j,x);
	}
}
int A=0,B=0;
long long ans=0;
void dfs3(int x,int dep){
	if(dep==3){
		for(int i=1;i<=3;i++){
			if(maxn[x][i]!=A&&maxn[x][i]!=B&&maxn[x][i]){
				ans=max(ans,a[A]+a[B]+a[x]+a[maxn[x][i]]);
				break;
			}
		}
		return;
	}
	for(int i=fir[x];i;i=e[i].next){
		int j=e[i].to;
		if(dep==1){
			if(j==1)continue;
			A=x;
			dfs3(j,dep+1);
		}
		else if(dep==2){
			if(j==1||j==A)continue;
			B=x;
			dfs3(j,dep+1);
		}
		else dfs3(j,dep+1);
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	    scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		    vis[j]=0;
		bfs(i);
	}
	np=0;
	for(int i=1;i<=n;i++)
	    fir[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!con[i][j]||i==j)continue;
			add(i,j);
			add(j,i);
		}
	}
	dfs2(1,-1);
	dfs3(1,0);
	printf("%lld",ans);
	return 0;
}
//预计得分70qwq 
