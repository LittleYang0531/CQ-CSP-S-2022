#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#define ll long long
#define ite set<int>::iterator
using namespace std;
namespace shik{
	const int N=500005;
//	char me1;
	struct edge{
		int x,y,z;
	}g[N];
	int k[N],out[N],v[N],X[N],Y[N];
	int su=0,cnt;
	namespace hx{
		const int mod=10000019;
		struct infor{
			int x,y1,y2,h;
		}q[N];
		int k[mod];
		int tot=0;
		inline void insert(int a,int b,int c)
		{
			int v=(1ll*a*N+b)%mod;
			q[++tot]=(infor){k[v],a,b,c};k[v]=tot;
		}
		inline int get(int a,int b)
		{
			int v=(1ll*a*N+b)%mod;
			for(int i=k[v];i;i=q[i].x)if(q[i].y1==a&&q[i].y2==b)return q[i].h;
			return -1;
		}
	}
	set<int>g2[N];
	inline char gc()
	{
		static char buf[1<<16],*S,*T;
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,1<<16,stdin);
			if(S==T)return EOF;
		}
		return *(S++);
	}
	#define getchar gc
	inline ll read()
	{
		char h=getchar();
		ll y=0,q=1;
		while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
		while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
		return y*q;
	}
	inline void add(int a,int b,int c){g[++su]=(edge){k[a],b,c};k[a]=su;}
	inline void change(int x,int v){cnt-=(out[x]==1);out[x]+=v;cnt+=(out[x]==1);}
	char me2;
	int main()
	{
//		cout<<((&me1-&me2)>>20)<<"!!\n";
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
		int n=read(),m=read();
		for(int a,b,i=1;i<=m;i++)a=read(),b=read(),add(b,a,i),v[i]=1,hx::insert(a,b,i),out[a]++,g2[b].insert(i),X[i]=a,Y[i]=b;
		for(int i=1;i<=n;i++)cnt+=(out[i]==1);
		int q=read();
		while(q--)
		{
			int op=read();
			if(op==1)
			{
				int x=read(),y=read(),h=hx::get(x,y);
				v[h]=0;change(x,-1);g2[y].erase(h);
			}
			else if(op==2)
			{
				int x=read();
				for(ite it=g2[x].begin();it!=g2[x].end();it++)
				{
					int h=*it,y=X[h];
					if(v[h])v[h]=0,change(y,-1);
				}
			}
			else if(op==3)
			{
				int x=read(),y=read(),h=hx::get(x,y);
				v[h]=1;change(x,1);g2[y].insert(h);
			}
			else
			{
				int x=read();
				for(int i=k[x];i;i=g[i].x)
				{
					int y=g[i].y,h=g[i].z;
					if(!v[h])v[h]=1,change(y,1),g2[x].insert(h);
				}
			}
			puts(cnt==n?"YES":"NO");
		}
		return 0;
	}
}
int main(){return shik::main();}
