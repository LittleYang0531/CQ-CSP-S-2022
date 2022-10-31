#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,q,vis[500001];
multiset <int> s[500001],lz[500001];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		lz[u].insert(v);
		s[u].insert(v);
	}
	scanf("%d",&q);
	while(q--){
		int pos=read(),u=read(),v;
		if(pos==1){
			v=read();
			if(s[u].find(v)!=s[u].end()) s[u].erase(s[u].find(v));
		}
		else if(pos==2){
			for(int i=1;i<=n;i++){
				if(s[i].find(u)!=s[i].end()) s[i].erase(s[i].find(u));
			}
		}
		else if(pos==3){
			v=read();
			if(s[u].find(v)==s[u].end()) s[u].insert(v);
		}
		else{
			for(int i=1;i<=n;i++){
				if(lz[i].find(u)!=lz[i].end()&&s[i].find(u)==s[i].end()) s[i].insert(u);
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(s[i].size()!=1){
				flag=0;
				printf("NO\n");
				break;
			}
		}
		if(!flag) continue;
		for(int i=1;i<=n;i++) vis[i]=0;
		int st=1;
		while(1){
			vis[st]=1;
			st=(*s[st].begin());
			if(vis[st]){
				flag=0;
				break;
			}
		}
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
