#include<bits/stdc++.h>
using namespace std;
#define rt register
int n,m,k,f,t,root[1000010],die[2010][2010],idx,p,x,y,flag,in[1000010],out[1000010],ct;
struct Scarlet{
	int to,pre;
}mp[1000010];
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
inline int check()
{
	queue<int> qq;
	for(rt int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			qq.push(i);
		}
	}
	while(qq.size())
	{
		int p=qq.front();
    	qq.pop();
	    for(rt int i=root[p];i;i=mp[i].pre)
    	{
    		int to=mp[i].to;
    		in[to]--;
	    	if(in[to]==0)
	    	{
		    	qq.push(to);
	    	}
    	}
	}
	for(rt int i=1;i<=n;i++)
	{
		if(in[i]!=0) return 1; //»¹ÓÐÊ£ÏÂ 
	}
	return 0;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(rt int i=1;i<=m;i++)
	{
		f=read(),t=read();
		add(f,t);
		in[t]++;
		out[f]++;
	}
	k=read();
	for(rt int i=1;i<=k;i++)
	{
		p=read();
		flag=0;
		if(p==1)
		{
			x=read(),y=read();
			die[x][y]=1;
			in[y]--;
			out[x]--;
		}
		else if(p==2)
		{
			x=read();
			for(rt int i=1;i<=n;i++)
			{
				if(i!=x)
				{
					for(rt int j=root[i];j;j=mp[j].pre)
					{
						if(mp[j].to==x)
						{
							die[i][x]=1;
							in[x]--;
							out[i]--;
						}
					}
				}
			}
		}
		else if(p==3)
		{
			x=read(),y=read();
			if(die[x][y]) in[y]++,out[x]++;
			die[x][y]=0;
		}
		else if(p==4)
		{
			x=read();
			for(rt int i=1;i<=n;i++)
			{
				if(i!=x)
				{
					for(rt int j=root[i];j;j=mp[j].pre)
					{
						if(mp[j].to==x)
						{
							if(die[i][x]) in[x]++,out[i]++;
							die[i][x]=0;
						}
					}
				}
			}
		}
		for(rt int i=1;i<=n;i++)
		{
			ct=0;
			for(rt int j=root[i];j;j=mp[j].pre)
			{
				int to=mp[j].to;
				if(die[i][to]==0) ct++;
			}
			if(ct!=1) flag=1;
		}
		if(check()&&flag==0) printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);
	fclose(stdout);
}
