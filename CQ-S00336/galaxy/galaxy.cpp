#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(a,b) for(int a=1;a<=b;++a)
#define F first
#define S second
typedef pair<int,int> pii;
const int nx=500050,mx=500050,inf=0x3f3f3f3f;
inline int read()
{
	int x=0;
	bool f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=1;
		ch=getchar();
	}
	while('0'<=ch&&'9'>=ch)
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
int v[nx],bk[mx],cnt=1,q,n,m;
struct node
{
	int out,in;
	vector<int>ego,egi;
	node()
	{
		out=in=0;
	}
	int rr()
	{
		in=egi.size();
		return out=ego.size();
	}
} lf[nx];
int far[nx];
bool rd[nx];
int fa(int x)
{
	return far[x]==x?x:far[x]=fa(far[x]);
}
map<int,pii>mp;
map<pii,int>mq;
bool rch()
{
	for(int i=1; i<=n; ++i)far[i]=i,rd[i]=0;
	for(int i=0; i<m; i++)
		if(!bk[i])
			if(fa(mp[i].F)==fa(mp[i].S))rd[far[mp[i].F]]=1;
			else
			{
				far[fa(mp[i].S)]=fa(mp[i].F);
				if(fa(mp[i].F)==fa(mp[i].S))rd[far[mp[i].F]]=1;
			}
	for(int i=1; i<=n; ++i)if(!rd[fa(i)])return 0;
	return 1;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=0; i<m; i++)
	{
		int f=read(),t=read();
		lf[f].ego.push_back(cnt),lf[t].egi.push_back(cnt);
		mq[pii(f,t)]=cnt;
		mp[cnt++]=pii(f,t);
	}
	int num=0;
	for(int i=1; i<=n; i++)
		if(lf[i].rr()>1)++num;
	q=read();
	while(q--)
	{
		int does=read();
		if(does==1)
		{
			int a=read(),b=read();
			lf[b].in--;
			bk[mq[pii(a,b)]]=1;
			if(--lf[a].out==1)--num;
			if(lf[a].out==0)++num;
		}
		else if(does==2)
		{
			int a=read(),s=lf[a].egi.size() ;
			node b=lf[a];
			for(int i=0; i<s; i++)
				if(!bk[b.egi[i]])
				{
					bk[b.egi[i]]=1;
					if(--lf[mp[b.egi[i]].F].out==1)--num;
					if(lf[mp[b.egi[i]].F].out==0)++num;
				}
		}
		else if(does==3)
		{
			int a=read(),b=read();
			lf[b].in++;
			bk[mq[pii(a,b)]]=0;
			if(++lf[a].out==2)++num;
			if(lf[a].out==1)--num;
		}
		else
		{
			int a=read(),s=lf[a].egi.size() ;
			node b=lf[a];
			for(int i=0; i<s; i++)
				if(bk[b.egi [i]])
				{
					bk[b.egi [i]]=0;
					if(++lf[mp[b.egi [i]].F].out==1)--num;
					if(lf[mp[b.egi [i]].F].out==2)++num;
				}
		}
		if(!num)printf("%s\n",rch()?"Yes":"No");
		else printf("No\n");
	}
}
