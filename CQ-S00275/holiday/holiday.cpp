#include<bits/stdc++.h> 
using namespace std;
#define rt register
int n,m,k,f,t,root[100010],idx,vis[100010];
long long a[100010],ans;
struct Scarlet{
	int to,pre;
}mp[100010];
inline int read()
{
	int platinum=0,lucadio=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') lucadio=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		platinum=(platinum<<1)+(platinum<<3)+(ch^48);
		ch=getchar();
	}
	return platinum*lucadio;
}
inline void add(int f,int t)
{
	mp[++idx].to=t;
	mp[idx].pre=root[f];
	root[f]=idx;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(rt int i=1;i<=n-1;i++) scanf("%lld",&a[i]);
	for(rt int i=1;i<=m;i++)
	{
		f=read(),t=read();
		add(f,t);
		add(t,f);
	}
	sort(a+1,a+n);
	for(rt int i=n-1;i>=n-4;i--)
	{
		ans+=a[i];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
