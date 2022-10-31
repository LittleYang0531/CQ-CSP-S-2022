#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace tokidosaya {
	int n,m,q;
	namespace sub1 {
		const int maxn=1005;
		typedef pair<int,int> pi;
		typedef vector<pi>::iterator iter;
#define fi first
#define sc second
		int cd[maxn],tot,c0;
		vector<pi> v[maxn];
		map<int,int> book[maxn];
		int main() {
			int op,x,y;
			tot=m;
			for(int i=1; i<=m; i++)x=read(),y=read(),book[x][y]=v[y].size(),cd[x]++,v[y].push_back(pi(x,1));
			q=read();
			while(q--) {
				op=read(),x=read();
				if(op==1) {
					y=read();
					int id=book[x][y];
					v[y][id].sc=0,tot--,cd[x]--,c0+=!cd[x];
				} else if(op==2) {
					for(iter it=v[x].begin(); it!=v[x].end(); it++)if(it->sc)it->sc=0,tot--,cd[it->fi]--,c0+=!cd[it->fi];
				} else if(op==3) {
					y=read();
					int id=book[x][y];
					v[y][id].sc=1,tot++,c0-=!cd[x],cd[x]++;
				} else {
					for(iter it=v[x].begin(); it!=v[x].end(); it++)if(!it->sc)it->sc=1,tot++,c0-=!cd[it->fi],cd[it->fi]++;
				}
				puts(tot==n&&!c0?"YES":"NO");
			}
			return 0;
		}
	}
	namespace sub2 {
		const int maxn=5e5+5;
		typedef set<int>::iterator iter;
		set<int> s[maxn],e[maxn];
		int cd[maxn],q,tot,c0;
		int main() {
			int op,x,y;
			tot=m;
			for(int i=1; i<=m; i++)x=read(),y=read(),cd[x]++,s[y].insert(x);
			q=read();
			while(q--) {
				op=read(),x=read();
				if(op==1)y=read(),cd[x]--,c0+=!cd[x],tot--,s[y].erase(x),e[y].insert(x);
				else if(op==2)for(iter it=s[x].begin(); it!=s[x].end(); it=s[x].erase(it))cd[*it]--,tot--,c0+=!cd[*it],e[x].insert(*it);
				else if(op==3)y=read(),tot++,c0-=!cd[x],cd[x]++,e[y].erase(x),s[y].insert(x);
				else for(iter it=e[x].begin(); it!=e[x].end(); it=e[x].erase(it))c0+=!cd[*it],cd[*it]++,tot++,s[x].insert(*it);
				puts(tot==n&&!c0?"YES":"NO");
			}
			return 0;
		}
	}
	int main() {
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
		n=read(),m=read();
		if(n<=1000)return sub1::main();
		return sub2::main();
		return 0;
	}
}
int main() {
	return tokidosaya::main();
}

