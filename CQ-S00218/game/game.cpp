#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
namespace ljx_9420yy {

	const long long inf = 1000000000000000000, maxn = 1e5+5;
	    long long n, m, q, a[maxn], b[maxn], min1, min2, max1, max2, l1, r1, l2, r2, ans;

	int main() {
		cin>> n>> m>> q;
		for(int i=1; i<=n; i++) {
			cin>> a[i];
		}
		for(int i=1; i<=m; i++) {
			cin>> b[i];
		}
		for(int i=1; i<=q; i++) {
			cin>> l1>> r1>> l2>> r2;
			min1 = inf;
			max1 = -inf;
			min2 = inf;
			max2 = -inf;
			int b_op0=0, b_op1=0, b_op2=0, a_op0=0, a_op1=0, a_op2=0;
			ans = -inf;
			for(int j=l2; j<=r2; j++){
				if(b[j]>0)	b_op1++;
				if(b[j]<0)	b_op2++;
				if(b[j]==0)	b_op0++;
				min1 = min(min1, b[j]);
				max1 = max(max1, b[j]);
			}
			for(int j=l1; j<=r1; j++){
				if(a[j]>0)	a_op1++;
				if(a[j]<0)	a_op2++;
				if(a[j]==0)	a_op0++;
				min2 = min(min2, a[j]);
				max2 = max(max2, a[j]);
			}
			if(b_op1 == r2-l2+1){	//b全为正数
				if(a_op1 >= 1)	ans = max2*min1;	//a有正数
				else	ans = max2*max1;	//a没有正数 
			} else if(b_op2 == r2-l2+1){	//b全为负数 
//			cout<< "  agar1335\n";
				if(a_op2 >= 1)	ans = min2*max1;	//a有负数 
				else	ans = min2*min1;	//a没有负数 
			} else{
//				cout<< "5ssdfsdsfd446464\n";
				if(a_op0 >= 1)	ans = 0;	//a有0 
				else{
					for(int j=l1; j<=r1; j++){
						if(a[j]>0)	ans = max(ans, a[j]*min1);
						else	ans = max(ans, a[j]*max1);
					}
				}
			}
			cout<< ans<< endl;
		}
		
		
		return 0;
	}

}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ljx_9420yy::main();
	return 0;
}

