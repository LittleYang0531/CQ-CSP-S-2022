#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,a[10][2502],k1[100001],k2[100001],k3[100001],c,k4[100001],a1,a2,k6[100001],t,k7[100001],o1;
bool k5[100001];
void DD(long long x,long long y){
	k1[++c]=k2[x];
	k2[x]=c;
	k3[c]=y;
}
void dg(long long x,long long y,long long z){
	if(z>k)return;
	if(k5[x]==1)return;
	else k5[x]=1;
	for(k6[x]=k2[x];k6[x]!=0;k6[x]=k1[k6[x]]){
	    if(k3[k6[x]]!=t)a[y][k3[k6[x]]]=max(a[y][k3[k6[x]]],max(a[y-1][k3[k6[x]]],a[y-1][t]+k4[k3[k6[x]]]));
		dg(k3[k6[x]],y,z+1);
	}
	k5[x]=0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>k4[i];
	for(int i=1;i<=m;i++){
		cin>>a1>>a2;
		DD(a1,a2);
		DD(a2,a1);
		if(a1==1){
			a[1][a2]=k4[a2];
		    DD(n+1,a2);
		    DD(a2,n+1);
		}
		if(a2==1){
			a[1][a1]=k4[a1];
			DD(n+1,a1);
		    DD(a1,n+1);
		    
		}
	}
	for(int i=2;i<=5;i++){
		for(int j=2;j<=n+1;j++){
			t=j;
			dg(j,i,0);
		}
	}
	cout<<a[5][n+1];
}
