#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
namespace shik{
	const ll inf=4e18;
	const int N=2505,M=23333;
	struct edge{
		int x,y;
	}g[M];
	struct infor{
		int x,d;
		bool operator<(const infor &b)const{return d>b.d;}
	};
	ll v[N],ma[N],cma[N],sma[N],fma[N];
	int d[N][N],k[N],w[N],cw[N],sw[N];
	int n,lim,su=0;
	bool vis[N];
	priority_queue<infor>dl;
	inline void add(int a,int b){g[++su]=(edge){k[a],b};k[a]=su;}
	inline void dij(int st,int d[])
	{
		for(int i=1;i<=n;i++)d[i]=N,vis[i]=0;
		d[st]=0;dl.push((infor){st,0});
		while(!dl.empty())
		{
			int x=dl.top().x;dl.pop();
			if(vis[x])continue;
			vis[x]=1;
			for(int y,i=k[x];i;i=g[i].x)if(d[y=g[i].y]>d[x]+1)d[y]=d[x]+1,(d[y]<=lim?dl.push((infor){y,d[y]}):void());
		}
	}
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
//	#define getchar gc
	inline ll read()
	{
		char h=getchar();
		ll y=0,q=1;
		while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
		while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
		return y*q;
	}
	int main()
	{
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
		n=read();int m=read();lim=read()+1;ll ans=0;
		for(int i=2;i<=n;i++)v[i]=read();
		for(int a,b,i=1;i<=m;i++)a=read(),b=read(),add(a,b),add(b,a);
		dij(1,d[1]);
		for(int i=1;i<=n;i++)ma[i]=cma[i]=sma[i]=fma[i]=-inf;
		for(int i=1;i<=n;i++)if(d[1][i]<=lim&&i!=1)
		{
			dij(i,d[i]);
			for(int j=1;j<=n;j++)if(j!=1&&j!=i&&d[i][j]<=lim)
			{
//				cout<<i<<" "<<j<<"*\n";
				if(v[i]>=ma[j])fma[j]=sma[j],sma[j]=cma[j],sw[j]=cw[j],cma[j]=ma[j],cw[j]=w[j],ma[j]=v[i],w[j]=i;
				else if(v[i]>=cma[j])sma[j]=sma[j],sma[j]=cma[j],sw[j]=cw[j],cma[j]=v[i],cw[j]=i;
				else if(v[i]>=sma[j])sma[j]=sma[j],sma[j]=v[i],sw[j]=i;
				else if(v[i]>=fma[j])fma[j]=v[i];
			}
		}
		for(int i=1;i<=n;i++)if(i!=1&&d[1][i]>lim&&ma[i]>=0)dij(i,d[i]);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=1&&j!=1&&i!=j&&d[i][j]<=lim)
		{
			if(w[i]!=w[j]&&w[i]!=j&&w[j]!=i)ans=max(ans,ma[i]+ma[j]+v[i]+v[j]);
			else
			{
				if(w[i]==w[j])
				{
					if(cw[j]!=i&&w[i]!=j)ans=max(ans,ma[i]+cma[j]+v[i]+v[j]);
					else if(cw[j]==i&&w[i]==j)
					{
						if(cw[i]!=sw[j])ans=max(ans,cma[i]+sma[j]+v[i]+v[j]);
						else ans=max(ans,max(sma[i]+sma[j]+v[i]+v[j],cma[i]+fma[j]+v[i]+v[j]));
					}
					else if(cw[j]==i)
					{
						if(w[i]!=sw[j])ans=max(ans,ma[i]+sma[j]+v[i]+v[j]);
						else ans=max(ans,max(cma[i]+sma[j]+v[i]+v[j],ma[i]+fma[j]+v[i]+v[j]));
					}
					else
					{
						if(cw[i]!=cw[j])ans=max(ans,cma[i]+cma[j]+v[i]+v[j]);
						else ans=max(ans,max(sma[i]+cma[j]+v[i]+v[j],cma[i]+sma[j]+v[i]+v[j]));
					}
					swap(i,j);
					if(cw[j]!=i&&w[i]!=j)ans=max(ans,ma[i]+cma[j]+v[i]+v[j]);
					else if(cw[j]==i&&w[i]==j)
					{
						if(cw[i]!=sw[j])ans=max(ans,cma[i]+sma[j]+v[i]+v[j]);
						else ans=max(ans,max(sma[i]+sma[j]+v[i]+v[j],cma[i]+fma[j]+v[i]+v[j]));
					}
					else if(cw[j]==i)
					{
						if(w[i]!=sw[j])ans=max(ans,ma[i]+sma[j]+v[i]+v[j]);
						else ans=max(ans,max(cma[i]+sma[j]+v[i]+v[j],ma[i]+fma[j]+v[i]+v[j]));
					}
					else
					{
						if(cw[i]!=cw[j])ans=max(ans,cma[i]+cma[j]+v[i]+v[j]);
						else ans=max(ans,max(sma[i]+cma[j]+v[i]+v[j],cma[i]+sma[j]+v[i]+v[j]));
					}
					swap(i,j);
				}
				else if(w[i]==j&&w[j]==i)
				{
					if(cw[i]==cw[j])ans=max(ans,max(cma[i]+sma[j]+v[i]+v[j],sma[i]+cma[j]+v[i]+v[j]));
					else ans=max(ans,cma[i]+cma[j]+v[i]+v[j]);
				}
				else if(w[i]==j)
				{
					if(cw[i]==w[j])
					{
						ans=max(ans,sma[i]+ma[j]+v[i]+v[j]);
						if(cw[j]!=i)ans=max(ans,cma[i]+cma[j]+v[i]+v[j]);
						else ans=max(ans,cma[i]+sma[j]+v[i]+v[j]);
					}
					else ans=max(ans,cma[i]+ma[j]+v[i]+v[j]);
				}
				else
				{
					if(w[i]==cw[j])
					{
						swap(i,j);
//						cout<<i<<" "<<j<<" "<<sma[i]<<" "<<ma[j]<<"!!\n";
						ans=max(ans,sma[i]+ma[j]+v[i]+v[j]);
						if(cw[j]!=i)ans=max(ans,cma[i]+cma[j]+v[i]+v[j]);
						else ans=max(ans,cma[i]+sma[j]+v[i]+v[j]);
						swap(i,j);
					}
					else ans=max(ans,ma[i]+cma[j]+v[i]+v[j]);
				}
			}
//			cout<<i<<" "<<j<<"::"<<w[i]<<" "<<w[j]<<" "<<ans<<"^^\n";
		}
		cout<<ans<<"\n";
		return 0;
	}
}
int main(){return shik::main();}
