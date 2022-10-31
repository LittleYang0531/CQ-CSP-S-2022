#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long>s[2505];
long long a[2505];
long long pd[2505];
long long q,w;
long long bj[2505];
long long dfs(long long x,long long y){
	if(pd[x]!=0)return pd[x];
	if(y==4){
		pd[x]=a[x];
		return a[x];
	}
	int ans=0;
	int ax=0;
	for(int i=0;i<s[x].size();i++){
		if(bj[s[x][i]]==0){
			bj[s[x][i]]=1;
			ans+=dfs(s[x][i],y+1);
			bj[s[x][i]]=0;
		}
	}
	pd[x]=ans;
	return ans;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=2;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld",&q,&w);
		s[q].push_back(w);
		s[w].push_back(q);
	}
	printf("%lld\n",dfs(1,0));
	return 0;
}

