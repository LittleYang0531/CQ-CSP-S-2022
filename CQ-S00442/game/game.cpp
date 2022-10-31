#include<bits/stdc++.h>
#define int long long
using namespace std;//zaayyds!
int n,m,q; 
int a[100005],b[100005];
int fs[3][100005],l[3][100005];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fs[1][i]=fs[1][i-1];
		l[1][i]=l[1][i-1];
		if(a[i]<0) fs[1][i]++;
		if(a[i]==0) l[1][i]++;
	} 
	for(int i=1;i<=m;i++){
		cin>>b[i];
		fs[2][i]=fs[2][i-1];
		l[2][i]=l[2][i-1];
		if(b[i]<0) fs[2][i]++;
		if(b[i]==0) l[2][i]++;
		
	}
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1){
			int minx=1e15;
			for(int j=l2;j<=r2;j++){
				minx=min(minx,a[l1]*b[j]);
			}
			cout<<minx<<endl;
		}
		else if(l2==r2){
			int minx=-1e15;
			for(int j=l1;j<=r1;j++){
				minx=max(minx,a[j]*b[l2]);
			}
			cout<<minx<<endl;
		}
		else if(fs[2][r2]-fs[2][l2-1]==0&&fs[1][r1]-fs[1][l1-1]==0){//È«ÎªÕý 
			int minx=-1e15;
			for(int j=l1;j<=r1;j++){
				minx=max(minx,a[j]);
			}
			int maxx=1e15;
			for(int j=l2;j<=r2;j++){
				maxx=min(maxx,b[j]);
			}
			cout<<minx*maxx<<endl;
		}
		else{
			int minx=-1e15;
			for(int j=l1;j<=r1;j++){
				int s=1e15;
				for(int t=l2;t<=r2;t++){
					s=min(s,b[t]*a[j]);
				}
				minx=max(minx,s);
			}
			cout<<minx<<endl;
		}
	}
	return 0;
}
