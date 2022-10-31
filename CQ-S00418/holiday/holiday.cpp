#include <bits/stdc++.h>
#include <queue>
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
int n,m,k,s[2505],inu,inv,ans;
bool vis[2505];
vector <int> lis[2505];
//vector <int> lj={1};
void dfs(int u,int step,int sum){
	if(step==5){
		if(u!=1) return;
		else{
			ans=max(ans,sum);
//			for(int i=0;i<lj.size();i++){
//				printf("%d ",lj[i]);
//			}
//			cout<<endl;
		}
	}else for(int i=0;i<lis[u].size();i++){
		int v=lis[u][i];
		if(vis[v]) continue;
		vis[v]=true;
	//	lj.push_back(v);
		dfs(v,step+1,sum+s[v]);
	//	lj.pop_back();
		vis[v]=false;
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	s[1]=0;
	for(int i=2;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&inu,&inv);
		lis[inu].push_back(inv);
		lis[inv].push_back(inu);
	}
	if(k==0){
		dfs(1,0,0);
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
