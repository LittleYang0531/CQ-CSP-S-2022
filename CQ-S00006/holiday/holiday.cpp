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
	int n,m,k;
	const int maxn=2505;
	int dis[maxn][maxn];
	long long s[maxn];
	const int maxm=20006;
	int q[maxm],ql,qr;
	int lst[maxn],nxt[maxm],ed[maxm],et;
	inline void addedge(int x,int y) {
		ed[++et]=y,nxt[et]=lst[x],lst[x]=et;
		return ;
	}
	const int inf=0x3f3f3f3f;
	inline void calc(int s) {
		q[ql=qr=1]=s;
		rep(i,n)dis[s][i]=inf;
		dis[s][s]=0;
		while(ql<=qr) {
			R int u=q[ql++];
			for(R int i=lst[u]; i; i=nxt[i]) {
				R int v=ed[i];
				if(dis[s][v]>dis[s][u]+1) {
					dis[s][v]=dis[s][u]+1;
					q[++qr]=v;
				}
			}
		}
		return ;
	}
	int flag[maxn];
	struct sss {
		int id[3]= {};
		inline void operator+=(const int &b) {
#define fir id[0]
#define sec id[1]
#define thi id[2]
			if(s[fir]<s[b]) {
				thi=sec,sec=fir,fir=b;
			} else if(s[sec]<s[b]) {
				thi=sec,sec=b;
			} else if(s[thi]<s[b]) {
				thi=b;
			}
#undef fir
#undef sec
#undef thi
			return ;
		}
	} cho[maxn];
	int _main(void) {
		n=rint(),m=rint(),k=rint();
		++k;
		for(R int i=2; i<=n; ++i)s[i]=rll();
		rep(i,m) {
			R int u=rint(),v=rint();
			addedge(u,v),addedge(v,u);
		}
		rep(i,n)calc(i);
		for(R int i=2; i<=n; ++i) {
			if(dis[1][i]<=k)flag[i]=1;
		}
		for(R int i=2; i<=n; ++i) {
			if(flag[i]) {
				for(R int j=2; j<=n; ++j) {
					if(i!=j) {
						if(dis[i][j]<=k)cho[j]+=i;
					}
				}
			}
		}
		long long ans=0;
		for(R int i=2; i<=n; ++i) {
			for(R int j=2; j<=n; ++j) {
				if(i!=j&&dis[i][j]<=k) {
					R int k=0,l=0;
					if(cho[i].id[k]==j)++k;
					if(cho[j].id[l]==i)++l;
					if(cho[i].id[k]==cho[j].id[l]) {
						R int nx1=cho[i].id[k+1]==j?cho[i].id[k+2]:cho[i].id[k+1];
						R int nx2=cho[j].id[l+1]==i?cho[j].id[l+2]:cho[j].id[l+1];
//						printf("%d %d %d %d\n",i,j,cho[i].id[k],cho[i].id[l]);
						if(cho[i].id[k]&&nx2)ans=std::max(ans,s[i]+s[j]+s[cho[i].id[k]]+s[nx2]);
						if(nx1&&cho[j].id[l])ans=std::max(ans,s[i]+s[j]+s[nx1]+s[cho[j].id[l]]);
					} else {
						if(cho[i].id[k]&&cho[j].id[l])ans=std::max(ans,s[i]+s[j]+s[cho[i].id[k]]+s[cho[j].id[l]]);
//						printf("%d %d %d %d %lld\n",i,j,cho[i].id[k],cho[j].id[l],ans);
//						printf("%d\n",cho[i].id[k]==cho[j].id[l]);
					}
				}
			}
		}
		wrt(ans);
		return flu(),0;
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	return fck_up::_main();
}

