#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<map>
const int Q=500005;
const int INF=1<<30;
#define rg register int
#define cint const register int
//const int SZ=1<<21;
//char ibuf[SZ|5],*IP1=ibuf,*IP2=ibuf;
//inline char gc(){if(IP1==IP2)IP2=(IP1=ibuf)+fread(ibuf,1,SZ,stdin);return *IP1++;}
#define gc() getchar()
inline bool ig(const char c){return c>='0'&&c<='9';}
inline void read(rg&oi){rg res=0,f=1;char c;while(c=gc(),(!ig(c))&&(c^'-'));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(rg oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+'0');}
inline void write(cint oi,const char c){print(oi);putchar(c);}
int n,m,deg[Q],q;
std::vector<int>vc[Q];
std::map<int,bool>mp[Q];
int cnt[Q];
inline void erase(cint x,cint y){mp[x][y]=0;--cnt[deg[x]];--deg[x];++cnt[deg[x]];}
inline void insert(cint x,cint y){mp[x][y]=1;--cnt[deg[x]];++deg[x];++cnt[deg[x]];}
std::vector<int>::iterator it;
inline void erase_all(cint x){
	for(it=vc[x].begin();it!=vc[x].end();++it){
		cint y=*it;if(!mp[y][x])continue;
		mp[y][x]=0;--cnt[deg[y]];--deg[y];++cnt[deg[y]];
	}
}
inline void insert_all(cint x){
	for(it=vc[x].begin();it!=vc[x].end();++it){
		cint y=*it;if(mp[y][x])continue;
		mp[y][x]=1;--cnt[deg[y]];++deg[y];++cnt[deg[y]];
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);read(m);
	for(rg i=1,x,y;i<=m;++i)read(x),read(y),vc[y].emplace_back(x),++deg[x],mp[x][y]=1;
	for(rg i=1;i<=n;++i)++cnt[deg[i]];
	read(q);for(rg op,x,y;q--;){
		read(op);read(x);switch(op){
			case 1:read(y);erase(x,y);break;
			case 2:erase_all(x);break;
			case 3:read(y);insert(x,y);break;
			case 4:insert_all(x);break;
		}
//		for(rg i=1;i<=n;++i)write(cnt[i],' ');putchar('\n');
		puts(cnt[1]==n?"YES":"NO");
	}
	return 0;
}
