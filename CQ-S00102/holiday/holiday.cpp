#include<bits/stdc++.h>
#define ll long long
#define N 2500
#define inf 0x3f3f3f3f
#define inff 0x7f7f7f7f7f7f7f7f
using namespace std;

inline ll read(){
	ll s=0;char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();
	return s;
}

inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

int n,m,k;
ll s[N+100];
vector<int> a[N+100];

struct node{ll v;int i;}b[N+100];
bool cmp(node x,node y){return x.v<y.v;}


int dis[N+100][N+100];
queue<int> q;
void BFS(int rt){
	dis[rt][rt]=-1;
	q.push(rt);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i];
			if(dis[rt][y]<inf) continue;
			dis[rt][y]=dis[rt][x]+1;
			q.push(y);
		}
	}
}

int leg[N+100][N+100],top[N+100];

// 1 i j x y 1
int main(){
	
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++) s[i]=read(),b[i].v=s[i],b[i].i=i;
	sort(b+2,b+n+1,cmp);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		a[x].push_back(y),a[y].push_back(x);
	}
	
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) BFS(i),dis[i][i]=0;
	
	if(n<=50){
		
		ll ans=-1;
		for(int i=2;i<=n;i++) if(dis[1][i]<=k){
			for(int j=2;j<=n;j++) if(j!=i&&dis[i][j]<=k){
				for(int x=2;x<=n;x++) if(x!=i&&x!=j&&dis[j][x]<=k){
					for(int y=2;y<=n;y++) if(y!=i&&y!=j&&y!=x&&dis[x][y]<=k){
						if(dis[y][1]<=k)
							ans=max(ans,s[i]+s[j]+s[x]+s[y]);
					}
				}
			}
		}
		write(ans);
		return 0;
	}
	
	for(int x=2;x<=n;x++){
		for(int z=2;z<=n;z++){
			int y=b[z].i;
			if(x==y) continue;
			if(dis[1][y]<=k&&dis[x][y]<=k)
				leg[x][++top[x]]=y;
		}
	}
	
	ll ans=-1;
	for(int x=2;x<=n;x++){
		for(int j=2;j<=n;j++){
			if(x==j||dis[x][j]>k) continue;
		
			int cnty=top[x],cnti=top[j];
			int y=leg[x][cnty],i=leg[j][cnti];
			if(y==j) y=leg[x][--cnty];
			if(i==x) i=leg[j][--cnti];
			if(!y||!i) continue;

			if(y!=i) ans=max(ans,s[i]+s[j]+s[x]+s[y]);
			else{
				int tmpy=cnty,tmpi=cnti;
				
				y=leg[x][--cnty];
				if(y==j) y=leg[x][--cnty];
				if(y&&y!=i) ans=max(ans,s[i]+s[j]+s[x]+s[y]);
				
				cnty=tmpy,cnti=tmpi;
				y=leg[x][cnty],i=leg[j][cnti];
				
				i=leg[j][--cnti];
				if(i==x) i=leg[j][--cnti];
				if(i&&i!=y) ans=max(ans,s[i]+s[j]+s[x]+s[y]);
			}
		}
	}
	
	write(ans);
	return 0;
}
