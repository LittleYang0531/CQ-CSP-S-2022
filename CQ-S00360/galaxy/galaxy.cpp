//sto Lisdery orz
//sto Mu_tr orz
//sto ryhuang orz
//sto piggydan orz
//sto MrXBJ orz
//sto PPYYHH orz
//sto LittleYang orz
//sto hualian orz
//sto moyujiang orz
//sto zjy orz
//sto unreachable orz
//sto shuaizui orz
//sto lmgoat orz
//sto my_grandson orz
//sto gyh20 orz
//sto feecle6418 orz
//sto mazihang2022 orz
//sto Prean orz
//sto Leasier orz
//sto OhtoAi orz
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
const int N=5e5+10,M=N<<1;
int n,m,q,u[M],v[M],out[N];
int first[N],to[M],nxt[M],cnt;
bool vis[N],able[M],loop[N];
inline void inc(int x,int y) {nxt[++cnt]=first[x],to[cnt]=y,first[x]=cnt;}
void add(int x)
{
	if(out[x]==1) ++cnt;
	++out[x];
	if(out[x]==1) --cnt;
}
void del(int x)
{
	if(out[x]==1) ++cnt;
	--out[x];
	if(out[x]==1) --cnt;
}
void dfs(int x)
{
	if(vis[x]) return loop[x]=1,void();
	vis[x]=1;
	for(int i=first[x],v;i;i=nxt[i])
	{
		if(!able[i]) continue;
		dfs(to[i]);
		loop[x]|=loop[to[i]];
	}
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		inc(u[i],v[i]);able[i]=1;
	}
	cnt=0;
	for(int i=1;i<=m;i++) ++out[u[i]];
	for(int i=1;i<=n;i++) cnt+=(out[i]!=1);
	q=read();
	int opt,x,y;
L:	while(q--)
	{
		opt=read(),x=read();
		if(opt&1) y=read();
		switch(opt)
		{
			case 1:{
				del(x);
				for(int i=1;i<=m;i++)
					if(u[i]==x&&v[i]==y) {able[i]=0;break;}
				break;
			}
			case 2:{
				for(int i=1;i<=m;i++)
					if(v[i]==x&&able[i]) able[i]=0,del(u[i]);
				break;
			}
			case 3:{
				add(x);
				for(int i=1;i<=m;i++)
					if(u[i]==x&&v[i]==y) {able[i]=1;break;}
				break;
			}
			case 4:{
				for(int i=1;i<=m;i++)
					if(v[i]==x&&!able[i]) able[i]=1,add(u[i]);
				break;
			}
		}
		if(cnt) {puts("NO");goto L;}
		for(int i=1;i<=n;i++) vis[i]=loop[i]=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]) dfs(i);
		for(int i=1;i<=n;i++)
			if(!loop[i]) {puts("NO");goto L;}
		puts("YES");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
