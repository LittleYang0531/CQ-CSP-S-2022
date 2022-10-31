#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,m,k;
vector<int> w[2501];


long long int dp(int x,int t,long long int a[],bool p[],int z1,int z2)
{
	if(t==0){
		if(p[x]) return a[x];
		return -1;
	}
	bool u=0;
	int i,e;
	long long int ans=-1,r;t--;
	for(i=0;i<w[x].size();i++){
		u=0;
		if(w[x][i]==z1 || w[x][i]==z2) continue;
		if(t==2) z1=w[x][i];
		else if(t==1) z2=w[x][i];
		r=dp(w[x][i],t,a,p,z1,z2);
		ans=max(ans,r);
	}
	if(ans==-1) return -1;
	return ans+a[x];
	
}



int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int i,x,y;
	cin>>n>>m>>k;
	bool p[n+1]={0};
	long long int a[n+1];
	
	
	for(i=2;i<=n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>x>>y;
		
		if(x==1){
			w[x].push_back(y);
			p[y]=1;
		} 
		if(y==1){
			w[y].push_back(x);
			p[x]=1;
		} 
		else{
			w[x].push_back(y);
			w[y].push_back(x);
		}
	}
	cout<<dp(1,4,a,p,1,1);
	
	
	return 0;
}
