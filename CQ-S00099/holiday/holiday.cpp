#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int x,y;
long long a[2510];
vector<int> b[10010];
long long sum;
int c[2510];
int aa[2510];
void dfs(int x,int h)
{
	c[x]=min(c[x],h);
	for(int i=0;i<b[x].size();i++)
	{
		int ss=b[x][i];
		if(aa[ss]==0)
		{
			aa[ss]=1;
			dfs(ss,h+1);
			//aa[ss]=0;
		}
	}
}
int abs(int x,long long t,int ab)
{
	for(int ak=0;ak<b[x].size();ak++)
	{
		int ss=b[x][ak];
		if(aa[ss]==0&&t<=a[ss])
		{
			t=a[ss];
			ab=ss;
		}
	}
	aa[ab]=1;
	return ab;
}
void dfs1(int x,long long s,int abc)
{
	s+=a[x];
	if(abc==4)
	{
		for(int i=0;i<b[x].size();i++)
		    if(b[x][i]==1)
		    {
		    	sum=max(s,sum);
		    	return ;
			}
		return ;
	}
	for(int i=0;i<b[x].size();i++)
	    dfs1(b[x][i],s,abc+1);
}
int main() 
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
    cin>>n>>m>>k;
	c[1]=1e9;
	for(int i=2;i<=n;i++)
    {
	    cin>>a[i];
	    c[i]=1e9;
	}
    for(int i=1;i<=m;i++)
    {
    	cin>>x>>y;
    	b[x].push_back(y);
    	b[y].push_back(x);
	}
	aa[1]=1;
	dfs(1,1);
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(c[j]-c[i]<=k+1&&c[j]-c[i]>1)
    		{
    			b[i].push_back(j);
    	        b[j].push_back(i);
			}
			int t=0;
            for(int add=0;add<b[1].size();add++)
            {
                if(b[1][add]==j)
                {
                    t=1;
                    break;
                }
            }
            if(t==1&&c[j]+c[i]+2<=k)
            {
			    b[i].push_back(j);
    	        b[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	    aa[i]=0;
	int l=1;
	for(int i=0;i<b[1].size();i++)
		dfs1(b[1][i],0,1);
	cout<<sum;
	cout<<endl;
	return 0;
}
