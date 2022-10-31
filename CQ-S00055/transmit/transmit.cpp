#include<bits/stdc++.h>
using namespace std;
long long N,Q1,K,a[200005],A,B;
int hd1[200005],nxt1[400005],to1[400005],hi1;
int hd[200005],nxt[10000005],to[10000005],hi;
void make_edge1(int x,int y) {
	hi1++;
	nxt1[hi1]=hd1[x];
	hd1[x]=hi1;
	to1[hi1]=y;
}
void make_edge(int x,int y) {
	hi++;
	nxt[hi]=hd[x];
	hd[x]=hi;
	to[hi]=y;
}
void dfs(int x,int fa,int n,int k) {
	if(k>=K)return ;
	for(int i=hd1[n]; i!=0; i=nxt1[i]) {
		int t=to1[i];
		if(t==fa)continue;
		make_edge(x,t);
		dfs(x,n,t,k+1);
	}
}
long long d[200005],f[200005];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >Q;
void dijkstra(int x) {
	for(int i=1; i<=N; ++i) {
		d[i]=1000000000000000000;
		f[i]=0;
	}
	d[x]=a[x];
	Q.push(make_pair(d[x],x));
	while(!Q.empty()) {
		long long c=Q.top().first,w=Q.top().second;
		Q.pop();
		if(f[w]==1)continue;
		f[w]=1;
		for(int i=hd[w]; i!=0; i=nxt[i]) {
			int t=to[i];
			if(d[t]>c+a[t]) {
				d[t]=c+a[t];
				Q.push(make_pair(d[t],t));
			}
		}
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&N,&Q1,&K);
	for(int i=1; i<=N; ++i) {
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<N; ++i) {
		scanf("%lld%lld",&A,&B);
		make_edge1(A,B);
		make_edge1(B,A);
	}
	for(int i=1; i<=N; ++i) {
		dfs(i,i,i,0);
	}
	for(int i=1; i<=Q1; ++i) {
		scanf("%lld%lld",&A,&B);
		dijkstra(A);
		printf("%lld\n",d[B]);
	}
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7
1221097936
1086947276
1748274667
887646183
939363946
900059971
964517506
1392379601
992068897
541763489
10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7
1221097936
1086947276
1748274667
887646183
939363946
900059971
964517506
1392379601
992068897
541763489
Oh My God!
*/
