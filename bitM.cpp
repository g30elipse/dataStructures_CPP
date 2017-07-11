
/** Bit manipulation
  * isPowerOfTwo:		checks if the number 'n' is a power of 2
***/

#include <iostream>
using namespace std;



bool isPowerOfTwo(int x)
{
	return (x && !(x & (x-1)));
}


int countOnes(int n)
{
	int count=0;
	while(n)
	{
		n = n & (n-1);
		count++;
	}
	return count;
}


int main()
{
	int n;
	cin>>n;
	
	cout<<countOnes(n)<<endl;
	
	return 0;
}