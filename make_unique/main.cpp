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
protected:
    unique_ptr<testing> t_;
public:

    repository(unique_ptr<testing> t) : t_(move(t))
    {

    }
    void virtual mockthis()
    {
        //some very ugly static call
    }
};

// under tests:
class repositoryTest : public repository
{
public:
    repositoryTest(unique_ptr<testing> t) : repository(move(t)) {}
    void mockThis();
};

int main()
{
    repositoryTest r(unique_ptr<testing>(new testing));

    return 0;
}

