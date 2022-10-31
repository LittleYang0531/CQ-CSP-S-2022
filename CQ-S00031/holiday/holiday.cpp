#include<bits/stdc++.h>
using namespace std;
namespace IO_ER{
	#define LL long long
	#define db double 
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

#define N 2550

int n,m,k;

LL a[N];

basic_string<int>e[N];

namespace sub1{
	LL ans;
	int vis[N];
	void dfs(int u,int now,int len,LL sum){
		if(len>k)return;
//		cout<<u<<" "<<now<<" "<<len<<endl;
		if(u==1&&now==6){
//			cout<<"--------\n";
			ans=max(ans,sum);
			return;
		}
		if(now>=6)return;
		for(auto v:e[u]){
			dfs(v,now,len+1,sum);
			if(vis[v])continue;
			if(v==1&&now!=5)continue;
			vis[v]=1;
			dfs(v,now+1,0,sum+a[v]);
			vis[v]=0;
		}
	}
	int Main(){
		dfs(1,1,0,0);
		printf("%lld",ans);
		return 0;
	}
}
//#include<windows.h>
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
//	srand((unsigned)time(0));
//	clock_t st,ed;
	read(n,m,k);
	f(2,n,i)read(a[i]);
	int u,v;
//	cout<<endl;
	f(1,m,i){
		read(u,v);
//		cout<<u<<" "<<v<<endl;
		e[u]+=v;
		e[v]+=u;
	}
//	cout<<endl;
//	st=clock();
	if(n<=10&&m<=20){
		int i=0;
		while(i>-1)i++;
		sub1::Main();
	}
//	ed=clock();
//	db DTIME=(ed-st)/1.0;
//	printf("%.8lf",st,ed,DTIME);
	return 0;
}
