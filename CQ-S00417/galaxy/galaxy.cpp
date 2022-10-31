#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct asd
{
	int nxt,to;
	bool flag;
}e[1000000];
int head[1000000],cnt;
bool mar[1000000];
int tot;
void ad(int u,int v)
{
	e[++cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
	e[cnt].flag=1;
}
void del(int u,int v)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(e[i].to==v)
		{
			e[i].flag=0;
			return;
		}
	}
}
void ret(int u,int v)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(e[i].to==v)
		{
			e[i].flag=1;
			return;
		}
	}
	mar[v]=1;
}
bool mark[1000000];
bool pd()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		memset(mark,0,sizeof(0));
		queue<int> s;
		s.push(i);
		while(!s.empty())
		{
			int u=s.front();
			s.pop();
			mark[u]=1;
			int az=0;
			for(int j=head[u];j;j=e[j].nxt)
			{
				int v=e[j].to;
				if(e[j].flag==0)continue;
				if(mar[v]==1)continue;	
				if(mark[v]==1)
				{
					res++;
					break;
				}
			
				s.push(v);
			}
			if(res==i)break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int az=0;
		for(int j=head[i];j;j=e[j].nxt)
		{
			if(e[j].flag==1)az++;
			if(az>1)return 0;
		}
	}
	if(res==n)return 1;
	return 0;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		ad(u,v);
	}
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			int u,v;
			cin>>u>>v;
			del(u,v);
			if(pd())
			{
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
			continue;
		}
		if(x==2)
		{
			int num;
			cin>>num;
			mar[num]=1;
			tot--;
			cout<<"NO"<<endl;
			continue;
		}
		if(x==3)
		{
			int u,v;
			cin>>u>>v;
			ret(u,v);
			if(pd())
			{
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
			continue;
		}
		if(x==4)
		{
			int num;
			cin>>num;
			if(mar[num])tot++;
			mar[num]=0;
			if(pd())
			{
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*


*/
