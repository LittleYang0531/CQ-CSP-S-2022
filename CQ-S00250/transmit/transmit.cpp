#include<bits/stdc++.h>
using namespace std;
int c[2005][3],ans[2005],n,q,k,t[2005];
int zssj(int qd,int cd,int fx){
	if(cd<=k)
		return 0;
	int min1=INT_MAX;
	for(int i=1;i<=k;i++){
		qd=c[qd][fx];
		min1=min(zssj(qd,cd-i,fx),min1);
	}
	return min1;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		c[a][c[a][2]]=b;
		c[a][2]++;
	}
	for(int i=0,s,t,l=0,j;i<q;i++){
		cin>>s>>t;
		for(j=s,i=0;j!=t&&c[j][2]>1;j=c[j][1],l++){}
		if(j!=t){
			for(j=s,i=0;j!=t;j=c[j][0],l++){}
			ans[i]=zssj(s,l,0);
		}
		else
			ans[i]=zssj(s,l,1);
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
