
/** Bit manipulation
  * isPowerOfTwo:		checks if the number 'n' is a power of 2
***/

#include <iostream>
using namespace std;



bool isPowerOfTwo(int x)
{
	return (x && !(x & (x-1)));
}


int main()
{
	int n;
	cin>>n;
	
	if(isPowerOfTwo(n))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}