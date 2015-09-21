#include <iostream>
#include <memory>

using namespace std;

class testing
{
public:
    testing(){ cout << "ctor" << endl;}
    ~testing(){ cout << "dtor"<< endl;}
};
class repository
{
private:
    unique_ptr<testing> t_;
public:

    repository(unique_ptr<testing> t) : t_(move(t))
    {

    }
};

void sink(unique_ptr<testing> t)
{

}

int main()
{
    repository r(unique_ptr<testing>(new testing));
//    repository(unique_ptr<testing> (new testing)) t;
    unique_ptr<testing> t(new testing);
    sink(unique_ptr<testing>{new testing});
    return 0;
}

