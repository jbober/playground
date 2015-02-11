//#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	     string s("abcdefgijklmnoprstquwzxABCDEFGHIJKL");
	          transform(s.begin(),s.end(),s.begin(),::_toupper);
		       cout<<s<<endl;
}
