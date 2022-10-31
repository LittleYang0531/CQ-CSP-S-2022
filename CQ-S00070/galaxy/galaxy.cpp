#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
typedef long long ll;
const int maxn=500002,mod=998244353;
const int inf=(1<<30);
using namespace std;
int ask(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int n,m,q;
struct str{
	priority_queue<int>q1,q2;
	void push(int x)
	{
		q1.push(x);
	}
	void pop(int x)
	{
		q2.push(x);
	}
	bool empty()
	{
		return !(q1.size()-q2.size());
	}
	int top()
	{
		while(q1.size()&&q2.size()&&q1.top()==q2.top())
		{
			q1.pop();
			q2.pop();
		}
		return q1.top();
	}
}a[maxn],b[maxn];
int d[maxn];
int ans;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		a[y].push(x);
		if(d[x]==1)ans--;
		d[x]++;
		if(d[x]==1)ans++;
	}
	q=read();
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read();
			a[y].pop(x);
			if(d[x]==1)ans--;
			d[x]--;
			if(d[x]==1)ans++;
			b[y].push(x);
		}else if(op==2)
		{
			int x=read();
			while(!a[x].empty())
			{
				int w=a[x].top();
				if(d[w]==1)ans--;
				d[w]--;
				if(d[w]==1)ans++;
				b[x].push(w);
				a[x].pop(w);
			}
		}else if(op==3)
		{
			int x=read(),y=read();
			a[y].push(x);
			if(d[x]==1)ans--;
			d[x]++;
			if(d[x]==1)ans++;
			b[y].pop(x);
		}else
		{
			int x=read();
			while(!b[x].empty())
			{
				int w=b[x].top();
				a[x].push(w);
				if(d[w]==1)ans--;
				d[w]++;
				if(d[w]==1)ans++;
				b[x].pop(w);
			}
		}
		if(ans==n)puts("YES");
		else puts("NO");
	}
	return 0;
}
