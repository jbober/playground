#include <algorithm>
#include <string>
#include <iostream>
#include <boost/bimap.hpp>

using namespace std;
using namespace boost;

int main()
{
	//1. typedef
	typedef bimap<int, string> bm_int_string;
	typedef bm_int_string::value_type value_type;

	//2.construct
	bm_int_string bm;

	//3. insert
	bm.insert(value_type(1, "Steve"));
	bm.insert(value_type(2, "Jane"));
	bm.insert(value_type(3, "Bob"));


	//4. access
	cout << "size of bm: " << bm.size() << endl;
	cout << "first place is: " << bm.left.at(1) << endl;
	cout << "Bob finished in: " << bm.right.at("Bob") << endl << endl;

	//5. Iterate
	cout << "Left iterator: " << endl;
	for (auto i = bm.left.begin(); i != bm.left.end(); ++i){
		cout << i->first << " : " << i->second << endl;
	}
	cout << endl << "Right iterator: " << endl;
	for (auto i = bm.right.begin(); i != bm.right.end(); ++i)
	{
		cout << i->first << " : " << i->second << endl;
	}
	cout << endl;
	//6. Uniqueness
	bm.insert(value_type(4, "Steve")); //warning - does nothin
	bm.left.replace_data(bm.left.find(3), "Lucy");

	return 0;
}