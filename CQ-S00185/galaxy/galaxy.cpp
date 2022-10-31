#include<bits/stdc++.h>
using namespace std;
int n,m,u,uu,q,t,sum;
vector<int> v[500005],vv[500005];
int s[500005];
map<pair<int,int>,bool> mp;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d%d",&u,&uu),v[u].push_back(uu),vv[uu].push_back(u);
	scanf("%d",&q);
	for(int i=1; i<=n; ++i) s[i]=v[i].size(),sum+=(s[i]!=1);
	while(q--)
	{
//		cout<<sum<<" ";
//		for(int i=1; i<=n; ++i) cout<<s[i]<<" ";
		scanf("%d%d",&t,&u);
		if(t==1 || t==3) scanf("%d",&uu);
		if(t==1)
		{
			mp[make_pair(u,uu)]=1,--s[u];
			if(s[u]==1) --sum;
			if(s[u]==0) ++sum;
		}
		if(t==2)
		{
			for(int i=0; i<vv[u].size(); ++i)
			{
				int x=vv[u][i];
				if(!mp[make_pair(x,u)])
				{
					mp[make_pair(x,u)]=1,--s[x];
					if(s[x]==1) --sum;
					if(s[x]==0) ++sum;
				}
			}
		}
		if(t==3)
		{
			mp[make_pair(u,uu)]=0,++s[u];
			if(s[u]==1) --sum;
			if(s[u]==2) ++sum;
		}
		if(t==4)
		{
			for(int i=0; i<vv[u].size(); ++i)
			{
				int x=vv[u][i];
				if(mp[make_pair(x,u)])
				{
					mp[make_pair(x,u)]=0,++s[x];
					if(s[x]==1) --sum;
					if(s[x]==2) ++sum;
				}
			}
		}
		if(sum==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
