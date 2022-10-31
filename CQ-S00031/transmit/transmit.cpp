#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double 
	#define unsigned U
	#define ULL U LL
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define ff(a,b,i) for(int i=a;i<b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define ff_(a,b,i) for(int i=a;i>b;i--)
	int inf=0x3f3f3f3f;
	int INF=0x7fffffff;
	LL infll=0x3f3f3f3f3f3f3f3fll;
	LL INFll=0x7fffffffffffffffll;
	template<typename T>void read(T &x){
		x=0;
		int f=0;
		char c=getchar();
		while(c<'0'||'9'<c){
			if(c=='-')f=1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			x=x*10+(c^48);
			c=getchar();
		}
		x=f?-x:x;
	}
	template<typename T,typename ...Args>void read(T &x,Args &...args){
		read(x);
		read(args...);
	}
}
using namespace IO_ER;

#define N 200050

int n,q,k;

LL a[N];

basic_string<int>e[N];

int dep[N];

int fa[N][20];

int fl=0;

int Lca(int &x,int &y){
	if(dep[x]<dep[y])swap(x,y),fl=1;
//	cout<<x<<" "<<y<<endl;
	f_(18,0,i){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
//	cout<<x<<" "<<y<<" "<<dep[x]<<endl;
		}
	}
	if(x==y)return y;
	f_(18,0,i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}

namespace sub1{
	
	LL dis[N];
	
	void dfs1(int u,int faa){
		dis[u]=dis[faa]+a[u];
		dep[u]=dep[faa]+1;
		fa[u][0]=faa;
		f(1,18,i)fa[u][i]=fa[fa[u][i-1]][i-1];
		for(auto v:e[u]){
			if(v==faa)continue;
			dfs1(v,u);
		}
	}
	
	int Main(){
		dfs1(1,0);
		int s,t;
		f(1,q,i){
			read(s,t);
			int x=s,y=t;
			int lca=Lca(x,y);
			printf("%lld\n",dis[s]+dis[t]-2*dis[lca]+a[lca]);
		}
		return 0;
	}
}

namespace sub2{
	#define LN 2050
	LL dis[LN][LN];
	
	void dfs1(int u,int faa){
		dep[u]=dep[faa]+1;
		fa[u][0]=faa;
		f(1,18,i)fa[u][i]=fa[fa[u][i-1]][i-1];
		dis[u][u]=a[u];
//			if(u==171&&faa==17){
//				printf("%d %d %d %d %d\n",dis[u][faa],dis[u][u],faa,u,a[faa]);
//			}
		if(faa)dis[u][faa]=a[u]+a[faa];
		int now=fa[faa][0],lst=faa,lt=u;
		while(now){
			dis[u][now]=min(dis[u][lst],dis[u][lt])+a[now];
//			if(u==171&&now==17){
////				printf("%d %d %d %d %d %d\n",dis[u][now],dis[u][lst],dis[u][lt],lst,lt,a[now]);
//			}
			lt=lst;
			lst=now;
			now=fa[now][0];
		}
		for(auto v:e[u]){
			if(v==faa)continue;
			dfs1(v,u);
		}
	}
	
	int Main(){
		if(k==2)dfs1(1,0);
//		if(k==3)dfs2(1,0);
		int s,t;
		f(1,q,i){
//			cout<<endl;
			read(s,t);
			int x=s,y=t;
			fl=0;
			int lca=Lca(x,y);
			if(fl)swap(x,y);
//			cout<<s<<" "<<t<<" "<<x<<" "<<y<<" "<<lca<<endl;
			if(x==y){
				if(dep[s]<dep[t])swap(s,t);
				printf("%lld\n",dis[s][t]);
			}
			else{
				LL t1=dis[s][lca]+dis[t][lca]-a[lca];
				LL t2=dis[s][x]+dis[t][y];
//				cout<<x<<" "
				if(t1<t2)printf("%lld\n",t1);	
				if(t1>=t2)printf("%lld\n",t2);	
			}
		}
		return 0;
	}
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\transmit\\transmit3.in","r",stdin);
//	freopen("C:\\Users\\Administrator\\Desktop\\CSP-S\\CSP-S\\transmit\\transmit3.txt","w",stdout);

//	srand((unsigned)time(0));
//	clock_t st,ed;
	read(n,q,k);
	f(1,n,i)read(a[i]);
	int u,v;
	ff(1,n,i){
		read(u,v);
		e[u]+=v;
		e[v]+=u;
	}
//	st=clock();
	if(k==1){
		sub1::Main();
	}
	else if(n<=2000){
		sub2::Main();
	}
//	ed=clock();
//	db DTIME=(ed-st)/1000.0;
//	printf("%.4lf",DTIME);
	return 0;
}
