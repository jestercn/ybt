#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double x;
	cin>>x>>n;
	for(int i = 0; i < n; ++i)
	{
		x *= 1 + 0.001;
	}
	cout<<fixed<<setprecision(4)<<x;
	return 0;
}
