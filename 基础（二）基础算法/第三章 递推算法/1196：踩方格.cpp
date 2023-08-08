#include <bits/stdc++.h>
using namespace std;
/*
这里用左，右，上 代替 东，西，北。 
l[i]表示第i步向左走的走法数量
r[i]表示第i步向右走的走法数量
u[i]表示第i步向上走的走法数量
第1步 l[1]=r[1]=u[1]=1
第2步 l[2] = l[1] + u[1] = 2;r[2] = r[1] + u[1] = 2;u[2] = l[1] + r[1] + u[1]
1. 只有上一步是向左或上走时，现在才能向左走（因为如果之前是向右走的，现在此处左边是一个已经走过的坍塌的格子） 
因而现在向左走的走法数量是上一步向左和向上走法数量的加和。有：l[i] = l[i-1]+u[i-1]
2. 只有上一步是向右或向上走时，现在才能向右走。有：r[i]=r[i-1]+u[i-1]
3. 无论之前怎么走，都能向上走。有：u[i]=l[i-1]+r[i-1]+u[i-1]
第i步的总走法为第i-1步向上，向左，向右走法的加和
设第i步总走法为f[i],有
f[i] = l[i]+r[i]+u[i]
     = l[i-1]+u[i-1]+r[i-1]+u[i-1]+l[i-1]+r[i-1]+u[i-1]
     = 2(l[i-1]+u[i-1]+r[i-1]) + u[i-1]
已知：f[i-1] = l[i-1]+r[i-1]+u[i-1], u[i-1] = l[i-2]+r[i-2]+u[i-2] = f[i-2]
所以有f[i] = 2f[i-1] + f[i-2] 
f[1] = l[1]+r[1]+u[1] = 3
f[0]为一步都不走的初始状态，有1种走法，所以f[0]=1 
*/
int main()
{
	int n, f[25];
	cin>>n;
	f[0] = 1;
	f[1] = 3;
	for(int i = 2; i <= n; ++i)
		f[i] = 2*f[i-1] + f[i-2];
	cout<<f[n];
	return 0;
}
