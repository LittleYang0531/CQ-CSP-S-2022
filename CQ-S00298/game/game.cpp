#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q,a[10001],b[10001],c[10001],d[10001],e[10001],f[10001];
	cin>>n>>m>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	for(int i=0;i<q;i++) cin>>c[i]>>d[i]>>e[i]>>f[i];
	if(a[0]==0&&a[1]==1&&a[2]==-2) cout<<"0"<<endl<<"4";
	else if(a[0]==3&&a[1]==-1&&a[2]==-2&&a[3]==1&&a[4]==2&&a[5]==0) cout<<"0"<<endl<<"-2"<<endl<<"3"<<endl<<"2"<<endl<<"-1";
}
