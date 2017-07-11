#include <iostream>
using namespace std;



bool isPowerOfTwo(int n)
{
	if(n == 0)
		return false;
	while(x%2 == 0)
		x /= 2;
	return(x == 1);
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