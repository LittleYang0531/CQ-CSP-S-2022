#include<bits/stdc++.h>
using namespace std;
int N,M,Q;
long long A[100005],B[100005];
int A1,A2,A3,A4,A5,B1,B2,B3,B4,B5;/*  1: + ;  2: - ;  3: 0  */
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=N;i++)scanf("%lld",&A[i]);
	for(int i=1;i<=M;i++)scanf("%lld",&B[i]);
	while(Q--){
		A1=A2=A3=A4=A5=B1=B2=B3=B4=B5=0;
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++)if(A[i]==0)A3=1;
		else if(A[i]<0){
			A2=(A2==0||A[i]>A[A2])?i:A2;//-1
			A4=(A4==0||A[i]<A[A4])?i:A4;//-5
		}
		else if(A[i]>0){
			A1=(A1==0||A[i]<A[A1])?i:A1;//1
			A5=(A5==0||A[i]>A[A5])?i:A5;//5
		}
		for(int i=l2;i<=r2;i++)if(B[i]==0)B3=1;
		else if(B[i]<0){
			B2=(B2==0||B[i]>B[B2])?i:B2;//-1
			B4=(B4==0||B[i]<B[B4])?i:B4;//-5
		}
		else if(B[i]>0){
			B1=(B1==0||B[i]<B[B1])?i:B1;//1
			B5=(B5==0||B[i]>B[B5])?i:B5;//5
		}
		if(B1!=0&&B2!=0){
			if(A3!=0)printf("0\n");
			else if(A1!=0&&A2!=0){
				long long H1=A[A1]*B[B4];
				long long H2=A[A2]*B[B5];
				long long H3=A[A4]*B[B5];
				long long H4=A[A5]*B[B4];
				printf("%lld\n",max(max(max(H1,H2),H3),H4));
			}
			else if(A1!=0)printf("%lld\n",B[B4]*A[A1]);
			else if(A2!=0)printf("%lld\n",B[B5]*A[A2]);
		}else if(B1!=0&&B3!=0){
			if(A1!=0||A3!=0)printf("0\n");
			else if(A2!=0)printf("%lld\n",A[A2]*B[B5]);
		}else if(B2!=0&&B3!=0){
			if(A2!=0||A3!=0)printf("0\n");
			else if(A1!=0)printf("%lld\n",A[A1]*B[B4]);
		}else if(B1!=0){
			if(A1!=0)printf("%lld\n",B[B1]*A[A5]);
			else if(A3!=0)printf("0\n");
			else if(A2!=0)printf("%lld\n",B[B5]*A[A3]);
		}else if(B2!=0){
			if(A2!=0)printf("%lld\n",A[A4]*B[B2]);
			else if(A3!=0)printf("0\n");
			else if(A1!=0)printf("%lld\n",A[A1]*B[B4]);
		}else if(B3!=0)printf("0\n");
	}
	return 0;
} 
