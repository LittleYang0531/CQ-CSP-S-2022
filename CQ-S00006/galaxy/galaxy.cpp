#include<bits/stdc++.h>
#define R register
#define rep(i,n) for(R int i=1;i<=(int)n;++i)
#define rep0(i,n) for(R int i=0;i<(int)n;++i)
const int maxbuf=1<<21;
char buf[maxbuf],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxbuf,stdin),p1==p2)?EOF:*p1++)
inline int rint(void) {
	R int x=0,flag=0;
	char c=GC;
	while((c<'0'||c>'9')&&c!='-') {
		c=GC;
	}
	if(c=='-') {
		c=GC,flag=1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48,c=GC;
	}
	return flag?-x:x;
}
inline long long rll(void) {
	R long long x=0;
	R int flag=0;
	char c=GC;
	while((c<'0'||c>'9')&&c!='-') {
		c=GC;
	}
	if(c=='-') {
		c=GC,flag=1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48,c=GC;
	}
	return flag?-x:x;
}
const int maxlimit=1<<20;
char pbuf[maxbuf],*pp=pbuf;
inline void flu(void) {
	fwrite(pbuf,1,pp-pbuf,stdout),pp=pbuf;
	return ;
}
int top;
char sta[35];
inline void wrt(int x) {
	if(pp-pbuf>=maxlimit)flu();
	if(x==0)*pp++='0';
	else {
		if(x<0)x=-x,*pp++='-';
		top=0;
		do {
			sta[++top]=x%10+48,x/=10;
		} while(x);
		while(top)*pp++=sta[top--];
	}
	*pp++='\n';
	return ;
}
inline void wrt(long long x) {
	if(pp-pbuf>=maxlimit)flu();
	if(x==0)*pp++='0';
	else {
		if(x<0)x=-x,*pp++='-';
		top=0;
		do {
			sta[++top]=x%10+48,x/=10;
		} while(x);
		while(top)*pp++=sta[top--];
	}
	*pp++='\n';
	return ;
}
namespace fck_up {
	int n,m;
	const int maxn=500005;
	std::set<int > son[maxn],lft[maxn];
	int flag,dg[maxn];
	int _main(void) {
		n=rint(),m=rint();
		rep(i,m) {
			R int x=rint(),y=rint();
			son[y].insert(x);
			++dg[x];
		}
		int q=rint(),now=m;
		rep(i,n)if(dg[i]!=1)++flag;
		while(q--) {
			R int op=rint();
			if(op==1||op==3) {
				R int x=rint(),y=rint();
				if(op==1) {
					lft[y].insert(x);
					son[y].erase(x);
					--dg[x];
					if(dg[x]==0)++flag;
					else if(dg[x]==1)--flag;
					--now;
				} else {
					if(son[y].find(x)==son[y].end()) {
						son[y].insert(x);
						lft[y].erase(x);
						++now;
						++dg[x];
						if(dg[x]==2)++flag;
						else if(dg[x]==1)--flag;
					}
				}
			} else {
				R int u=rint();
				if(op==2) {
					now-=(int)son[u].size();
					for(R int v:son[u]) {
						lft[u].insert(v);
						--dg[v];
						if(dg[v]==0)++flag;
						else if(dg[v]==1)--flag;
					}
					son[u].clear();
				} else {
					now+=(int)lft[u].size();
					for(R int v:lft[u]) {
						son[u].insert(v);
						++dg[v];
						if(dg[v]==2)++flag;
						else if(dg[v]==1)--flag;
					}
					lft[u].clear();
				}
			}
//			printf("%d %d\n",now,flag);
//			rep(i,n)printf("%d ",dg[i]);
//			printf("\n");
			if(now==n&&!flag)*pp++='Y',*pp++='E',*pp++='S';
			else *pp++='N',*pp++='O';
			*pp++='\n';
			if(pp-pbuf>=maxlimit)flu();
		}
		return flu(),0;
	}
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	return fck_up::_main();
}

