#include<bits/stdc++.h>
using namespace std;
int N,M,K,a,b,c[2505],ci;
long long s[2505],Ans;
int hd[2505],nxt[20005],to[20005],hi;
int hd1[2505],nxt1[1000005],to1[1000005],hi1;
vector<int>v[2505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
int make_edge(int x,int y) {
	hi++;
	nxt[hi]=hd[x];
	hd[x]=hi;
	to[hi]=y;
}
int make_edge1(int x,int y) {
	hi1++;
	nxt1[hi1]=hd1[x];
	hd1[x]=hi1;
	to1[hi1]=y;
}
bool comp(int a,int b){
	return s[a]>s[b];
}
int d[2502],f[2505];
void dijkstra(int x) {
	d[x]=0;
	Q.push(make_pair(d[x],x));
	while(!Q.empty()) {
		int c=Q.top().first,w=Q.top().second;
		Q.pop();
		if(f[w]==1)continue;
		f[w]=1;
		for(int i=hd[w]; i!=0; i=nxt[i]) {
			int t=to[i];
			if(d[t]>c+1) {
				d[t]=c+1;
				Q.push(make_pair(d[t],t));
			}
		}
	}
/*	cout<<K+1<<" ";*/
	for(int i=1; i<=N; ++i) {
		//cout<<d[i]<<" ";
		if(d[i]>0&&d[i]<=K+1) {
		//	cout<<"i:"<<i<<" ";
			make_edge1(x,i);
			//	make_edge1(i,x);
		}
		d[i]=0x3f3f3f3f;
		f[i]=0;
	}
	//cout<<"\n";
}
void dfs(int x,int cst,int get) {
	if(cst==4) {
		for(int i=0; i<v[x].size(); i++) {
			if(v[x][i]==1) {
				if(Ans<get) {
					Ans=get;
				}
				return ;
			}
		}
	}
	for(int i=0; i<v[x].size(); i++) {
		int t=v[x][i];
		if(f[t]==0){
			f[t]=1;
			dfs(t,cst+1,get+s[t]);
			f[t]=0;
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for(int i=2; i<=N; ++i) {
		scanf("%lld",&s[i]);
	}
	for(int i=1; i<=M; ++i) {
		scanf("%d%d",&a,&b);
		make_edge(a,b);
		make_edge(b,a);
	}
	for(int i=1; i<=N; ++i) {
		d[i]=0x3f3f3f3f;
		f[i]=0;
	}
	for(int i=1; i<=N; ++i) {
		dijkstra(i);
	/*	for(int j=1; j<=N; ++j) {
			cout<<"j:"<<j<<"  ";
			for(int i=hd1[j]; i!=0; i=nxt1[i]) {
				cout<<to1[i]<<" ";
			}
		}
		cout<<"\n";*/
		ci=0;
		for(int j=hd1[i];j!=0;j=nxt1[j]){
			ci++,c[ci]=to1[j];
		}
		sort(c+1,c+ci+1,comp);
		for(int j=1;j<=ci;++j){
			v[i].push_back(c[j]);
		}
	}
	dfs(1,0,0);
	printf("%lld",Ans);
	/*for(int j=1; j<=N; ++j) {
		cout<<"\n";
		for(int i=hd1[j]; i!=0; i=nxt1[i]) {
			cout<<to1[i]<<" ";
		}

	}*/
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

20 20 0
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12 
12 13
13 14
14 15
15 16 
16 17
17 18
18 19
19 20
20 1
Just so so!
*/
