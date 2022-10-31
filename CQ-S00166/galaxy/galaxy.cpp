#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
const long long N=1e5+10;

long long n,m,q;
long long head[N],book[N],cnt,dist[N];

struct node{
	long long nxt,to,w;
}e[N*2];

inline void add(long long x,long long y,long long z){
	e[++cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].to=y;
	e[cnt].w=z;
}

inline void spfa(long long s){
	queue<long long> q;
	q.push(s);
	memset(book,0,sizeof(book));
	memset(dist,0x3f,sizeof(dist));
	book[s]=1;
	dist[s]=0;
	while(!q.empty()){
		long long tmp=q.front();
		book[tmp]=0;
		q.pop();
		for(long long i=head[tmp];i;i=e[i].nxt){
			long long v=e[i].to,w=e[i].w;
			if(dist[v]>dist[tmp]+w){
				dist[v]=dist[tmp]+w;
				if(!book[v]){
					book[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y,1);
	}
	scanf("%lld",&q);
	long long t=n,s=1;
	while(q--){
		long long pos;
		scanf("%lld",&pos);
		if(pos==1){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			add(x,y,-1);
//			spfa(s);
//			cout<<dist[t]<<endl;
			if(x&1 && y&1) printf("NO\n");
			else printf("YES\n");
		}else if(pos==2){
			long long u;
			scanf("%lld",&u);
//			spfa(s);
//			cout<<dist[t]<<endl;
			if(!u&1) printf("NO\n");
			else printf("YES\n");
		}else if(pos==3){
			long long u,v;
			scanf("%lld%lld",&u,&v);
			add(u,v,1);
//			spfa(s);
//			cout<<dist[t]<<endl;
			if(u&1 && v&1) printf("YES\n");
			else printf("NO\n");
		}else if(pos==4){
			long long u;
			scanf("%lld",&u);
//			spfa(s);
//			cout<<dist[t]<<endl;
			if(!u&1)printf("NO\n");
			else printf("YES\n");
		}
	}
 } 
