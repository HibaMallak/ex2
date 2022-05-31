//hello!
#ifndef EX2_QUEUE_H
#define EX2_QUEUE_H
#include <new>

static const int INITIAL_SIZE = 0;
//static const bool DIFF = false;
//static const bool IDENTICAL = true;

template <typename T>
class Queue
{
private:
    template <typename S>
    struct Node
    {
            S m_data;
            Node *m_nextNode = nullptr;
            Node()= default;
            Node(const Node& n) = default;
            Node& operator=(const Node& n)=default;
            ~Node() = default;
    };

    Node<T> *m_head;
    Node<T> *m_tail;
    int m_size;

public:
    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    Queue();
    Queue(const Queue<T> &q);
    ~Queue();
    Queue& operator=(const Queue<T>& q);
    void pushBack(const T& data);
    T& front() ;
    const T& front() const;
    void popFront();
    int size() const;
    //bool operator==(const Queue<T>& q);                 //are we allowed to add?

    class EmptyQueue {};
};


template<typename T>
class Queue<T>::Iterator
{
private:
    Queue<T>::Node<T> * m_pointer;
    friend class Queue<T>;

public:


    Iterator(Node<T>* pointer); //private??
    Iterator(const Iterator&) = default; //private??
    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator()= default;

    class InvalidOperation{};                             //new
};


template<typename T>
class Queue<T>::ConstIterator
{
private:

    Node<T>* m_pointer;
    friend class Queue<T>;

public:

    ConstIterator(Node<T>* pointer);
   // ConstIterator(const Iterator& it); no need
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    ~ConstIterator()= default;

    class InvalidOperation {};
};


template<typename T>
Queue<T>::Iterator::Iterator(Node<T>* pointer): m_pointer(pointer)
{
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    if (this->m_size == INITIAL_SIZE)
    {
        return Iterator(nullptr);
    }
    return Iterator(this->m_head->m_nextNode);

}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(nullptr);
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{

    if(this->m_pointer == nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }

    this->m_pointer= this->m_pointer->m_nextNode;
    return *this;
}

template<typename T>
T& Queue<T>::Iterator::operator*()
{
    return this->m_pointer->m_data;
}


template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const
{
    return this->m_pointer != i.m_pointer;
}

template<typename T>
Queue<T>::ConstIterator::ConstIterator(Node<T>* pointer): m_pointer(pointer)
{

}

//template<typename T>
//Queue<T>::ConstIterator::ConstIterator(const Iterator& it): m_pointer(it->m_pointer)  //something is not right here
//m_pointer(it->m_pointer)
//{
 //no need
//}


template<typename T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    if (this->m_size == INITIAL_SIZE)
    {
        return ConstIterator(nullptr);
    }

    return ConstIterator(this->m_head->m_nextNode);
}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(nullptr);
}

template<typename T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(this->m_pointer == nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    this->m_pointer= this->m_pointer->m_nextNode;
    return *this;
}

template<typename T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return this->m_pointer->m_data;
}


template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const
{
    return this->m_pointer != i.m_pointer;
}


template<typename T>
Queue<T>::Queue() : m_head(new Node<T>()), m_tail(this->m_head), m_size(INITIAL_SIZE) ///// in 191 test
{

}

template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    if(q.m_head->m_nextNode == nullptr)
    {
        throw Queue<T>::EmptyQueue();
    }
    try
    {
        this->m_head= new Node<T>(); /////////////////////// 366 in tests
    }
    catch(const std::bad_alloc& e)
    {
        throw e;
    }
    this->m_tail= this->m_head;
    this->m_size = INITIAL_SIZE;

    for( typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
    {
        try
        {
            this->pushBack(*it);
        }
        catch(const std::bad_alloc& e)
        {
            while(this->m_size > INITIAL_SIZE) //maybe with =?
            {
                this->popFront();
            }
            delete this->m_head;
            throw e;
        }
        
    }

}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) //change all!!!!!!
{
    if(this == &q)
    {
        return *this;
    }
    Node<T>* dummyNode = new Node<T>();
    Node<T>* temp = dummyNode;
    for(typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
    {
        try
        {
            temp->m_nextNode = new Node<T>(); //////////////////////////// 300 in tests
        }
        catch(const std::bad_alloc& e)
        {
            while(dummyNode->m_nextNode != nullptr)
            {
                Node<T>* toDelete = dummyNode;
                dummyNode = dummyNode->m_nextNode;
                delete toDelete;
            }
            throw e;
            return *this;
        }
        temp = temp->m_nextNode;
        temp->m_data = *it;
    }
    while(this->m_size > INITIAL_SIZE)
    {
        this->popFront();
    }
    this->m_head = dummyNode;
    this->m_tail = temp;
    this->m_size = q.size();
    return *this;
}
/*
    Queue<T> newQueue=q;

    for( typename Queue<T>::Iterator it = this->begin(); it != this->end(); ++it)
    {
        this->popFront();
    }

    for( typename Queue<T>::Iterator it = newQueue.begin(); it != newQueue.end(); ++it)
    {
            this->pushBack(newQueue.front());
            newQueue.popFront();
    }
*/



template <typename T>
Queue<T>::~Queue()
{/*
    for(int size = this->m_size; size >= INITIAL_SIZE; size--)
    {
        Node<T> *toDelete = this->m_head;

        if(this->m_head != this->m_tail)
        {
            this->m_head= this->m_head->m_nextNode;
        }
        delete toDelete;
    }*/
    while(this->m_size > INITIAL_SIZE)
    {
        this->popFront();
    }
    delete this->m_head;

}

template <typename T>
void Queue<T>:: pushBack(const T& data)
{   
    this->m_tail->m_nextNode= new Node<T>();
    this->m_tail= this->m_tail->m_nextNode;
    this->m_tail->m_data= data;
    ++this->m_size;
}

template <typename T>
const T& Queue<T>::front() const
{/*
    if(this->begin() == nullptr)
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
    */
    if(this->m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
 T& Queue<T>::front()
{
    //if(this->m_head == this->m_tail)
    if(this->m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
void Queue<T>:: popFront()
{
    if(this->m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    Node<T>* toDelete = this->m_head->m_nextNode;
    if(toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }
    else
    {
        this->m_head->m_nextNode= this->m_head->m_nextNode->m_nextNode;
    }
    delete toDelete;
    --this->m_size;
}

template <typename T>
int Queue<T>:: size() const
{
    return this->m_size;
}

/*template <typename T>
bool Queue<T>::operator==(const Queue<T>& q)
{
    if(this->m_size != q.size())
    {
        return DIFF;
    }
    int size= this->m_size;

    typename Queue<T>::ConstIterator it = q.begin();
    typename Queue<T>::Iterator our = this->begin();

    while (size>INITIAL_SIZE)
    {
        if (*it != *our)
        return DIFF;

        ++it;
        ++our;
        size--;
    }

    return IDENTICAL;
}*/

template <typename T, typename S>
Queue<T> filter(const Queue<T>& q, S func)
{
    if(q.size() <= INITIAL_SIZE)
    {
        return q;
    }
    Queue<T> newQueue;

    for(typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
    {
        if(func(*it))
        {
            try
            {
                newQueue.pushBack(*it);
            }
            catch(std::bad_alloc& e)
            {
                /*
                while(newQueue.size() > INITIAL_SIZE)
                {
                    newQueue.popFront();
                }
               // delete newQueue.m_head;*/ //~Queue
                throw e;
            }
        }
    }
    return newQueue;
}

template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
    for( typename Queue<T>::Iterator it = q.begin(); it != q.end(); ++it)
    {
        func(*it);
    }
}

#endif
