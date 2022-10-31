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

long long n,q,k,a[N];
long long book[N],dist[N],head[N],cnt;

struct node{
	long long nxt,to,w;
}e[N*3];

inline void add(long long x,long long y,long long z){
	cnt++;
	e[cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].to=y;
	e[cnt].w=z;
}

inline void spfa(long long s,long long t){
	queue<long long> q;
	q.push(s);
	memset(book,0,sizeof(book));
	book[s]=1;
	memset(dist,0x3f,sizeof(dist));
	dist[s]=a[s];
	while(!q.empty()){
		long long tmp=q.front();
		q.pop();
		book[tmp]=0;
		for(long long i=head[tmp];i;i=e[i].nxt){
			long long v=e[i].to;
			if(dist[v]>dist[tmp]+a[v]){
				dist[v]=dist[tmp]+a[v];
				if(!book[v]){
					q.push(v);
					book[v]=1;
				}
			}
		}
	}
}

long long u;

inline void re(long long x,long long t){
	if(x==t) return ;
	for(long long i=head[x];i;i=e[i].nxt){
		long long v=e[i].to,w=e[i].w;
		if(!book[v]){
			book[v]=1;
			u++;
			re(v,t); 
		}
	}
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=2;i<=n;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	while(q--){
		long long s,t;
		cin>>s>>t;
		memset(book,0,sizeof(book));
		u=0;
		re(s,t);
		//cout<<u<<endl;
		printf("%lld\n",a[s]+a[t]);
	}
 } 
