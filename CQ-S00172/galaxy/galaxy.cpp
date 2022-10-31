//你不曾注意阴谋得逞者在狞笑！
//估分60 
#include<cstdio>
#include<cctype>
#include<set>
namespace SOLVE{
	inline int read(){
		int n(0);char s;while(!isdigit(s=getchar()));while(n=n*10+(s&15),isdigit(s=getchar()));return n;
	}
	const int M=5e5+5;
	std::set<int>Add[M],Del[M];
	int n,m,q,d[M],cnt;
	inline void f1(const int&u,const int&v){
		Del[v].insert(u);Add[v].erase(u);if(d[u]==1)--cnt;--d[u];if(d[u]==1)++cnt;
	}
	inline void f2(const int&v){
		static int len,t[M];len=0;for(int x:Add[v])t[++len]=x;for(int i=1;i<=len;++i)f1(t[i],v);
	}
	inline void f3(const int&u,const int&v){
		Add[v].insert(u);Del[v].erase(u);if(d[u]==1)--cnt;++d[u];if(d[u]==1)++cnt;
	}
	inline void f4(const int&v){
		static int len,t[M];len=0;for(int x:Del[v])t[++len]=x;for(int i=1;i<=len;++i)f3(t[i],v);
	}
	inline void main(){
		n=read();m=read();for(int u,v,i=1;i<=m;++i)u=read(),v=read(),Add[v].insert(u),++d[u];
		for(int u=1;u<=n;++u)if(d[u]==1)++cnt;q=read();
		while(q--){
			int opt,u;opt=read();u=read();
			if(opt==1)f1(u,read());if(opt==2)f2(u);if(opt==3)f3(u,read());if(opt==4)f4(u);
			if(cnt==n)putchar('Y'),putchar('E'),putchar('S');else putchar('N'),putchar('O');putchar(10);
		}
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	SOLVE::main();
	return 0;
}
