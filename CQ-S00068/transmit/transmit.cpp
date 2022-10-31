#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,next;
}e[400005];
int n,h[200005],cnt,q,k;
long long v[200005];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
int prt[200005],d[200005];
int f[200005][26];
void dfs(int root,int father)
{
	for(int i=h[root];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==father)continue;
		prt[y]=root;	
		d[y]=d[root]+1;
		dfs(y,root);
	}
}
void prepare()
{
	for(int i=1;i<=n;i++)prt[i]=i;
	d[1]=1;
	f[1][0]=0;
	dfs(1,-1);
	for(int i=1;i<=n;i++)f[i][0]=prt[i];
//	for(int i=1;i<=n;i++)cout<<f[i][0]<<' ';
//	cout<<endl;
	for(int j=1;j<=25;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int j=25;j>=0;j--)
	{
		if(d[f[x][j]]>=d[y])x=f[x][j];
	}
	if(d[x]>d[y])x=f[x][0];
	if(x==y)return y;
	for(int j=25;j>=0;j--)
	{
		if(f[x][j]!=f[y][j])
		{
			
			x=f[x][j];
			y=f[y][j];
		}
	}
//	cout<<"lca: "<<x<<' '<<y<<' '<<f[x][0]<<' '<<f[y][0]<<'\n';
	if(x!=y)
	{
		x=f[x][0];
		y=f[y][0];
	}

	return y;
}
int fqr[200005]; 
void work()
{
	int s,t;
	long long sum=0;
	cin>>s>>t;
	int pos=lca(s,t);
	sum+=v[t]+v[s];
//	cout<<"now: "<<s<<' '<<t<<' '<<pos<<'\n';
	int tmp=d[s]-d[pos];
	int dmp=d[t]-d[pos];
	int num=0;
	int rez;
	if(tmp+dmp>k)
	{
		int ans=(tmp+dmp)/k;
		rez=s;	
		while(rez!=pos)
		{		
			rez=prt[rez];
			int now=v[rez];
			fqr[++num]=now;
		}
		rez=t;	
		while(rez!=pos)
		{
			rez=prt[rez];
			int now=v[rez];
			if(rez!=pos)fqr[++num]=now;
		}		
		sort(fqr+1,fqr+1+num);
//		cout<"fqr:\n";
//		for(int i=1;i<=num;i++)cout<<fqr[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=ans;i++)sum+=fqr[i];
//		cout<<"ans: "<<ans<<'\n';
	}
	cout<<sum<<'\n';		
}
int main()
{	
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	prepare();
	while(q--)work();
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7
*/
