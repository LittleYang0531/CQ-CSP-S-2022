#include<bits/stdc++.h>
using namespace std;
long long sc[2505];
int n,m,k;
bool pos[2505][2505];
bool cf[9500000];
long long dp[15000];long long ans=LONG_LONG_MIN; 
void qiu(int x,int k,long long cnt){
	if(k==-1&&x!=1){
		return;
	}
	if(k==-1&&x==1){
		ans=max(ans,cnt);
	}
	for (int i=1;i<=2501;i++){
		if(pos[x][i]==1&&cf[i]==0){
			cf[i]=1;
//			cout<<"¾°µã"<<i<<"Ê£Óà²½Êý"<<k-1<<endl; 
			qiu(i,k-1,cnt+sc[i]);
			cf[i]=0;
		}	
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin >> n>> m>> k;
	for(int i=2;i<=n;i++){
		cin>> sc[i];
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		pos[a][b]=1;
		pos[b][a]=1;
	}
	qiu(1,4,0);
	cout<<ans;
	return 0;
}
