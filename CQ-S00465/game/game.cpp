/*
T2:
有60分暴力
对于矩阵C，一个询问就是求一个子矩阵每行最小值的最大值
ST表，暴力扫每一行

这60分好拿，考虑满分
先想A 

85分都很简单
考虑满分：

如果全正：
我一定选[l1,r1]最大的
对方一定选[l2,r2]最小的
ST表即可

如果全负就反过来

如果对方手里捏着全正，我选最大值
对方全负：我选最小值

对方有正有负：我一定弄不到正数了，考虑对方正数最大值和负数最小值
和我的正数最小值和负数最大值 

答案是这两个里面大的一个 

max(我正最小*对负最小
,我负最大*对正最大)

数据结构维护区间最小最大，2个东西

可以用ST表

但我就想用线段树，因为懒得想 
*/
#include <bits/stdc++.h>

using namespace std;
const int INF=1e9+1;
const int MAXN=1e5+50;
int A[2][MAXN];
int tr[2][MAXN<<2][4];//0:负数最小，1:负数最大，2:正数最小,3:正数最大 
void Build(int u,int l,int r,int op)
{
//	cout<<u<<" "<<l<<" "<<r<<endl; 
	tr[op][u][0]=INF;
	tr[op][u][1]=-INF;
	tr[op][u][2]=INF;
	tr[op][u][3]=-INF;
	if(l==r)
	{
		if(A[op][l]<=0)
		{
			tr[op][u][0]=tr[op][u][1]=A[op][l];
		}
		if(A[op][l]>=0)
		{
			tr[op][u][2]=tr[op][u][3]=A[op][l];
		}
		return;
	}
	int Mid=l+r>>1;
	Build(u<<1,l,Mid,op);
	Build(u<<1|1,Mid+1,r,op);
	
	tr[op][u][0]=min(tr[op][u<<1][0],tr[op][u<<1|1][0]);
	tr[op][u][1]=max(tr[op][u<<1][1],tr[op][u<<1|1][1]);
	tr[op][u][2]=min(tr[op][u<<1][2],tr[op][u<<1|1][2]);
	tr[op][u][3]=max(tr[op][u<<1][3],tr[op][u<<1|1][3]);
}

int Query(int op1,int op2,int u,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		return tr[op1][u][op2];
	}
	int Mid=l+r>>1;
	int Nowans;
	if(op2&1)
	Nowans=-INF;
	else
	Nowans=INF; 
	if(x<=Mid)
	{
		if(op2&1)
		{
			Nowans=max(Nowans,Query(op1,op2,u<<1,l,Mid,x,y));
		}
		else
		{
			Nowans=min(Nowans,Query(op1,op2,u<<1,l,Mid,x,y));
		}
	}
	if(y>=Mid+1)
	{
		if(op2&1)
		{
			Nowans=max(Nowans,Query(op1,op2,u<<1|1,Mid+1,r,x,y));
		}
		else
		{
			Nowans=min(Nowans,Query(op1,op2,u<<1|1,Mid+1,r,x,y));
		}
	}
	return Nowans;
}

int N,M,Q;
long long Now[2][4];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&N,&M,&Q);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&A[0][i]);
	}
	for(int i=1;i<=M;i++)
	{
		scanf("%d",&A[1][i]);
	}
	Build(1,1,N,0);
	Build(1,1,M,1);
	
//	puts("ee");
	while(Q--)
	{
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		
		for(int op2=0;op2<=3;op2++)
		{
			Now[0][op2]=Query(0,op2,1,1,N,l1,r1);
			Now[1][op2]=Query(1,op2,1,1,M,l2,r2);
		}
		if(Now[1][1]==-INF)//对方无负数 
		{
			if(Now[0][3]==-INF)//我无正数
			{
				printf("%lld\n",Now[0][1]*Now[1][3]); 
			}
			else
			{
				printf("%lld\n",Now[0][3]*Now[1][2]);
			}
			continue;
		}
		if(Now[1][3]==-INF)//对方无正数 
		{
			if(Now[0][1]==-INF)//我无负数 
			{
				printf("%lld\n",Now[0][2]*Now[1][0]);
			}
			else
			{
				printf("%lld\n",Now[0][0]*Now[1][1]);
			}
			continue;
		}
		if(Now[0][1]==-INF)//我无负 
		{
			if(Now[1][1]==-INF)//对方无负 
			{
				printf("%lld\n",Now[0][3]*Now[1][2]);
			}
			else
			{
				printf("%lld\n",Now[0][2]*Now[1][0]);
			}
			continue;
		}
		if(Now[0][3]==-INF)//我无正 
		{
			if(Now[1][3]==-INF)//对方无正
			{
				printf("%lld\n",Now[0][0]*Now[1][1]);
			 } 
			 else
			 {
			 	printf("%lld\n",Now[0][1]*Now[1][3]);
			 }
			 continue;
		}
	//	cout<<"Now:"<<Now[0][2]<<" "<<Now[1][0]<<endl; 
		printf("%lld\n",max(Now[0][2]*Now[1][0],Now[0][1]*Now[1][3]));
	}
	return 0;
}
