#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2510;
//char buf[(1<<21)+1],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,k,a[N];
int dis[N][N];
vector<int>e[N];
int q[N*2],l,r;
void bfs(int rt){
	int *d=&dis[rt][0];
	d[rt]=0;l=1,r=0;q[++r]=rt;
	while(l<=r){
		int x=q[l++];
		for(int to:e[x]){
			if(d[x]+1<d[to])
				d[to]=d[x]+1,
				q[++r]=to;
		}
	}
}
int mx[N][3];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read()+1;
	For(i,2,n)a[i]=read();
	rep(i,m){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(dis,0x3f,sizeof dis);
	rep(i,n)bfs(i);
	For(i,2,n)For(j,2,n)if(i!=j&&dis[1][i]<=k&&dis[i][j]<=k){
		int now=i;
		if(a[now]>a[mx[j][2]])swap(mx[j][2],now);
		if(a[now]>a[mx[j][1]])swap(mx[j][1],now);
		if(a[now]>a[mx[j][0]])swap(mx[j][0],now);
	}
	int ans=0;
	For(i,2,n)For(j,2,n)if(i!=j&&dis[i][j]<=k){
		For(A,0,2)For(B,0,2)if(mx[i][A]!=mx[j][B]&&mx[i][A]!=j&&mx[j][B]!=i&&mx[i][A]&&mx[j][B])
			ans=max(ans,a[mx[i][A]]+a[i]+a[j]+a[mx[j][B]]);
	}cout<<ans<<endl;
	return 0;
}


