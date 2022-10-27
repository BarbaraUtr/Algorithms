#include<cstdio>
#include<algorithm>
#include<math.h>
//#include<bits\stdc++.h>

#define LOL 1000000007
#define pie sqrt(5)

using namespace std;

int main ()
{
	int long long fib, n=0;
	
	scanf("%lld", &n);
	
	fib=(1/pie)*pow(((1+pie)/2),n)-(1/pie)*pow(((1-pie)/2),n);
	fib%=LOL;
	
	printf("%lld", fib);
}
