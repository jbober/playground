#include <iostream>
#include <boost/circular_buffer.hpp>

using namespace std;
using namespace boost;

int main()
{
    //1. create
    circular_buffer<int> cb(5); // 5 element circullar buffer

    //2. Populate
    for (int i = 1; i <= 6; i++) //1,2,3,4,5,6
    {
        cb.push_back(i);
    }
    // cb now contains: 2,3,4,5,6
    for (auto i = cb.begin(); i != cb.end(); ++i)
    {
        cout << *i << *i << ' ';
    }
    // 3. Query
    cout << "cb[0]: " << cb[0] << endl;
    cout << "front: " << cb.front() << endl;
    cout << "cb[4] " << cb[4] << endl;
    cout << "back: " << cb.back() << endl;
    cout << endl;

    //4. push front

    return 0;
}
