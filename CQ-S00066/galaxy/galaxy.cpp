#include<bits/stdc++.h>
namespace ifzw{
#define ll long long
#define dd double
#define LL __int128
#define ull unsigned ll
#define uLL __uint128_t 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=5e5+5;
int n,m,Q;
int uu[xx],vv[xx];
struct nod
{
	int to,id;
};
vector<nod>v[xx],r[xx];
unordered_map<ll,int>mp;
int in[xx],out[xx],cr[xx];
namespace bf
{
	void solve()
	{
		for(int i=1;i<=m;i++)in[vv[i]]++,out[uu[i]]++,cr[i]=1;
		while(Q--)
		{
			int op=read();
			if(op==1)
			{
				int x=read(),y=read();
				in[y]--,out[x]--;
				cr[mp[1000000ll*x+y]]=0;
			}
			if(op==3)
			{
				int x=read(),y=read();
				in[y]++,out[x]++;
				cr[mp[1000000ll*x+y]]=1;
			}
			if(op==2)
			{
				int x=read();
				for(auto it:r[x])
					if(cr[it.id])in[x]--,out[it.to]--,cr[it.id]=0;
			}
			if(op==4)
			{
				int x=read();
				for(auto it:r[x])
					if(!cr[it.id])in[x]++,out[it.to]++,cr[it.id]=1;
			}
			int ce=1;
			for(int i=1;i<=n;i++)if(out[i]!=1)ce=0;
			if(ce)puts("YES");
			else puts("NO");
		}
	}
}
struct qu
{
	int op,x,y;
}e[xx];
namespace no4
{
	int on[xx];
	vector<int>lin[xx];
	int num=0;
	void dec(int x)
	{
		num-=(out[x]!=1);
		--out[x];
		num+=(out[x]!=1);
	}
	void inc(int x)
	{
		num-=(out[x]!=1);
		++out[x];
		num+=(out[x]!=1);
	}
	void solve()
	{
		for(int i=1;i<=m;i++)in[vv[i]]++,out[uu[i]]++,cr[i]=1;
		for(int i=1;i<=n;i++)num+=(out[i]!=1);
		for(int I=1;I<=Q;I++)
		{
			int op=e[I].op;
			if(op==1)
			{
				int x=e[I].x,y=e[I].y;
				in[y]--,dec(x);
				int id=mp[1000000ll*x+y];
				cr[id]=0;
				lin[y].push_back(id);
			}
			if(op==3)
			{
				int x=e[I].x,y=e[I].y;
				in[y]++,inc(x);
				int id=mp[1000000ll*x+y];
				cr[id]=1;
				lin[y].push_back(id);
			}
			if(op==2)
			{
				int x=e[I].x;
				for(auto it:lin[x])
				{
					int to=uu[it],id=it;
					if(cr[id])in[x]--,dec(to),cr[id]=0;
				}
				if(!on[x])
				{
					on[x]=1;
					for(auto it:r[x])
						if(cr[it.id])in[x]--,dec(it.to),cr[it.id]=0;
				}
				lin[x].clear();
			}
			if(op==4)
			{
				assert(0);
			}
			
			if(!num)puts("YES");
			else puts("NO");
		}
	}
}
int d[xx];
//每个 1 旁边不能有 dlt >0 的。 
int on[xx];
vector<int>w[xx];
char ED;
int main(){
//	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		uu[i]=a,vv[i]=b;
		v[a].push_back({b,i}),r[b].push_back({a,i});
		mp[1000000ll*a+b]=i;
	}
	Q=read();
	if(n<=1000&&m<=10000&&Q<=1000)
	{
		bf::solve();
		exit(0);
	}
	for(int i=1;i<=Q;i++)
	{
		e[i].op=read(),e[i].x=read();
		if(e[i].op==1||e[i].op==3)e[i].y=read();
	}
	
