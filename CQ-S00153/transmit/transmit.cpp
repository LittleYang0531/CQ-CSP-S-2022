#include<bits/stdc++.h>
using namespace std;
int n,q,k,v[200010],head[200010],cnt;
struct node{
	int to,next;
}e[200010*2];
void add(int u,int v){
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=q;++i){
		int s,t;
		scanf("%d%d",&s,&t);
	}
	return 0;
}
