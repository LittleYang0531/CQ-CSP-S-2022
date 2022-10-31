#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
//一个人只有站在了悬崖边上才会真正坚强起来
//sto duanyixiu orz
//sto cool_milo orz
//sto tanyulin orz
//注意long long
//注意 (x^1) 优先级
//注意freopen
const int N=5e5+10;
int h[N],e[2*N],ne[2*N],idx;
map<PII,int> mp;
PII inmp[N];
bool vis[N];
int q;
int n,m;
vector<int> EXIT[N],ENTR[N];//虫洞出口/入口时该点 
bool useable[N];
int degree[N];

int add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	int id=idx;
	h[a]=idx++;
	return id;
}

bool dfs(int point){
	if(vis[point]) return true;
	vis[point]=true;
	for(int i=h[point];i!=-1;i=ne[i]){
		int j=e[i];
		if(dfs(j)) return true;
	}
	return false;
}

bool check(){
	for(int i=1;i<=n;i++) if(degree[i]!=1) return false;
	for(int i=1;i<=n;i++) vis[i]=false;
	return dfs(1);
}
 

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int id=add(a,b);
		degree[a]++;
		mp[{a,b}]=id;
		inmp[id]={a,b};
		EXIT[b].push_back(id);
		ENTR[a].push_back(id);
	}
	scanf("%d",&q);
	for(int i=0;i<=idx;i++) useable[i]=true;
	while(q--){
		int t,a,b;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&a,&b);
			int id=mp[{a,b}];
			degree[a]--;
			useable[id]=false;
			puts(check()?"YES":"NO");
		}else if(t==2){
			scanf("%d",&a);
			for(int lane:EXIT[a]) {
				useable[lane]=false;
				degree[inmp[lane].first]--;
			}
			puts(check()?"YES":"NO");
		}else if(t==3){
			scanf("%d%d",&a,&b);
			int id=mp[{a,b}];
			degree[a]++;
			useable[id]=true;
			puts(check()?"YES":"NO");
		}else if(t==4){
			scanf("%d",&a);
			for(int lane:EXIT[a]){
				useable[lane]=true;
				degree[inmp[lane].first]++;
			}
			puts(check()?"YES":"NO");
		}
	}
	


	return 0;
}