	int ce=1;
	for(int i=1;i<=Q;i++)
	if(e[i].op==4)ce=0;
	if(ce)
	{
		no4::solve(),exit(0);
	}
	
//	for(int i=1;i<=n;i++)d[i]=i;
//	
//	sort(d+1,d+n+1,[&](int a,int b){return r[a].size()>r[b].size();});
//	
//	int tt=m;
//	
//	for(int i=1;i<=m;i++)in[vv[i]]++,out[uu[i]]++,cr[i]=1;
//	
//	for(int i=1;i<=500;i++)vis[i]=1,on[i]=1;
//	
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
//	
//	for(int i=1;i<=n;i++)num+=(out[i]!=1);
//	for(int I=1;I<=Q;I++)
//	{
//		int op=e[I].op;
//		if(op==1)
//		{
//			int x=e[I].x,y=e[I].y;
//			in[y]--,dec(x);
//			int id=mp[1000000ll*x+y];
//			cr[id]=0;
//			lin[y].push_back(id);
//		}
//		if(op==3)
//		{
//			int x=e[I].x,y=e[I].y;
//			in[y]++,inc(x);
//			int id=mp[1000000ll*x+y];
//			cr[id]=1;
//			lin[y].push_back(id);
//		}
//		if(op==2)
//		{
//			int x=e[I].x;
//			for(auto it:lin[x])
//			{
//				int to=uu[it],id=it;
//				if(cr[id])in[x]--,dec(to),cr[id]=0;
//			}
//			if(!on[x])
//			{
//				on[x]=1;
//				for(auto it:r[x])
//					if(cr[it.id])in[x]--,dec(it.to),cr[it.id]=0;
//			}
//			lin[x].clear();
//		}
//		if(op==4)
//		{
//			int x=e[I].x;
//			for(auto it:lin[x])
//			{
//				int to=uu[it],id=it;
//				if(cr[id])in[x]--,dec(to),cr[id]=0;
//			}
//			assert(0);
//		}
//		if(tt==n)
//		{
//			
//		}
//		if(!num)puts("YES");
//		else puts("NO");
//	}
//	
	//这个根号分治也不能做。 
	
	/*
	for(int i=1;i<=n;i++)d[i]=i;
	
	sort(d+1,d+n+1,[&](int a,int b){return r[a].size()>r[b].size();});
	
	int tt=m;
	
	for(int i=1;i<=400;i++)vis[d[i]]=1,on[d[i]]=1;
	
	for(int i=1;i<=m;i++)if(!vis[vv[i]])out[uu[i]]++;
	
	for(int i=1;i<=n;i++)
		for(auto it:v[i])if(vis[it.to])w[i].push_back(it.to);
	
	for(int i=1;i<=n;i++)
	{
		if(out[i]>0)
			for(auto it:w[i])use[it]++;
	}
	
	for(int I=1;I<=Q;I++)
	{
		int op=e[I].op;
		if(op==1)
		{
			int x=e[I].x,y=e[I].y;
			--tt,out[x]--;
			if(out[x]==0)
			{
				for(auto it:w[x])use[it]--;
			}
			lin[y].push_back({x,1});
		}
		if(op==3)
		{
			int x=e[I].x,y=e[I].y;
			++tt,out[x]++;
			if(out[x]==1)
			{
				for(auto it:w[x])use[it]++;
			}
			lin[y].push_back({x,3});
		}
		if(op==2)
		{
			int x=e[I].x;
			for(auto it:lin[x])
			{
				int to=it.first;
				if(it.op==1)
				{
					out[to]++;
					if(out[to]==1)
						for(auto it:w[to])use[it]++;
				}
				else 
				{
					out[to]--;
					if(out[to]==0)
						for(auto it:w[to])use[it]--;
				}
			}
			if(!vis[x])
			{
				if(on[x])
				{
					on[x]=0;
					for(auto it:r[x])
					{
						
					}
						if(cr[it.id])in[x]--,dec(it.to),cr[it.id]=0;
				}
			}
			if(!on[x])
			{
				on[x]=1;
				for(auto it:r[x])
					if(cr[it.id])in[x]--,dec(it.to),cr[it.id]=0;
			}
			else 
			{
				
			}
			lin[x].clear();
		}
		if(op==4)
		{
			int x=e[I].x;
			for(auto it:lin[x])
			{
				int to=uu[it],id=it;
				if(cr[id])in[x]--,dec(to),cr[id]=0;
			}
			assert(0);
		}
		if(tt==n)
		{
			
		}
		if(!num)puts("YES");
		else puts("NO");
	}*/
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}
