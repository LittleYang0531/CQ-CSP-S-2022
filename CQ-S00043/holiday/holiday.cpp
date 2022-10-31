#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[2505],b[10003][3],ans,c[2500][2500];
int main(){
freopen("holiday.in","r",stdin);
freopen("holiday.out","w",stdout);
cin>>n>>m>>k;
k+=1;
for(int i=2;i<=n;i++){
cin>>a[i];	
}
for(int i=1;i<=m;i++){
	cin>>b[i][1]>>b[i][2];
}
sort(a+1,a+n+1);
/*for(int i=1;i<=n;i++){
	c[b[i][1]][b[i][2]]++;		
		c[b[i][2]][b[i][1]]++;		
	}
while(){
	
	
	
	
}*/
for(int i=n;i>=n-4;i--){
	ans+=a[i];
}
cout<<ans;
return 0;
}

