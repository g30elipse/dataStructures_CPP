
/** Bit manipulation
  * isPowerOfTwo:		checks if the number 'n' is a power of 2
  * countOnes:			returns: number of ones in the binary representation of 'n'
  * bitCheck:			check if the ith bit is set in the binary form of  'n'
  * checkAllBits:		checks if all the bits are set in the binary form of 'n'
***/

#include <iostream>
using namespace std;


bool checkAllBits(int n)
{
	while(n)
	{
		if(!(n & 1))
			return false;
		n = n>>1;
	}
	return true;
}


bool isPowerOfTwo(int x)
{
	return (x && !(x & (x-1)));
}

bool bitCheck(int n, int i)
{
	return (n & (1<<(i-1)));
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

/* Alternative method
int countOnes(int n)
{
	int count=0;
	while(n)
	{
		if(n & 1)
			count++;
		n = n>>1;
	}
	return count;
}
*/


int main()
{
	int n;
	cin>>n;
	
	cout<<countOnes(n)<<endl;
	
	if(checkAllBits(n))
		cout<<"All bits are set";
	else
		cout<<"All bits are not set";
	
	return 0;
}