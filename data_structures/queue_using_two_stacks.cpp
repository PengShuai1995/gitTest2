#include <cassert>
#include <iostream>
#include <stack>

namespace{

    template<typename T>
    class MyQueue{
        private:
            std::stack<T> s1, s2;
        public:
            MyQueue() = default;

            void push(T x);

            const T& pop();
            const T& peek() const;
            bool empty() const;
    }
};
template <typename T>
void MyQueue<T>::push(T x)
{
    while (!s2.empty())
    {
        s1.push(s2.pop());
        s2.pop();
    }
    s2.push(x);
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    } 
}

template<typename T>
const T& MyQueue<T>::pop()
{
    const T& temp = MyQueue::peek();
    s2.pop();
    return temp;
}

template<typename T>
const T& MyQueue<T>::peek() const{
    if(!empty())
    {
        return s2.top();
    }
    std::cerr<<"Queue is empty"<<std::endl;
    exit(0);
}

template<typename T>
bool MyQueue<T>::empty() const{
    return s2.empty() && s1.empty();
}

void queue_test()
{
    MyQueue<int> que;
    std::cout<<"Test #1\n";
    que.push(2);
    que.push(5);
    que.push(0);
    assert(que.peek() == 2);
    assert(que.pop() == 2);
    assert(que.peek() == 5);
    assert(que.peek() == 5);


}