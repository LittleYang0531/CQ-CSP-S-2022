#include <bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
using namespace std;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
map<int,int>M[500005];
vector <int> G[500005];
vector <int> G_[500005];
int cnt,Out[500005],Ban[500005];
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	int n,m,NowE;read(n);read(m);NowE=m;
	for(int i=1,u,v;i<=m;i++)
	{
		read(u);read(v);
		Out[u]++;
		M[u][v]=i;
		G[u].push_back(v);
		G_[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cnt+=(Out[i]==1);
	int q;read(q);
	while(q--)
	{
		int op,x,y;
		read(op);read(x);
		if(op==1||op==3) read(y);
		if(op==1)
		{
			NowE--; Ban[M[x][y]]=true;
			if(Out[x]==1) cnt--;
			Out[x]--;
			if(Out[x]==1) cnt++;
		}
		if(op==2)
		{
			y=x;
			for(int i=0;i<G_[y].size();i++)
			{
				x=G_[y][i];
				if(!Ban[M[x][y]])
				{
					NowE--; Ban[M[x][y]]=true;
					if(Out[x]==1) cnt--;
					Out[x]--;
					if(Out[x]==1) cnt++;
				}
			}
		}
		if(op==3)
		{
			NowE++; Ban[M[x][y]]=false;
			if(Out[x]==1) cnt--;
			Out[x]++;
			if(Out[x]==1) cnt++;
		}
		if(op==4)
		{
			y=x;
			for(int i=0;i<G_[y].size();i++)
			{
				x=G_[y][i];
				if(Ban[M[x][y]])
				{
					NowE++; Ban[M[x][y]]=false;
					if(Out[x]==1) cnt--;
					Out[x]++;
					if(Out[x]==1) cnt++;
				}
			}
		}
		puts(cnt==n?"YES":"NO");
	}
	return 0;
}
/*
清夜无尘，月色如银，酒斟时，须满十分；浮名浮利，虚苦劳神，叹隙中驹，石中火，梦中身。
虽抱文章，开口谁亲，且陶陶，乐尽天真；几时归去，作个闲人，对一张琴，一壶酒，一溪云。

也就是是否基环树森林 
*/

