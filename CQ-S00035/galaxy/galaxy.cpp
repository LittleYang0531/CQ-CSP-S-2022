#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,q,m,d[N],asw;
set<int>s1[N],s2[N];
inline void add(int x) {
	if(d[x]==1) asw++;
	if(++d[x]==1) asw--;
}
inline void del(int x) {
	if(d[x]==1) asw++;
	if(--d[x]==1) asw--;
}
inline int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read(),asw=n;
	for(int x,y,i=1; i<=m; i++) {
		x=read(),y=read(),s1[y].insert(x),add(x);
	}
	q=read();
	for(int op,x,y,i=1; i<=q; i++) {
		op=read(),x=read();
		if(op==1) {
			s2[y=read()].insert(x),s1[y].erase(x),del(x);
		} else if(op==3) {
			s1[y=read()].insert(x),s2[y].erase(x),add(x);
		} else if(op==2) {
			for(auto j:s1[x]) s2[x].insert(j),del(j);
			s1[x].clear();
		} else {
			for(auto j:s2[x]) s1[x].insert(j),add(j);
			s2[x].clear();
		}
		puts(asw?"NO":"YES");
	}
	return 0;
}
