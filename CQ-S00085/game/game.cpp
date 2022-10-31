#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+5;
long long A[Maxn],B[Maxn],C[1005][1005],n,m,Q;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>B[i];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
		C[i][j]=A[i]*B[j];
	while(Q--){
	  int l1,r1,l2,r2,ans,sum;
	  cin>>l1>>r1>>l2>>r2;
	  if(l1==r1){
	  	ans=1e9;
	  	for(int i=l2;i<=r2;i++)
	  	  if(ans>C[l1][i]) ans=C[l1][i];
	  }
	  else if(l2==r2){
	  	ans=-1e9;
	  	for(int i=l1;i<=r1;i++)
	  	  if(ans<C[i][l2]) ans=C[i][l2];
	  }
	  else{
	  	ans=-1e9;
	  	for(int i=l1;i<=r1;i++){
	  	  sum=1e9;
	  	  for(int j=l2;j<=r2;j++)
	  	    if(sum>C[i][j]) sum=C[i][j];
	  	  if(ans<sum) ans=sum;
		}
	  }
	  cout<<ans<<endl;
	}
	return 0;
}
