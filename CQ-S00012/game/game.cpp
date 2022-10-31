#include<bits/stdc++.h>
using namespace std;
long long n,m,q,ans;
struct peopLe{
	long long n,posi[100050],val[100050],mx[18][100050],mn[18][100050],sp_po[18][100050],sp_ne[18][100050];
	void InItIalIze(){
		for(int i=1;i<=n;i++){
			scanf("%lld",&val[i]);
			mn[0][i]=mx[0][i]=val[i];
			posi[i]=posi[i-1];
			if(val[i]>0){
				posi[i]++;
				sp_po[0][i]=val[i];
				sp_ne[0][i]=-0x3f3f3f3f;
			}else{
				sp_ne[0][i]=val[i];
				sp_po[0][i]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=17;i++){
			long long len=(1ll<<i);
			for(int j=1;j+len-1<=n;j++){
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
				sp_ne[i][j]=max(sp_ne[i-1][j],sp_ne[i-1][j+(1<<(i-1))]);
				sp_po[i][j]=min(sp_po[i-1][j],sp_po[i-1][j+(1<<(i-1))]);
			}
		}
		return;
	}
	long long ThInk(long long l,long long r){
		long long num=posi[r]-posi[l-1];
		if(num==r-l+1){
			return 1;
		}
		if(num==0){
			return 2;
		}
		return 3;
	}
	long long getmax(long long l,long long r){
		long long k=log2(r-l+1);
		return max(mx[k][l],mx[k][r-(1ll<<k)+1]);
	}
	long long getmin(long long l,long long r){
		long long k=log2(r-l+1);
		return min(mn[k][l],mn[k][r-(1ll<<k)+1]);
	}
	long long getsppo(long long l,long long r){
		long long k=log2(r-l+1);
		return min(sp_po[k][l],sp_po[k][r-(1ll<<k)+1]);
	}
	long long getspne(long long l,long long r){
		long long k=log2(r-l+1);
		return max(sp_ne[k][l],sp_ne[k][r-(1ll<<k)+1]);
	}
}A,B;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	A.n=n;
	B.n=m;
	A.InItIalIze();
	B.InItIalIze();
	for(int i=1;i<=q;i++){
		long long l1,l2,r1,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long op=B.ThInk(l2,r2);
//		cout<<op<<" ";
		if(op==1){
			long long ans1;
			ans1=A.getmax(l1,r1);
			if(ans1>0){
				ans1*=B.getmin(l2,r2);
			}else{
				ans1*=B.getmax(l2,r2);
			}
			ans=ans1;
		}else{
			if(op==2){
				long long ans1;
				ans1=A.getmin(l1,r1);
				if(ans1>0){
					ans1*=B.getmin(l2,r2);
				}else{
					ans1*=B.getmax(l2,r2);
				}
				ans=ans1;
			}else{
				long long ans1,ans2;
				ans1=A.getsppo(l1,r1);
				ans2=A.getspne(l1,r1);
				ans1*=B.getmin(l2,r2);
				ans2*=B.getmax(l2,r2);
				ans=max(ans1,ans2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
6 4 5
3 ©\1 ©\2 1 2 0
1 2 ©\1 ©\3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
