#include "MutantStack.hpp"

int main()
{
    //----CASE 1 (SUBJECT TEST)----
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;

    //----CASE 2----
    // MutantStack<int> mystack;
    // for (int i = 1; i <= 100; i++) {
    //     mystack.push(i);
    // }
    // MutantStack<int>::iterator it = mystack.begin();
    // MutantStack<int>::iterator ite = mystack.end();
    // while (it != ite)
    // {
    //     std::cout << *it << " ";
    //     it++;
    // }
    // std::cout << std::endl;
}