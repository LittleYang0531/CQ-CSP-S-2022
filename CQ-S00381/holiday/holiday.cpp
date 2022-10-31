#include<bits/stdc++.h>
#define LL long long
#define Max(x,y) (x<y?y:x)
#define Min(x,y) (x<y?x:y)
using namespace std;
void read(int&x){
	x=0;
//	fh=1;
	char c=getchar();
	while(c<'0'||'9'<c){
//		if(c == '-')fh=-1;
		c=getchar();
	}
	while(c<':'&&'/'<c){
		x=x*10+c-'0';
		c=getchar();
	}
//	x*=fh;
}
int t[200005],las[200005],fir[2505],num;
void add(int u,int v){
	t[++num]=v;
	las[num]=fir[u];
	fir[u]=num;
}
int dis[2505][2505];
int vxxr[2505];
int cx[2505];
int n,m,k;

queue<int> q;
void bfs(int rt){
	while(q.size())q.pop();
	memset(vxxr,0,sizeof vxxr);
	q.push(rt);
	dis[rt][rt]=-1;
	vxxr[rt]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(dis[rt][u]>=k)continue;
		for(int i=fir[u];i;i=las[i]){
			if(vxxr[t[i]])continue;
			dis[rt][t[i]]=dis[rt][u]+1;
			vxxr[t[i]]=1;
			q.push(t[i]);
		}
	}
}
void Bfs(){
	memset(dis,127,sizeof dis);
	for(int i=1;i<=n;i++){
	bfs(i);
	/*
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
		*/
	}
}
int ans=0;
void f1(){
	Bfs();
	for(int a=2;a<=n;a++){
		if(dis[1][a]>k)continue;
		for(int b=2;b<=n;b++){
			if(dis[a][b]>k||a == b)continue;
			for(int c=2;c<=n;c++){
				if(dis[b][c]>k||a == c||b == c)continue;
				for(int d=2;d<=n;d++){
					if(dis[c][d]>k||dis[1][d]>k||dis[1][d]>k||a == d||b == d||c == d)continue;
					ans=max(ans,cx[a]+cx[b]+cx[c]+cx[d]);
				}
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=2;i<=n;i++)read(cx[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	f1();
	cout<<ans;
	return 0;
}
