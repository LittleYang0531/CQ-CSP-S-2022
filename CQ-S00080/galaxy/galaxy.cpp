#include<bits/stdc++.h>
using namespace std;
int n,m,q,sum,mp[1003][1003],vis[500005],out[500005],in[500005],to[500005];
void judge()
{
	for(int i=1;i<=n;i++)
	{
		to[i]=i;
	}
	bool b=false,c=false;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mp[i][j]==1)
			{
				to[j]=to[i];
				//cout<<i<<" "<<j<<endl;
				in[j]++;
				out[i]++;
			}
			if(out[i]>1)
			{
				//cout<<"outrange"<<endl;
				b=true;
				break;
			}
			if(mp[i][j]==1&&mp[j][i]==1)
			{
				//cout<<"loop1"<<endl;
				c=true;
			}
		}
		if(b==true)
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<"to: "<<i<<" "<<to[i]<<" "<<to[to[i]]<<endl;
		if(out[i]!=1)
		{
			//cout<<"notenough"<<endl;
			b=true;
			break;
		}
		if(to[i]==i||i==to[to[i]])
		{
			//cout<<"loop2"<<endl;
			c=true;
			break;
		}
	}
	if(b==true||c==false)
	{
		cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int a,b,c;
		cin>>a;
		if(a==1)
		{
			cin>>b>>c;
			mp[b][c]=-1;
		}
		if(a==2)
		{
			cin>>b;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][b]==1)
				mp[j][b]=-1;
			}
		}
		if(a==3)
		{
			cin>>b>>c;
			mp[b][c]=1;
		}
		if(a==4)
		{
			cin>>b;
			for(int j=1;j<=n;j++)
			{
				if(mp[j][b]==-1)
				mp[j][b]=1;
			}
		}
		memset(in,0,sizeof(in));memset(out,0,sizeof(out));
		judge();
	}
	return 0;
}
