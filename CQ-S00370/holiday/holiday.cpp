#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,K,a[2510][2510];
ll s[2510],ans;
void f1(){
	++K;memset(a,0x3f,sizeof(a));
	a[1][1]=0;
	for(int i=2;i<=n;++i)cin>>s[i],a[i][i]=0;
	for(int i=1,x,y;i<=m;++i)cin>>x>>y,a[x][y]=a[y][x]=1;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(int i=2;i<=n;++i){
		if(a[1][i]>K)continue;
		for(int j=2;j<=n;++j){
			if(i==j||a[i][j]>K)continue;
			for(int k=2;k<=n;++k){
				if(i==k||j==k||a[j][k]>K)continue;
				for(int l=2;l<=n;++l){
					if(i==l||j==l||k==l||a[k][l]>K||a[l][1]>K)continue;
					ans=max(ans,s[i]+s[j]+s[k]+s[l]);
//					cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<ans<<'\n';
				}
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
//	if(n<=20&&m<=50)
	f1();
	return 0;
}
/*
1.调试后打开freopen
2.注意开long long
3.最后5分钟不要敲代码，编译运行并使用文件输入输出 
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
40pts+?pts（与k的大小有关） 
*/
/*
2022 CCF非专业级软件能力认证
CSP-J/S 2022第二轮认证
提高级
时间：2022年10月29日14:30～18:30
题目名称 假期计划 策略游戏 星战 数据传输
题目类型 传统型 传统型 传统型 传统型
目录 holiday game galaxy transmit
可执行文件名 holiday game galaxy transmit
输入文件名 holiday.in game.in galaxy.in transmit.in
输出文件名 holiday.out game.out galaxy.out transmit.out
每个测试点时限 2.0秒 1.0秒 2.0秒 3.0秒
内存限制 512 MiB 512 MiB 512 MiB 1024 MiB
测试点数目 20 20 20 25
测试点是否等分 是 是 是 是
提交源程序文件名
对于C++ 语言 holiday.cpp game.cpp galaxy.cpp transmit.cpp
编译选项
对于C++ 语言 ‐O2 ‐std=c++14
.
注
.
意
.
事
.
项（
.
请
.
仔
.
细
.
阅
.
读）
1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. C/C++中函数main()的返回值类型必须是int，程序正常结束时的返回值必须
是0。
3. 提交的程序代码文件的放置位置请参考各省的具体要求。
4. 因违反以上三点而出现的错误或问题，申诉时一律不予受理。
5. 若无特殊说明，结果的比较方式为全文比较（过滤行末空格及文末回车）。
6. 选手提交的程序源文件必须不大于100KB。
7. 程序可使用的栈空间内存限制与题目的内存限制一致。
8. 全国统一评测时采用的机器配置为：Inter(R) Core(TM) i7-8700K CPU @3.70GHz，
内存32GB。上述时限以此配置为准。
9. 只提供Linux格式附加样例文件。
10. 评测在当前最新公布的NOI Linux下进行，各语言的编译器版本以此为准。
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
假期计划（holiday）
【题目描述】
小熊的地图上有n个点，其中编号为1的是它的家、编号为2,3,. . ., n的都是景
点。部分点对之间有双向直达的公交线路。如果点x与z
1、z
1 与z
2、……、z
k?1 与z
k、
z
k 与y之间均有直达的线路，那么我们称x与y之间的行程可转车k次通达；特别地，
如果点x与y之间有直达的线路，则称可转车0次通达。
很快就要放假了，小熊计划从家出发去4个
.
不
.
同的景点游玩，完成5段行程后回
家：家→景点A →景点B →景点C →景点D →家且每段行程最多转车k次。转车
时经过的点没有任何限制，既可以是家、也可以是景点，还可以重复经过相同的点。例
如，在景点A →景点B的这段行程中，转车时经过的点可以是家、也可以是景点C，
还可以是景点D →家这段行程转车时经过的点。
假设每个景点都有一个分数，请帮小熊规划一个行程，使得小熊访问的四个
.
不
.
同景
点的分数之和最大
【输入格式】
从文件holiday.in中读入数据。
第一行包含3个正整数n,m, k，分别表示地图上点的个数、双向直达的点对数量、
每段行程最多的转车次数。
第二行包含n?1个正整数，分别表示编号为2,3,. .. , n的景点的分数。
接下来m行，每行包含两个正整数x,y，表示点x和y之间有道路直接相连，保
证1≤x,y≤n，且没有重边，自环。
【输出格式】
输出到文件holiday.out中。
输出一个正整数，表示小熊经过的4个不同景点的分数之和的最大值。
【样例1输入】
1 8 8 1
2 9 7 1 8 2 3 6
3 1 2
4 2 3
5 3 4
6 4 5
7 5 6
第2页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
8 6 7
9 7 8
10 8 1
【样例1输出】
1 27
【样例1解释】
当计划的行程为1 → 2 → 3 → 5 → 7 → 1时，4个景点的分数之和为9+7+8+3 = 27，
可以证明其为最大值。
行程1 → 3 → 5 → 7 → 8 → 1的景点分数之和为24、行程1 → 3 → 2 → 8 → 7
→ 1的景点分数之和为25。它们都符合要求，但分数之和不是最大的。
行程1 → 2 → 3 → 5 → 8 → 1的景点分数之和为30，但其中5 → 8至少需要转车
2次，因此不符合最多转车k= 1次的要求。
行程1 → 2 → 3 → 2 → 3 → 1的景点分数之和为32，但游玩的并非4个不同的景
点，因此也不符合要求。
【样例2输入】
1 7 9 0
2 1 1 1 2 3 4
3 1 2
4 2 3
5 3 4
6 1 5
7 1 6
8 1 7
9 5 4
10 6 4
11 7 4
【样例2输出】
1 7
第3页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
【样例3】
见选手目录下的holiday/holiday3.in与holiday/holiday3.ans。
【数据范围】
对于所有数据，保证5≤n≤2500,1≤m≤10000,0≤k≤100, 所有景点的分数
1≤s
i ≤10
18
。保证至少存在一组符合要求的行程。
测试点编号 n≤ m≤ k≤
1～3
10 20
0
4～5 5
6～8 20 50 100
9～11
300 1000
0
12～14 100
15～17
2500 10000
0
18～20 100
第4页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
策略游戏（game）
【题目描述】
小L和小Q在玩一个策略游戏。
有一个长度为n的数组A和一个长度为m的数组B，在此基础上定义一个大小
为n×m的矩阵C，满足Cij =Ai ×Bj。所有下标均从1开始。
游戏一共会进行q 轮，在每一轮游戏中，会事先给出4个参数l
1
,r
1
,l
2
,r
2，满足
1≤l
1≤r
1≤n,1≤l
2≤r
2≤m。
游戏中，小L先选择一个l
1 ～r
1 之间的下标x，然后小Q选择一个l
2 ～r
2 之间
的下标y。定义这一轮游戏中二人的得分是Cxy。
小L的目标是使得这个得分尽可能大，小Q的目标是使得这个得分尽可能小。同
时两人都是足够聪明的玩家，每次都会采用最优的策略。
请问：按照二人的最优策略，每轮游戏的得分分别是多少？
【输入格式】
从文件game.in中读入数据。
第一行输入3个正整数n,m, q，分别表示数组A，数组B的长度和游戏轮数。
第二行：n个整数，表示Ai，分别表示数组A的元素。
第三行：m个整数，表示Bi，分别表示数组B的元素。
接下来q行，每行4个正整数，表示这一次游戏的l
1
,r
1
,l
2
,r
2。
【输出格式】
输出到文件game.out中。
输出共q行，每行一个整数，分别表示每一轮游戏中，小L和小Q在最优策略下
的得分。
【样例1输入】
1 3 2 2
2 0 1 ‐2
3 ‐3 4
4 1 3 1 2
5 2 3 2 2
第5页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例1输出】
1 0
2 4
【样例1解释】
这组数据中，矩阵C如下：
1 0 0
2 ‐3 4
3 6 ‐8
在第一轮游戏中，无论小L选取的是x= 2还是x= 3，小Q都有办法选择某个
y使得最终的得分为负数。因此小L选择x= 1是最优的，因为这样得分一定为0。
而在第二轮游戏中，由于小L可以选x= 2，小Q只能选y= 2，如此得分为4。
【样例2输入】
1 6 4 5
2 3 ‐1 ‐2 1 2 0
3 1 2 ‐1 ‐3
4 1 6 1 4
5 1 5 1 4
6 1 4 1 2
7 2 6 3 4
8 2 5 2 3
【样例2输出】
1 0
2 ‐2
3 3
4 2
5 ‐1
【样例3】
见选手目录下的game/game3.in与game/game3.ans。
第6页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例4】
见选手目录下的game/game4.in与game/game4.ans。
【数据范围】
对于所有数据，1≤n,m, q≤10
5
,?10
9
≤Ai,B
i ≤10
9
。对于每轮游戏而言，1≤
l
1≤r
1≤n,1≤l
2≤r
2≤m。
测试点编号 n,m, q≤ 特殊条件
1
200
1,2
2 1
3 2
4～5 无
6
1000
1,2
7～8 1
9～10 2
11～12 无
13
10
5
1,2
14～15 1
16～17 2
18～20 无
其中，特殊性质1为：保证Ai,B
i >0。
特殊性质2为：保证对于每轮游戏而言，要么l
1=r
1，要么l
2=r
2。
第7页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
星战（galaxy）
【题目描述】
在这一轮的星际战争中，我方在宇宙中建立了n个据点，以m个单向虫洞连接。我
们把终点为据点u的所有虫洞归为据点u的虫洞。
战火纷飞之中这些虫洞很难长久存在，敌人的打击随时可能到来。这些打击中的有
效打击可以分为两类：
1. 敌人会摧毁某个虫洞，这会使它连接的两个据点无法再通过这个虫洞直接到达，
但这样的打击无法摧毁它连接的两个据点。
2. 敌人会摧毁某个据点，由于虫洞的主要技术集中在出口处，这会导致该据点的所
有还未被摧毁的虫洞被一同摧毁。而从这个据点出发的虫洞则
.
不
.
会
.
摧
.
毁。
注意：摧毁只会导致虫洞不可用，而不会消除它的存在。
为了抗击敌人并维护各部队和各据点之间的联系，我方发展出了两种特种部队负责
修复虫洞：
?A型特种部队则可以将某个特定的虫洞修复。
?B型特种部队可以将某据点的所有损坏的虫洞修复。
考虑到敌人打击的特点，我方并未在据点上储备过多的战略物资。因此只要这个据
点的某一条虫洞被修复，处于可用状态，那么这个据点也是可用的。
我方掌握了一种苛刻的空间特性，利用这一特性我方战舰可以沿着虫洞瞬移到敌方
阵营，实现精确打击。
为了把握发动反攻的最佳时机，指挥部必须关注战场上的所有变化，为了寻找一个
能够进行反攻的时刻。总指挥认为：
?如果从我方的任何据点出发，在选择了合适的路线的前提下，可以进行无限次的
虫洞穿梭（可以多次经过同一据点或同一虫洞），那么这个据点就可以
.
实
.
现
.
反
.
击。
?为了使虫洞穿梭的过程连续，尽量减少战舰在据点切换虫洞时的质能损耗，当且
仅当
.
只
.
有
.
一
.
个
.
从
.
该
.
据
.
点
.
出
.
发
.
的
.
虫
.
洞
.
可
.
用时，这个据点可以
.
实
.
现
.
连
.
续
.
穿
.
梭。
?如果我方所有据点都可以
.
实
.
现
.
反
.
击，也都可以
.
实
.
现
.
连
.
续
.
穿
.
梭，那么这个时刻就是
一个绝佳的
.
反
.
攻时刻。
总司令为你下达命令，要求你根据战场上实时反馈的信息，迅速告诉他当前的时刻
是否能够进行一次
.
反
.
攻。
【输入格式】
从文件galaxy.in中读入数据。
输入的第一行包含两个正整数n,m。
接下来m行每行两个数u,v，表示一个从据点u出发到据点v的虫洞。保证u?=v，
保证不会有两条相同的虫洞。初始时所有的虫洞和据点都是完好的。
第8页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
接下来一行一个正整数q表示询问个数。
接下来q行每行表示一次询问或操作。首先读入一个正整数t表示指令类型：
?若t= 1，接下来两个整数u,v表示敌人摧毁了从据点u出发到据点v的虫洞。
保证该虫洞存在且未被摧毁。
?若t= 2，接下来一个整数u表示敌人摧毁了据点u。如果该据点的虫洞已全部
被摧毁，那么这次袭击不会有任何效果。
?若t= 3，接下来两个整数u,v表示我方修复了从据点u出发到据点v的虫洞。
保证该虫洞存在且被摧毁。
?若t= 4，接下来一个整数u表示我方修复了据点u。如果该据点没有被摧毁的
虫洞，那么这次修复不会有任何效果。
在每次指令执行之后，你需要判断能否进行一次反攻。如果能则输出YES否则输出
NO。
【输出格式】
输出到文件galaxy.out中。
输出一共q行。对于每个指令，输出这个指令执行后能否进行反攻。
【样例1输入】
1 3 6
2 2 3
3 2 1
4 1 2
5 1 3
6 3 1
7 3 2
8 11
9 1 3 2
10 1 2 3
11 1 1 3
12 1 1 2
13 3 1 3
14 3 3 2
15 2 3
16 1 3 1
17 3 1 3
18 4 2
第9页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
19 1 3 2
【样例1输出】
1 NO
2 NO
3 YES
4 NO
5 YES
6 NO
7 NO
8 NO
9 YES
10 NO
11 NO
【样例1解释】
虫洞状态可以参考下面的图片，图中的边表示存在且未被摧毁的虫洞：
图1:样例1解释
【样例2】
见选手目录下的galaxy/galaxy2.in与galaxy/galaxy2.ans。
第10页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
【样例3】
见选手目录下的galaxy/galaxy3.in与galaxy/galaxy3.ans。
【样例4】
见选手目录下的galaxy/galaxy4.in与galaxy/galaxy4.ans。
【数据范围】
对于所有数据保证：1≤n≤5×10
5
,1≤m≤5×10
5
,1≤q≤5×10
5
。
测试点 n m q 特殊限制
1,2,3 ≤10 ≤20 ≤50
无
4,5,6,7,8 ≤10
3
≤10
4
≤10
3
9,10
≤5×10
5
≤5×10
5
≤5×10
5
保证没有t= 2和t= 4的情况
11,12 保证没有t= 4的情况
13,14,15,16 ≤10
5
无
17,18,19,20 ≤5×10
5
第11页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
数据传输（transmit）
【题目描述】
小C正在设计计算机网络中的路由系统。
测试用的网络总共有n台主机，依次编号为1～n。这n台主机之间由n?1根网
线连接，第i 条网线连接个主机a
i 和b
i。保证任意两台主机可以通过有限根网线直接
或者间接地相连。受制于信息发送的功率，主机a能够直接将信息传输给主机b当且仅
当两个主机在可以通过不超过k根网线直接或者间接的相连。
在计算机网络中，数据的传输往往需要通过若干次转发。假定小C需要将数据从主
机a传输到主机b(a?=b)，则其会选择出若干台用于传输的主机c
1=a,c
2
,·· ·,cm?1
,cm=
b，并按照如下规则转发：对于所有的1≤i < m, 主机c
i 将信息直接发送给c
i+1。
每台主机处理信息都需要一定的时间，第i 台主机处理信息需要v
i 单位的时间。数
据在网络中的传输非常迅速，因此传输的时间可以忽略不计。据此，上述传输过程花费
的时间为
∑
m
i=1
v
c
i
。
现在总共有q次数据发送请求，第i 次请求会从主机s
i 发送数据到主机t
i。小C
想要知道，对于每一次请求至少需要花费多少单位时间才能完成传输。
【输入格式】
从文件transmit.in 中读入数据。
输入的第一行包含三个正整数n,Q, k，分别表示网络主机个数，请求个数，传输参
数。数据保证1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3。
输入的第二行包含n个正整数，第i 个正整数表示v
i，保证1≤v
i ≤10
9
。
接下来n?1行，第i 行包含两个正整数a
i
,b
i，表示一条连接主机a
i
,b
i 的网线。保
证1≤a
i
,b
i ≤n。
接下来Q行，第i 行包含两个正整数s
i
,t
i，表示一次从主机s
i 发送数据到主机t
i
的请求。保证1≤s
i
,t
i ≤n,s
i
?=t
i。
【输出格式】
输出到文件transmit.out中。
Q行，每行一个正整数，表示第i 次请求在传输的时候至少需要花费多少单位的时
间。
【样例1输入】
1 7 3 3
2 1 2 3 4 5 6 7
第12页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
3 1 2
4 1 3
5 2 4
6 2 5
7 3 6
8 3 7
9 4 7
10 5 6
11 1 2
【样例1输出】
1 12
2 12
3 3
【样例1解释】
对于第一组请求，由于主机4,7之间需要至少4根网线才能连接，因此数据无法在
两台主机之间直接传输，其至少需要一次转发；我们让其在主机1进行一次转发，不难
发现主机1和主机4,7之间都只需要两根网线即可连接，且主机1的数据处理时间仅
为1，为所有主机中最小，因此最少传输的时间为4 + 1 + 7 = 12。
对于第三组请求，由于主机1,2之间只需要1根网线就能连接，因此数据直接传输
就是最优解，最少传输的时间为1 + 2 = 3。
【样例2】
见选手目录下的transmit/transmit2.in 与transmit/transmit2.ans。
该样例满足测试点2的限制。
【样例3】
见选手目录下的transmit/transmit3.in 与transmit/transmit3.ans。
该样例满足测试点3的限制。
【样例4】
见选手目录下的transmit/transmit4.in 与transmit/transmit4.ans。
该样例满足测试点20的限制。
第13页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
【数据范围】
对于所有的测试数据，满足1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3,1≤a
i
,b
i ≤
n,1≤s
i
,t
i ≤n,s
i
?=t
i。
测试点 n Q k 特殊性质
1
≤10 ≤10
= 2
是
2 = 3
3
≤200 ≤200
= 2
4,5 = 3
6,7
≤2,000 ≤2,000
= 1
否
8,9 = 2
10,11 = 3
12,13 ≤2×10
5
≤2×10
5
= 1
14 ≤5×10
4
≤5×10
4
= 2
是
15,16 ≤10
5
≤10
5
17,18,19 ≤2×10
5
≤2×10
5
否
20 ≤5×10
4
≤5×10
4
= 3
是
21,22 ≤10
5
≤10
5
23,24,25 ≤2×10
5
≤2×10
5
否
特殊性质：保证a
i =i+ 1，而b
i 则从1,2,. . ., i中等概率选取。
第14页 共14页
*/
/*
2022 CCF非专业级软件能力认证
CSP-J/S 2022第二轮认证
提高级
时间：2022年10月29日14:30～18:30
题目名称 假期计划 策略游戏 星战 数据传输
题目类型 传统型 传统型 传统型 传统型
目录 holiday game galaxy transmit
可执行文件名 holiday game galaxy transmit
输入文件名 holiday.in game.in galaxy.in transmit.in
输出文件名 holiday.out game.out galaxy.out transmit.out
每个测试点时限 2.0秒 1.0秒 2.0秒 3.0秒
内存限制 512 MiB 512 MiB 512 MiB 1024 MiB
测试点数目 20 20 20 25
测试点是否等分 是 是 是 是
提交源程序文件名
对于C++ 语言 holiday.cpp game.cpp galaxy.cpp transmit.cpp
编译选项
对于C++ 语言 ‐O2 ‐std=c++14
.
注
.
意
.
事
.
项（
.
请
.
仔
.
细
.
阅
.
读）
1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. C/C++中函数main()的返回值类型必须是int，程序正常结束时的返回值必须
是0。
3. 提交的程序代码文件的放置位置请参考各省的具体要求。
4. 因违反以上三点而出现的错误或问题，申诉时一律不予受理。
5. 若无特殊说明，结果的比较方式为全文比较（过滤行末空格及文末回车）。
6. 选手提交的程序源文件必须不大于100KB。
7. 程序可使用的栈空间内存限制与题目的内存限制一致。
8. 全国统一评测时采用的机器配置为：Inter(R) Core(TM) i7-8700K CPU @3.70GHz，
内存32GB。上述时限以此配置为准。
9. 只提供Linux格式附加样例文件。
10. 评测在当前最新公布的NOI Linux下进行，各语言的编译器版本以此为准。
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
假期计划（holiday）
【题目描述】
小熊的地图上有n个点，其中编号为1的是它的家、编号为2,3,. . ., n的都是景
点。部分点对之间有双向直达的公交线路。如果点x与z
1、z
1 与z
2、……、z
k?1 与z
k、
z
k 与y之间均有直达的线路，那么我们称x与y之间的行程可转车k次通达；特别地，
如果点x与y之间有直达的线路，则称可转车0次通达。
很快就要放假了，小熊计划从家出发去4个
.
不
.
同的景点游玩，完成5段行程后回
家：家→景点A →景点B →景点C →景点D →家且每段行程最多转车k次。转车
时经过的点没有任何限制，既可以是家、也可以是景点，还可以重复经过相同的点。例
如，在景点A →景点B的这段行程中，转车时经过的点可以是家、也可以是景点C，
还可以是景点D →家这段行程转车时经过的点。
假设每个景点都有一个分数，请帮小熊规划一个行程，使得小熊访问的四个
.
不
.
同景
点的分数之和最大
【输入格式】
从文件holiday.in中读入数据。
第一行包含3个正整数n,m, k，分别表示地图上点的个数、双向直达的点对数量、
每段行程最多的转车次数。
第二行包含n?1个正整数，分别表示编号为2,3,. .. , n的景点的分数。
接下来m行，每行包含两个正整数x,y，表示点x和y之间有道路直接相连，保
证1≤x,y≤n，且没有重边，自环。
【输出格式】
输出到文件holiday.out中。
输出一个正整数，表示小熊经过的4个不同景点的分数之和的最大值。
【样例1输入】
1 8 8 1
2 9 7 1 8 2 3 6
3 1 2
4 2 3
5 3 4
6 4 5
7 5 6
第2页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
8 6 7
9 7 8
10 8 1
【样例1输出】
1 27
【样例1解释】
当计划的行程为1 → 2 → 3 → 5 → 7 → 1时，4个景点的分数之和为9+7+8+3 = 27，
可以证明其为最大值。
行程1 → 3 → 5 → 7 → 8 → 1的景点分数之和为24、行程1 → 3 → 2 → 8 → 7
→ 1的景点分数之和为25。它们都符合要求，但分数之和不是最大的。
行程1 → 2 → 3 → 5 → 8 → 1的景点分数之和为30，但其中5 → 8至少需要转车
2次，因此不符合最多转车k= 1次的要求。
行程1 → 2 → 3 → 2 → 3 → 1的景点分数之和为32，但游玩的并非4个不同的景
点，因此也不符合要求。
【样例2输入】
1 7 9 0
2 1 1 1 2 3 4
3 1 2
4 2 3
5 3 4
6 1 5
7 1 6
8 1 7
9 5 4
10 6 4
11 7 4
【样例2输出】
1 7
第3页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
【样例3】
见选手目录下的holiday/holiday3.in与holiday/holiday3.ans。
【数据范围】
对于所有数据，保证5≤n≤2500,1≤m≤10000,0≤k≤100, 所有景点的分数
1≤s
i ≤10
18
。保证至少存在一组符合要求的行程。
测试点编号 n≤ m≤ k≤
1～3
10 20
0
4～5 5
6～8 20 50 100
9～11
300 1000
0
12～14 100
15～17
2500 10000
0
18～20 100
第4页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
策略游戏（game）
【题目描述】
小L和小Q在玩一个策略游戏。
有一个长度为n的数组A和一个长度为m的数组B，在此基础上定义一个大小
为n×m的矩阵C，满足Cij =Ai ×Bj。所有下标均从1开始。
游戏一共会进行q 轮，在每一轮游戏中，会事先给出4个参数l
1
,r
1
,l
2
,r
2，满足
1≤l
1≤r
1≤n,1≤l
2≤r
2≤m。
游戏中，小L先选择一个l
1 ～r
1 之间的下标x，然后小Q选择一个l
2 ～r
2 之间
的下标y。定义这一轮游戏中二人的得分是Cxy。
小L的目标是使得这个得分尽可能大，小Q的目标是使得这个得分尽可能小。同
时两人都是足够聪明的玩家，每次都会采用最优的策略。
请问：按照二人的最优策略，每轮游戏的得分分别是多少？
【输入格式】
从文件game.in中读入数据。
第一行输入3个正整数n,m, q，分别表示数组A，数组B的长度和游戏轮数。
第二行：n个整数，表示Ai，分别表示数组A的元素。
第三行：m个整数，表示Bi，分别表示数组B的元素。
接下来q行，每行4个正整数，表示这一次游戏的l
1
,r
1
,l
2
,r
2。
【输出格式】
输出到文件game.out中。
输出共q行，每行一个整数，分别表示每一轮游戏中，小L和小Q在最优策略下
的得分。
【样例1输入】
1 3 2 2
2 0 1 ‐2
3 ‐3 4
4 1 3 1 2
5 2 3 2 2
第5页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例1输出】
1 0
2 4
【样例1解释】
这组数据中，矩阵C如下：
1 0 0
2 ‐3 4
3 6 ‐8
在第一轮游戏中，无论小L选取的是x= 2还是x= 3，小Q都有办法选择某个
y使得最终的得分为负数。因此小L选择x= 1是最优的，因为这样得分一定为0。
而在第二轮游戏中，由于小L可以选x= 2，小Q只能选y= 2，如此得分为4。
【样例2输入】
1 6 4 5
2 3 ‐1 ‐2 1 2 0
3 1 2 ‐1 ‐3
4 1 6 1 4
5 1 5 1 4
6 1 4 1 2
7 2 6 3 4
8 2 5 2 3
【样例2输出】
1 0
2 ‐2
3 3
4 2
5 ‐1
【样例3】
见选手目录下的game/game3.in与game/game3.ans。
第6页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例4】
见选手目录下的game/game4.in与game/game4.ans。
【数据范围】
对于所有数据，1≤n,m, q≤10
5
,?10
9
≤Ai,B
i ≤10
9
。对于每轮游戏而言，1≤
l
1≤r
1≤n,1≤l
2≤r
2≤m。
测试点编号 n,m, q≤ 特殊条件
1
200
1,2
2 1
3 2
4～5 无
6
1000
1,2
7～8 1
9～10 2
11～12 无
13
10
5
1,2
14～15 1
16～17 2
18～20 无
其中，特殊性质1为：保证Ai,B
i >0。
特殊性质2为：保证对于每轮游戏而言，要么l
1=r
1，要么l
2=r
2。
第7页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
星战（galaxy）
【题目描述】
在这一轮的星际战争中，我方在宇宙中建立了n个据点，以m个单向虫洞连接。我
们把终点为据点u的所有虫洞归为据点u的虫洞。
战火纷飞之中这些虫洞很难长久存在，敌人的打击随时可能到来。这些打击中的有
效打击可以分为两类：
1. 敌人会摧毁某个虫洞，这会使它连接的两个据点无法再通过这个虫洞直接到达，
但这样的打击无法摧毁它连接的两个据点。
2. 敌人会摧毁某个据点，由于虫洞的主要技术集中在出口处，这会导致该据点的所
有还未被摧毁的虫洞被一同摧毁。而从这个据点出发的虫洞则
.
不
.
会
.
摧
.
毁。
注意：摧毁只会导致虫洞不可用，而不会消除它的存在。
为了抗击敌人并维护各部队和各据点之间的联系，我方发展出了两种特种部队负责
修复虫洞：
?A型特种部队则可以将某个特定的虫洞修复。
?B型特种部队可以将某据点的所有损坏的虫洞修复。
考虑到敌人打击的特点，我方并未在据点上储备过多的战略物资。因此只要这个据
点的某一条虫洞被修复，处于可用状态，那么这个据点也是可用的。
我方掌握了一种苛刻的空间特性，利用这一特性我方战舰可以沿着虫洞瞬移到敌方
阵营，实现精确打击。
为了把握发动反攻的最佳时机，指挥部必须关注战场上的所有变化，为了寻找一个
能够进行反攻的时刻。总指挥认为：
?如果从我方的任何据点出发，在选择了合适的路线的前提下，可以进行无限次的
虫洞穿梭（可以多次经过同一据点或同一虫洞），那么这个据点就可以
.
实
.
现
.
反
.
击。
?为了使虫洞穿梭的过程连续，尽量减少战舰在据点切换虫洞时的质能损耗，当且
仅当
.
只
.
有
.
一
.
个
.
从
.
该
.
据
.
点
.
出
.
发
.
的
.
虫
.
洞
.
可
.
用时，这个据点可以
.
实
.
现
.
连
.
续
.
穿
.
梭。
?如果我方所有据点都可以
.
实
.
现
.
反
.
击，也都可以
.
实
.
现
.
连
.
续
.
穿
.
梭，那么这个时刻就是
一个绝佳的
.
反
.
攻时刻。
总司令为你下达命令，要求你根据战场上实时反馈的信息，迅速告诉他当前的时刻
是否能够进行一次
.
反
.
攻。
【输入格式】
从文件galaxy.in中读入数据。
输入的第一行包含两个正整数n,m。
接下来m行每行两个数u,v，表示一个从据点u出发到据点v的虫洞。保证u?=v，
保证不会有两条相同的虫洞。初始时所有的虫洞和据点都是完好的。
第8页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
接下来一行一个正整数q表示询问个数。
接下来q行每行表示一次询问或操作。首先读入一个正整数t表示指令类型：
?若t= 1，接下来两个整数u,v表示敌人摧毁了从据点u出发到据点v的虫洞。
保证该虫洞存在且未被摧毁。
?若t= 2，接下来一个整数u表示敌人摧毁了据点u。如果该据点的虫洞已全部
被摧毁，那么这次袭击不会有任何效果。
?若t= 3，接下来两个整数u,v表示我方修复了从据点u出发到据点v的虫洞。
保证该虫洞存在且被摧毁。
?若t= 4，接下来一个整数u表示我方修复了据点u。如果该据点没有被摧毁的
虫洞，那么这次修复不会有任何效果。
在每次指令执行之后，你需要判断能否进行一次反攻。如果能则输出YES否则输出
NO。
【输出格式】
输出到文件galaxy.out中。
输出一共q行。对于每个指令，输出这个指令执行后能否进行反攻。
【样例1输入】
1 3 6
2 2 3
3 2 1
4 1 2
5 1 3
6 3 1
7 3 2
8 11
9 1 3 2
10 1 2 3
11 1 1 3
12 1 1 2
13 3 1 3
14 3 3 2
15 2 3
16 1 3 1
17 3 1 3
18 4 2
第9页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
19 1 3 2
【样例1输出】
1 NO
2 NO
3 YES
4 NO
5 YES
6 NO
7 NO
8 NO
9 YES
10 NO
11 NO
【样例1解释】
虫洞状态可以参考下面的图片，图中的边表示存在且未被摧毁的虫洞：
图1:样例1解释
【样例2】
见选手目录下的galaxy/galaxy2.in与galaxy/galaxy2.ans。
第10页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
【样例3】
见选手目录下的galaxy/galaxy3.in与galaxy/galaxy3.ans。
【样例4】
见选手目录下的galaxy/galaxy4.in与galaxy/galaxy4.ans。
【数据范围】
对于所有数据保证：1≤n≤5×10
5
,1≤m≤5×10
5
,1≤q≤5×10
5
。
测试点 n m q 特殊限制
1,2,3 ≤10 ≤20 ≤50
无
4,5,6,7,8 ≤10
3
≤10
4
≤10
3
9,10
≤5×10
5
≤5×10
5
≤5×10
5
保证没有t= 2和t= 4的情况
11,12 保证没有t= 4的情况
13,14,15,16 ≤10
5
无
17,18,19,20 ≤5×10
5
第11页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
数据传输（transmit）
【题目描述】
小C正在设计计算机网络中的路由系统。
测试用的网络总共有n台主机，依次编号为1～n。这n台主机之间由n?1根网
线连接，第i 条网线连接个主机a
i 和b
i。保证任意两台主机可以通过有限根网线直接
或者间接地相连。受制于信息发送的功率，主机a能够直接将信息传输给主机b当且仅
当两个主机在可以通过不超过k根网线直接或者间接的相连。
在计算机网络中，数据的传输往往需要通过若干次转发。假定小C需要将数据从主
机a传输到主机b(a?=b)，则其会选择出若干台用于传输的主机c
1=a,c
2
,·· ·,cm?1
,cm=
b，并按照如下规则转发：对于所有的1≤i < m, 主机c
i 将信息直接发送给c
i+1。
每台主机处理信息都需要一定的时间，第i 台主机处理信息需要v
i 单位的时间。数
据在网络中的传输非常迅速，因此传输的时间可以忽略不计。据此，上述传输过程花费
的时间为
∑
m
i=1
v
c
i
。
现在总共有q次数据发送请求，第i 次请求会从主机s
i 发送数据到主机t
i。小C
想要知道，对于每一次请求至少需要花费多少单位时间才能完成传输。
【输入格式】
从文件transmit.in 中读入数据。
输入的第一行包含三个正整数n,Q, k，分别表示网络主机个数，请求个数，传输参
数。数据保证1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3。
输入的第二行包含n个正整数，第i 个正整数表示v
i，保证1≤v
i ≤10
9
。
接下来n?1行，第i 行包含两个正整数a
i
,b
i，表示一条连接主机a
i
,b
i 的网线。保
证1≤a
i
,b
i ≤n。
接下来Q行，第i 行包含两个正整数s
i
,t
i，表示一次从主机s
i 发送数据到主机t
i
的请求。保证1≤s
i
,t
i ≤n,s
i
?=t
i。
【输出格式】
输出到文件transmit.out中。
Q行，每行一个正整数，表示第i 次请求在传输的时候至少需要花费多少单位的时
间。
【样例1输入】
1 7 3 3
2 1 2 3 4 5 6 7
第12页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
3 1 2
4 1 3
5 2 4
6 2 5
7 3 6
8 3 7
9 4 7
10 5 6
11 1 2
【样例1输出】
1 12
2 12
3 3
【样例1解释】
对于第一组请求，由于主机4,7之间需要至少4根网线才能连接，因此数据无法在
两台主机之间直接传输，其至少需要一次转发；我们让其在主机1进行一次转发，不难
发现主机1和主机4,7之间都只需要两根网线即可连接，且主机1的数据处理时间仅
为1，为所有主机中最小，因此最少传输的时间为4 + 1 + 7 = 12。
对于第三组请求，由于主机1,2之间只需要1根网线就能连接，因此数据直接传输
就是最优解，最少传输的时间为1 + 2 = 3。
【样例2】
见选手目录下的transmit/transmit2.in 与transmit/transmit2.ans。
该样例满足测试点2的限制。
【样例3】
见选手目录下的transmit/transmit3.in 与transmit/transmit3.ans。
该样例满足测试点3的限制。
【样例4】
见选手目录下的transmit/transmit4.in 与transmit/transmit4.ans。
该样例满足测试点20的限制。
第13页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
【数据范围】
对于所有的测试数据，满足1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3,1≤a
i
,b
i ≤
n,1≤s
i
,t
i ≤n,s
i
?=t
i。
测试点 n Q k 特殊性质
1
≤10 ≤10
= 2
是
2 = 3
3
≤200 ≤200
= 2
4,5 = 3
6,7
≤2,000 ≤2,000
= 1
否
8,9 = 2
10,11 = 3
12,13 ≤2×10
5
≤2×10
5
= 1
14 ≤5×10
4
≤5×10
4
= 2
是
15,16 ≤10
5
≤10
5
17,18,19 ≤2×10
5
≤2×10
5
否
20 ≤5×10
4
≤5×10
4
= 3
是
21,22 ≤10
5
≤10
5
23,24,25 ≤2×10
5
≤2×10
5
否
特殊性质：保证a
i =i+ 1，而b
i 则从1,2,. . ., i中等概率选取。
第14页 共14页
*/
/*
2022 CCF非专业级软件能力认证
CSP-J/S 2022第二轮认证
提高级
时间：2022年10月29日14:30～18:30
题目名称 假期计划 策略游戏 星战 数据传输
题目类型 传统型 传统型 传统型 传统型
目录 holiday game galaxy transmit
可执行文件名 holiday game galaxy transmit
输入文件名 holiday.in game.in galaxy.in transmit.in
输出文件名 holiday.out game.out galaxy.out transmit.out
每个测试点时限 2.0秒 1.0秒 2.0秒 3.0秒
内存限制 512 MiB 512 MiB 512 MiB 1024 MiB
测试点数目 20 20 20 25
测试点是否等分 是 是 是 是
提交源程序文件名
对于C++ 语言 holiday.cpp game.cpp galaxy.cpp transmit.cpp
编译选项
对于C++ 语言 ‐O2 ‐std=c++14
.
注
.
意
.
事
.
项（
.
请
.
仔
.
细
.
阅
.
读）
1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. C/C++中函数main()的返回值类型必须是int，程序正常结束时的返回值必须
是0。
3. 提交的程序代码文件的放置位置请参考各省的具体要求。
4. 因违反以上三点而出现的错误或问题，申诉时一律不予受理。
5. 若无特殊说明，结果的比较方式为全文比较（过滤行末空格及文末回车）。
6. 选手提交的程序源文件必须不大于100KB。
7. 程序可使用的栈空间内存限制与题目的内存限制一致。
8. 全国统一评测时采用的机器配置为：Inter(R) Core(TM) i7-8700K CPU @3.70GHz，
内存32GB。上述时限以此配置为准。
9. 只提供Linux格式附加样例文件。
10. 评测在当前最新公布的NOI Linux下进行，各语言的编译器版本以此为准。
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
假期计划（holiday）
【题目描述】
小熊的地图上有n个点，其中编号为1的是它的家、编号为2,3,. . ., n的都是景
点。部分点对之间有双向直达的公交线路。如果点x与z
1、z
1 与z
2、……、z
k?1 与z
k、
z
k 与y之间均有直达的线路，那么我们称x与y之间的行程可转车k次通达；特别地，
如果点x与y之间有直达的线路，则称可转车0次通达。
很快就要放假了，小熊计划从家出发去4个
.
不
.
同的景点游玩，完成5段行程后回
家：家→景点A →景点B →景点C →景点D →家且每段行程最多转车k次。转车
时经过的点没有任何限制，既可以是家、也可以是景点，还可以重复经过相同的点。例
如，在景点A →景点B的这段行程中，转车时经过的点可以是家、也可以是景点C，
还可以是景点D →家这段行程转车时经过的点。
假设每个景点都有一个分数，请帮小熊规划一个行程，使得小熊访问的四个
.
不
.
同景
点的分数之和最大
【输入格式】
从文件holiday.in中读入数据。
第一行包含3个正整数n,m, k，分别表示地图上点的个数、双向直达的点对数量、
每段行程最多的转车次数。
第二行包含n?1个正整数，分别表示编号为2,3,. .. , n的景点的分数。
接下来m行，每行包含两个正整数x,y，表示点x和y之间有道路直接相连，保
证1≤x,y≤n，且没有重边，自环。
【输出格式】
输出到文件holiday.out中。
输出一个正整数，表示小熊经过的4个不同景点的分数之和的最大值。
【样例1输入】
1 8 8 1
2 9 7 1 8 2 3 6
3 1 2
4 2 3
5 3 4
6 4 5
7 5 6
第2页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
8 6 7
9 7 8
10 8 1
【样例1输出】
1 27
【样例1解释】
当计划的行程为1 → 2 → 3 → 5 → 7 → 1时，4个景点的分数之和为9+7+8+3 = 27，
可以证明其为最大值。
行程1 → 3 → 5 → 7 → 8 → 1的景点分数之和为24、行程1 → 3 → 2 → 8 → 7
→ 1的景点分数之和为25。它们都符合要求，但分数之和不是最大的。
行程1 → 2 → 3 → 5 → 8 → 1的景点分数之和为30，但其中5 → 8至少需要转车
2次，因此不符合最多转车k= 1次的要求。
行程1 → 2 → 3 → 2 → 3 → 1的景点分数之和为32，但游玩的并非4个不同的景
点，因此也不符合要求。
【样例2输入】
1 7 9 0
2 1 1 1 2 3 4
3 1 2
4 2 3
5 3 4
6 1 5
7 1 6
8 1 7
9 5 4
10 6 4
11 7 4
【样例2输出】
1 7
第3页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级假期计划（holiday）
【样例3】
见选手目录下的holiday/holiday3.in与holiday/holiday3.ans。
【数据范围】
对于所有数据，保证5≤n≤2500,1≤m≤10000,0≤k≤100, 所有景点的分数
1≤s
i ≤10
18
。保证至少存在一组符合要求的行程。
测试点编号 n≤ m≤ k≤
1～3
10 20
0
4～5 5
6～8 20 50 100
9～11
300 1000
0
12～14 100
15～17
2500 10000
0
18～20 100
第4页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
策略游戏（game）
【题目描述】
小L和小Q在玩一个策略游戏。
有一个长度为n的数组A和一个长度为m的数组B，在此基础上定义一个大小
为n×m的矩阵C，满足Cij =Ai ×Bj。所有下标均从1开始。
游戏一共会进行q 轮，在每一轮游戏中，会事先给出4个参数l
1
,r
1
,l
2
,r
2，满足
1≤l
1≤r
1≤n,1≤l
2≤r
2≤m。
游戏中，小L先选择一个l
1 ～r
1 之间的下标x，然后小Q选择一个l
2 ～r
2 之间
的下标y。定义这一轮游戏中二人的得分是Cxy。
小L的目标是使得这个得分尽可能大，小Q的目标是使得这个得分尽可能小。同
时两人都是足够聪明的玩家，每次都会采用最优的策略。
请问：按照二人的最优策略，每轮游戏的得分分别是多少？
【输入格式】
从文件game.in中读入数据。
第一行输入3个正整数n,m, q，分别表示数组A，数组B的长度和游戏轮数。
第二行：n个整数，表示Ai，分别表示数组A的元素。
第三行：m个整数，表示Bi，分别表示数组B的元素。
接下来q行，每行4个正整数，表示这一次游戏的l
1
,r
1
,l
2
,r
2。
【输出格式】
输出到文件game.out中。
输出共q行，每行一个整数，分别表示每一轮游戏中，小L和小Q在最优策略下
的得分。
【样例1输入】
1 3 2 2
2 0 1 ‐2
3 ‐3 4
4 1 3 1 2
5 2 3 2 2
第5页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例1输出】
1 0
2 4
【样例1解释】
这组数据中，矩阵C如下：
1 0 0
2 ‐3 4
3 6 ‐8
在第一轮游戏中，无论小L选取的是x= 2还是x= 3，小Q都有办法选择某个
y使得最终的得分为负数。因此小L选择x= 1是最优的，因为这样得分一定为0。
而在第二轮游戏中，由于小L可以选x= 2，小Q只能选y= 2，如此得分为4。
【样例2输入】
1 6 4 5
2 3 ‐1 ‐2 1 2 0
3 1 2 ‐1 ‐3
4 1 6 1 4
5 1 5 1 4
6 1 4 1 2
7 2 6 3 4
8 2 5 2 3
【样例2输出】
1 0
2 ‐2
3 3
4 2
5 ‐1
【样例3】
见选手目录下的game/game3.in与game/game3.ans。
第6页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级策略游戏（game）
【样例4】
见选手目录下的game/game4.in与game/game4.ans。
【数据范围】
对于所有数据，1≤n,m, q≤10
5
,?10
9
≤Ai,B
i ≤10
9
。对于每轮游戏而言，1≤
l
1≤r
1≤n,1≤l
2≤r
2≤m。
测试点编号 n,m, q≤ 特殊条件
1
200
1,2
2 1
3 2
4～5 无
6
1000
1,2
7～8 1
9～10 2
11～12 无
13
10
5
1,2
14～15 1
16～17 2
18～20 无
其中，特殊性质1为：保证Ai,B
i >0。
特殊性质2为：保证对于每轮游戏而言，要么l
1=r
1，要么l
2=r
2。
第7页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
星战（galaxy）
【题目描述】
在这一轮的星际战争中，我方在宇宙中建立了n个据点，以m个单向虫洞连接。我
们把终点为据点u的所有虫洞归为据点u的虫洞。
战火纷飞之中这些虫洞很难长久存在，敌人的打击随时可能到来。这些打击中的有
效打击可以分为两类：
1. 敌人会摧毁某个虫洞，这会使它连接的两个据点无法再通过这个虫洞直接到达，
但这样的打击无法摧毁它连接的两个据点。
2. 敌人会摧毁某个据点，由于虫洞的主要技术集中在出口处，这会导致该据点的所
有还未被摧毁的虫洞被一同摧毁。而从这个据点出发的虫洞则
.
不
.
会
.
摧
.
毁。
注意：摧毁只会导致虫洞不可用，而不会消除它的存在。
为了抗击敌人并维护各部队和各据点之间的联系，我方发展出了两种特种部队负责
修复虫洞：
?A型特种部队则可以将某个特定的虫洞修复。
?B型特种部队可以将某据点的所有损坏的虫洞修复。
考虑到敌人打击的特点，我方并未在据点上储备过多的战略物资。因此只要这个据
点的某一条虫洞被修复，处于可用状态，那么这个据点也是可用的。
我方掌握了一种苛刻的空间特性，利用这一特性我方战舰可以沿着虫洞瞬移到敌方
阵营，实现精确打击。
为了把握发动反攻的最佳时机，指挥部必须关注战场上的所有变化，为了寻找一个
能够进行反攻的时刻。总指挥认为：
?如果从我方的任何据点出发，在选择了合适的路线的前提下，可以进行无限次的
虫洞穿梭（可以多次经过同一据点或同一虫洞），那么这个据点就可以
.
实
.
现
.
反
.
击。
?为了使虫洞穿梭的过程连续，尽量减少战舰在据点切换虫洞时的质能损耗，当且
仅当
.
只
.
有
.
一
.
个
.
从
.
该
.
据
.
点
.
出
.
发
.
的
.
虫
.
洞
.
可
.
用时，这个据点可以
.
实
.
现
.
连
.
续
.
穿
.
梭。
?如果我方所有据点都可以
.
实
.
现
.
反
.
击，也都可以
.
实
.
现
.
连
.
续
.
穿
.
梭，那么这个时刻就是
一个绝佳的
.
反
.
攻时刻。
总司令为你下达命令，要求你根据战场上实时反馈的信息，迅速告诉他当前的时刻
是否能够进行一次
.
反
.
攻。
【输入格式】
从文件galaxy.in中读入数据。
输入的第一行包含两个正整数n,m。
接下来m行每行两个数u,v，表示一个从据点u出发到据点v的虫洞。保证u?=v，
保证不会有两条相同的虫洞。初始时所有的虫洞和据点都是完好的。
第8页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
接下来一行一个正整数q表示询问个数。
接下来q行每行表示一次询问或操作。首先读入一个正整数t表示指令类型：
?若t= 1，接下来两个整数u,v表示敌人摧毁了从据点u出发到据点v的虫洞。
保证该虫洞存在且未被摧毁。
?若t= 2，接下来一个整数u表示敌人摧毁了据点u。如果该据点的虫洞已全部
被摧毁，那么这次袭击不会有任何效果。
?若t= 3，接下来两个整数u,v表示我方修复了从据点u出发到据点v的虫洞。
保证该虫洞存在且被摧毁。
?若t= 4，接下来一个整数u表示我方修复了据点u。如果该据点没有被摧毁的
虫洞，那么这次修复不会有任何效果。
在每次指令执行之后，你需要判断能否进行一次反攻。如果能则输出YES否则输出
NO。
【输出格式】
输出到文件galaxy.out中。
输出一共q行。对于每个指令，输出这个指令执行后能否进行反攻。
【样例1输入】
1 3 6
2 2 3
3 2 1
4 1 2
5 1 3
6 3 1
7 3 2
8 11
9 1 3 2
10 1 2 3
11 1 1 3
12 1 1 2
13 3 1 3
14 3 3 2
15 2 3
16 1 3 1
17 3 1 3
18 4 2
第9页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
19 1 3 2
【样例1输出】
1 NO
2 NO
3 YES
4 NO
5 YES
6 NO
7 NO
8 NO
9 YES
10 NO
11 NO
【样例1解释】
虫洞状态可以参考下面的图片，图中的边表示存在且未被摧毁的虫洞：
图1:样例1解释
【样例2】
见选手目录下的galaxy/galaxy2.in与galaxy/galaxy2.ans。
第10页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级星战（galaxy）
【样例3】
见选手目录下的galaxy/galaxy3.in与galaxy/galaxy3.ans。
【样例4】
见选手目录下的galaxy/galaxy4.in与galaxy/galaxy4.ans。
【数据范围】
对于所有数据保证：1≤n≤5×10
5
,1≤m≤5×10
5
,1≤q≤5×10
5
。
测试点 n m q 特殊限制
1,2,3 ≤10 ≤20 ≤50
无
4,5,6,7,8 ≤10
3
≤10
4
≤10
3
9,10
≤5×10
5
≤5×10
5
≤5×10
5
保证没有t= 2和t= 4的情况
11,12 保证没有t= 4的情况
13,14,15,16 ≤10
5
无
17,18,19,20 ≤5×10
5
第11页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
数据传输（transmit）
【题目描述】
小C正在设计计算机网络中的路由系统。
测试用的网络总共有n台主机，依次编号为1～n。这n台主机之间由n?1根网
线连接，第i 条网线连接个主机a
i 和b
i。保证任意两台主机可以通过有限根网线直接
或者间接地相连。受制于信息发送的功率，主机a能够直接将信息传输给主机b当且仅
当两个主机在可以通过不超过k根网线直接或者间接的相连。
在计算机网络中，数据的传输往往需要通过若干次转发。假定小C需要将数据从主
机a传输到主机b(a?=b)，则其会选择出若干台用于传输的主机c
1=a,c
2
,·· ·,cm?1
,cm=
b，并按照如下规则转发：对于所有的1≤i < m, 主机c
i 将信息直接发送给c
i+1。
每台主机处理信息都需要一定的时间，第i 台主机处理信息需要v
i 单位的时间。数
据在网络中的传输非常迅速，因此传输的时间可以忽略不计。据此，上述传输过程花费
的时间为
∑
m
i=1
v
c
i
。
现在总共有q次数据发送请求，第i 次请求会从主机s
i 发送数据到主机t
i。小C
想要知道，对于每一次请求至少需要花费多少单位时间才能完成传输。
【输入格式】
从文件transmit.in 中读入数据。
输入的第一行包含三个正整数n,Q, k，分别表示网络主机个数，请求个数，传输参
数。数据保证1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3。
输入的第二行包含n个正整数，第i 个正整数表示v
i，保证1≤v
i ≤10
9
。
接下来n?1行，第i 行包含两个正整数a
i
,b
i，表示一条连接主机a
i
,b
i 的网线。保
证1≤a
i
,b
i ≤n。
接下来Q行，第i 行包含两个正整数s
i
,t
i，表示一次从主机s
i 发送数据到主机t
i
的请求。保证1≤s
i
,t
i ≤n,s
i
?=t
i。
【输出格式】
输出到文件transmit.out中。
Q行，每行一个正整数，表示第i 次请求在传输的时候至少需要花费多少单位的时
间。
【样例1输入】
1 7 3 3
2 1 2 3 4 5 6 7
第12页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
3 1 2
4 1 3
5 2 4
6 2 5
7 3 6
8 3 7
9 4 7
10 5 6
11 1 2
【样例1输出】
1 12
2 12
3 3
【样例1解释】
对于第一组请求，由于主机4,7之间需要至少4根网线才能连接，因此数据无法在
两台主机之间直接传输，其至少需要一次转发；我们让其在主机1进行一次转发，不难
发现主机1和主机4,7之间都只需要两根网线即可连接，且主机1的数据处理时间仅
为1，为所有主机中最小，因此最少传输的时间为4 + 1 + 7 = 12。
对于第三组请求，由于主机1,2之间只需要1根网线就能连接，因此数据直接传输
就是最优解，最少传输的时间为1 + 2 = 3。
【样例2】
见选手目录下的transmit/transmit2.in 与transmit/transmit2.ans。
该样例满足测试点2的限制。
【样例3】
见选手目录下的transmit/transmit3.in 与transmit/transmit3.ans。
该样例满足测试点3的限制。
【样例4】
见选手目录下的transmit/transmit4.in 与transmit/transmit4.ans。
该样例满足测试点20的限制。
第13页 共14页
2022 CCF非专业级软件能力认证CSP-J/S 2022第二轮认证 提高级数据传输（transmit）
【数据范围】
对于所有的测试数据，满足1≤n≤2×10
5
,1≤Q≤2×10
5
,1≤k≤3,1≤a
i
,b
i ≤
n,1≤s
i
,t
i ≤n,s
i
?=t
i。
测试点 n Q k 特殊性质
1
≤10 ≤10
= 2
是
2 = 3
3
≤200 ≤200
= 2
4,5 = 3
6,7
≤2,000 ≤2,000
= 1
否
8,9 = 2
10,11 = 3
12,13 ≤2×10
5
≤2×10
5
= 1
14 ≤5×10
4
≤5×10
4
= 2
是
15,16 ≤10
5
≤10
5
17,18,19 ≤2×10
5
≤2×10
5
否
20 ≤5×10
4
≤5×10
4
= 3
是
21,22 ≤10
5
≤10
5
23,24,25 ≤2×10
5
≤2×10
5
否
特殊性质：保证a
i =i+ 1，而b
i 则从1,2,. . ., i中等概率选取。
第14页 共14页
*/
