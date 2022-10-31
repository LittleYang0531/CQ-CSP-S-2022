#include<bits/stdc++.h>
using namespace std;
const int N=500100;
vector<int> z[N],f[N];
set<int> l[N];
int n,m,cnt;
void check(){
	if(cnt){
		printf("NO\n");
		return ;
	}
	printf("YES\n");
	return ;
}
void era(int u,int v){
	set<int>::iterator it=l[u].lower_bound(v);
	if(it!=l[u].end()&&(*it)==v){
		l[u].erase(it);
		if(l[u].size()==0){
			cnt++;
		}
		if(l[u].size()==1){
			cnt--;
		}
		f[v].push_back(u);
	}
	return ;
}
void ins(int u,int v){
	set<int>::iterator it=l[u].lower_bound(v);
	if(it==l[u].end()||(*it)!=v){
		l[u].insert(v);
		if(l[u].size()==2){
			cnt++;
		}
		if(l[u].size()==1){
			cnt--;
		}
		z[v].push_back(u);
	}
	return ;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		z[v].push_back(u);
		l[u].insert(v);
	}
	for(int i=1;i<=n;i++){
		if(l[i].size()!=1){
			cnt++;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int u,v;
			scanf("%d%d",&u,&v);
			era(u,v);
		}
		else if(opt==2){
			int v;
			scanf("%d",&v);
			for(;!z[v].empty();){
				int u=z[v].back();
				z[v].pop_back();
				era(u,v);
			}
		}
		else if(opt==3){
			int u,v;
			scanf("%d%d",&u,&v);
			ins(u,v);
		}
		else{
			int v;
			scanf("%d",&v);
			for(;!f[v].empty();){
				int u=f[v].back();
				f[v].pop_back();
				era(u,v);
			}
		}
		check();
	}
	return 0;
}

