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
	int n,q,k;
	const int maxn=2e5+5;
	int a[maxn];
	const int maxm=4e5+5;
	int lst[maxn],nxt[maxm],ed[maxm],et;
	inline void addedge(int x,int y) {
		ed[++et]=y,nxt[et]=lst[x],lst[x]=et;
		return ;
	} const long long infll=0x3f3f3f3f3f3f3f3f;
	long long val[maxn];
	long long val2[maxn];
	int dep[maxn];
	const int maxlog=25;
	int fMin[maxlog][maxm];
	int Lg[maxm];
	inline int dmin(const int x,const int y) {
		return dep[x]<dep[y]?x:y;
	} int fa[maxn];
	int fir[maxn],visitime;
	const int inf=0x3f3f3f3f;
	struct sss {
		int fir=0,sec=0,thi=0;
		inline void operator+=(const long long &b) {
			if(a[fir]>a[b]) {
				thi=sec,sec=fir,fir=b;
			} else if(a[sec]>a[b]) {
				thi=sec,sec=b;
			} else if(a[thi]>a[b]) {
				thi=b;
			}
		}
	} cho[maxn];
	inline void dfs(int u) {
		fMin[0][++visitime]=u,fir[u]=visitime;
		for(R int i=lst[u]; i; i=nxt[i]) {
			R int v=ed[i];
			if(v!=fa[u]) {
				fa[v]=u,val[v]=val[u]+a[v],dep[v]=dep[u]+1,dfs(v);
				fMin[0][++visitime]=u;
				cho[u]+=v;
			}
		}
		return ;
	}
	inline void initi(void) {
		for(R int i=2; i<=visitime; ++i)Lg[i]=Lg[i>>1]+1;
		for(R int j=1; j<=Lg[visitime]; ++j) {
			for(R int i=1; i+(1<<j)-1<=visitime; ++i) {
				fMin[j][i]=dmin(fMin[j-1][i],fMin[j-1][i+(1<<j-1)]);
			}
		}
		return ;
	}
	inline int lca(int x,int y) {
		x=fir[x],y=fir[y];
		if(x>y)std::swap(x,y);
		R int p=Lg[y-x+1];
		return dmin(fMin[p][x],fMin[p][y-(1<<p)+1]);
	}
	int _main(void) {
		n=rint(),q=rint(),k=rint();
		rep(i,n)a[i]=rint();
		rep(i,n-1) {
			R int u=rint(),v=rint();
			addedge(u,v),addedge(v,u);
		}
		a[0]=inf;
		val[1]=a[1],dfs(1);
		initi();
		R int maxdep=0;
		rep(i,n)maxdep=std::max(maxdep,dep[i]);
		if(k==1) {
			while(q--) {
				int s=rint(),t=rint();
				R int l=lca(s,t);
				wrt(val[s]+val[t]-val[l]*2+a[l]);
			}
		} else if(k==2) {
			if(maxdep<=150||(n<=2000&&q<=2000)) {
				while(q--) {
					int s=rint(),t=rint();
					R int l=lca(s,t);
//					printf("%d %d %d\n",s,t,a[s]+a[t]);
					R int lst[4]= {};
					val[s]=a[s],lst[0]=s,s=fa[s];
					while(s!=fa[l]) {
						val[s]=infll;
						for(R int i=0; i<k; ++i)if(lst[i])val[s]=std::min(val[s],val[lst[i]]+a[s]);
//						if(lst[2]) {
//							R int hl=cho[lst[1]].fir==lst[2]?cho[lst[1]].sec:cho[lst[2]].fir;
//							hl=a[hl];
//							R long long temp=val[lst[2]];
//							val[s]=std::min(val[s],temp+hl+a[s]);
//						}
						lst[2]=lst[1],lst[1]=lst[0],lst[0]=s;
						s=fa[s];
					}
					R int lst2[4]= {};
					val2[t]=a[t],lst2[0]=t,t=fa[t];
					while(t!=fa[l]) {
						val2[t]=infll;
						for(R int i=0; i<k; ++i)if(lst2[i])val2[t]=std::min(val2[t],val2[lst2[i]]+a[t]);
//						if(lst2[2]) {
//							R int hl=cho[lst2[1]].fir==lst2[2]?cho[lst2[1]].sec:cho[lst2[2]].fir;
//							hl=a[hl];
//							R long long temp=val2[lst2[2]];
//							val2[s]=std::min(val2[s],temp+hl+a[s]);
//						}
						lst2[2]=lst2[1],lst2[1]=lst2[0],lst2[0]=t;
						t=fa[t];
					}
					R long long ans=val[l]+val2[l]-a[l];
					for(R int i=0; i<=2; ++i) {
						if(lst[i]) {
							for(R int j=0; j<=k-i; ++j) {
								if(lst2[j])ans=std::min(ans,val[lst[i]]+val2[lst2[j]]);
							}
						}
					}
					wrt(ans);
				}
			}
		} else {
			while(q--) {
				int s=rint(),t=rint();
				R int l=lca(s,t);
				R int lst[4]= {};
				val[s]=a[s],lst[0]=s,s=fa[s];
				while(s!=fa[l]) {
					val[s]=infll;
					for(R int i=0; i<k; ++i)if(lst[i])val[s]=std::min(val[s],val[lst[i]]+a[s]);
					if(lst[3]) {
						R int hl=cho[lst[1]].fir==lst[2]?cho[lst[1]].sec:cho[lst[1]].fir;
						hl=a[hl];
						R long long temp=val[lst[3]];
						val[s]=std::min(val[s],temp+hl+a[s]);
					}
					lst[3]=lst[2],lst[2]=lst[1],lst[1]=lst[0],lst[0]=s;
					s=fa[s];
				}
				R int lst2[4]= {};
				val2[t]=a[t],lst2[0]=t,t=fa[t];
				while(t!=fa[l]) {
					val2[t]=infll;
					for(R int i=0; i<k; ++i)if(lst2[i])val2[t]=std::min(val2[t],val2[lst2[i]]+a[t]);
					if(lst2[3]) {
						R int hl=cho[lst2[1]].fir==lst2[2]?cho[lst2[1]].sec:cho[lst2[1]].fir;
						hl=a[hl];
						R long long temp=val2[lst2[3]];
						val2[s]=std::min(val2[s],temp+hl+a[s]);
					}
					lst2[3]=lst2[2],lst2[2]=lst2[1],lst2[1]=lst2[0],lst2[0]=t;
					t=fa[t];
				}
				R long long ans=val[l]+val2[l]-a[l];
				for(R int i=0; i<=2; ++i) {
					if(lst[i]) {
						for(R int j=0; j<=k-i; ++j) {
							if(lst2[j])ans=std::min(ans,val[lst[i]]+val2[lst2[j]]);
						}
					}
				}
//				if(q==5) {
//					printf("temp:%lld\n",ans);
//					rep0(i,4)printf("%d ",lst[i]);
//				}
				if(lst[3]&&lst2[1]) {
					R int hl=cho[lst[1]].fir==lst[2]?cho[lst[1]].sec:cho[lst[1]].fir;
					hl=a[hl];
					R long long temp=val[lst[3]];
					ans=std::min(ans,temp+hl+val2[lst2[1]]);
				}
				if(lst2[3]&&lst[1]) {
					R int hl=cho[lst2[1]].fir==lst2[2]?cho[lst2[1]].sec:cho[lst2[1]].fir;
//					printf("%d %d\n",cho[lst2[1]].fir,lst2[2]);
					hl=a[hl];
					R long long temp=val2[lst2[3]];
					ans=std::min(ans,temp+hl+val[lst[1]]);
//					printf("%d %d\n",cho[lst2[1]].fir,cho[lst2[1]].sec);
//					printf("fefew:%lld %lld %lld\n",temp,hl,val[lst[1]]);
				}
//					if(lst[1]&&lst2[1]) {
//						R int temp=cho[l].fir;
//						if(temp==lst[1]||temp==lst2[1])temp==cho[l].sec;
//						if(temp==lst[1]||temp==lst2[1])temp==cho[l].thi;
//						ans=std::min(ans,val[lst[1]]+val2[lst2[1]]+a[temp]);
//					}
				wrt(ans);
			}
		}
		return flu(),0;
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	return fck_up::_main();
}
/*
6 3 1
1 1 4 5 1 4
1 2
2 3
3 4
4 5
5 6
1 6
2 5
3 4
*/

