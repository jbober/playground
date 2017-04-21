#include <iostream>

class Object
{
public:
    template<class T>
    void process()
{
	std::cout << "generic process \n";
}
};
template <>
    void Object::process<int>(){ std::cout << "proces<int>()\n";}
template <>
    void Object::process<double>(){ std::cout << "proces<double>()\n";}
int main()
{
	Object o;
	o.template process<double>();
	o.template process<int>();
	o.template process<float>();
	return 0;
}
