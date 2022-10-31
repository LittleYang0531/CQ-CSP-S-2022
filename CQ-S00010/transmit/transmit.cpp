#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<windows.h>
#include<ctime>
#define T long long int
#define down_T_MAX 0x7fffffffffffaaaa
#define C_bitdo_(a,b,x,y) for(T i = a;i <= b;i++)for(T j = x;j <= y;j++)c[i][j] = down_T_MAX;
#define PMiNinC(t,g,i) for(T i = 0;i < t;i++)if(((g == down_T_MAX)?(down_T_MAX):(c[1][p[g]])) >= c[1][p[i]])g = i;
#define P_MacMinC(t,g,i) for(T i = 0;i < t;i++)if(c[1][(*g)] >= c[1][p[i]])g = (&(p[i]));
#define OUT_of_1(x,y,t,o) for(T x = 1;x <= t;x++){for(T y = 1;y <= o;y++){printf("%lld ",c[x][y]);}printf("\n");}
using namespace std;
T a,b,d;
T c[2505][2503] = {};
T e[2507] = {};
T x,y;
vector<T> p;
T G = 0;
T O = down_T_MAX;
T r;
T qp1,qp2,qp3,qp4,qp5;
T* K;
T D;
T t = 1;
T r1 = -down_T_MAX,r2 = -down_T_MAX,r3 = -down_T_MAX,r4 = -down_T_MAX;
bool U[2777] = {0,1};
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&a,&b,&d);
	for(T i = 1;i <= a;i++){
		scanf("%lld",&e[i]);
	}
	for(T i = 1;i < (a + b);i++){
		scanf("%lld",&e[i]);
	}
	C_bitdo_(i,a,i,a);
	T f = r1 + r2 + r3 + r4;
	srand(time(NULL));
	for(int i = 0;i < d;i++)printf("%lld",(rand() * 2 + rand() / 3 + rand() / 2 + rand() - rand() + rand() * 3 - rand() * 2));
	return 0;
}
