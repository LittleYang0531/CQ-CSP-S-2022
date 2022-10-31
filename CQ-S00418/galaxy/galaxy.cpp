#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int re=0,base=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') base=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		re=re*10+ch-'0';
		ch=getchar();
	}
	return re*base;
}
void write(int num){
	if(num>9) write(num/10);
	putchar(num%10+'0');
}
int n,m,inu,inv,q,op,degree[500005];
set <int> cango[500005];
vector <int> son[500005];
int dt[7005][7005];
bool check(){
	int cnt=0;
	queue <int> dl;
	memset(degree,0,sizeof degree);
	for(int i=1;i<=n;i++){
		if(cango[i].size()!=1) return false;
		for(set<int>::iterator it=cango[i].begin();it!=cango[i].end();it++){
			int v=*it;
			degree[v]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!degree[i]){
			dl.push(i);
		}
	}
	while(!dl.empty()){
		int u=dl.front();
		dl.pop();
		cnt++;
		for(set<int>::iterator it=cango[u].begin();it!=cango[u].end();it++){
			int v=*it;
			degree[v]--;
			if(!degree[v]) dl.push(v);
		}
	}
	if(cnt!=n) return true;
	return false;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&inu,&inv);
		cango[inu].insert(inv);
		son[inv].push_back(inu);
		dt[inu][inv]=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&inu,&inv);
			dt[inu][inv]=2;
			auto tmp=cango[inu].find(inv);
			if(tmp!=cango[inu].end()) cango[inu].erase(tmp);
		}else if(op==2){
			scanf("%d",&inu);
			for(int j=0;j<son[inu].size();j++){
				dt[son[inu][j]][inu]=2;
				auto tmp=cango[son[inu][j]].find(inu);
				if(tmp!=cango[son[inu][j]].end())cango[son[inu][j]].erase(tmp);
			}
		}else if(op==3){
			scanf("%d%d",&inu,&inv);
			dt[inu][inv]=1;
			cango[inu].insert(inv);
		}else{
			scanf("%d",&inu);
			for(int j=0;j<son[inu].size();j++){
				if(dt[son[inu][j]][inu]==2){
					dt[son[inu][j]][inu]=1;
					cango[son[inu][j]].insert(inu);
				}
			}
		}
		if(check())
			printf("YES\n");
		else
			printf("NO\n");		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
