#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

template <typename T>
class Queue
{
private:
    static const int INITIAL_SIZE = 0;
    static const bool DIFF = false;
    struct Node<T>
    {
        T m_data;
        Node<T> *m_nextNode= nullptr;                    
        Node<T>()=default;                               //new
        Node<T>(const Node<T>& node)=default;            //new
        Node<T>& operator=(const Node<T>& node)=default; //new
        ~Node<T>()=default;                              //new
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

    Queue<T>();
    Queue<T>(const Queue<T> &q);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& q);
    void pushBack(const T& data);
    T& front();
    void popFront();
    int size() const;
    bool operator==(const Queue<T>& q);

    class EmptyQueue{};                                   //new
};


template<typename T>
class Queue<T>::Iterator
{
private:

    Node<T>* m_pointer;
    Iterator(Node<T>* pointer);
    friend class Queue<T>;

public:
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation&{};                             //new
};


template<typename T>
Queue<T>::Iterator::Iterator(Node<T>*  pointer): m_pointer(pointer)
{
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    if (this->m_size == INITIAL_SIZE)                      //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return Iterator(this->m_head->m_nextNode);             //->m_nextNode

}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(m_tail->m_nextNode);
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_pointer->m_nextNode == nullptr)                   //new: throw
    {
        throw InvalidOperation(); 
    }
    m_pointer= m_pointer->m_nextNode;
    return *this;
}

template<typename T>
T& Queue<T>::Iterator::operator*() const
{
    return m_pointer->m_data;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const
{
    return this->m_pointer!=i->m_pointer;                      //new: changed i.pointer to i->pointer
}


template<typename T>
class Queue<T>::ConstIterator
{
private:

    Node* m_pointer;
    ConstIterator(Node<T>* pointer);
    friend class Queue<T>;
    friend class Queue<T>::Iterator;
    ConstIterator(const Iterator& it);

public:
    const T& operator*() const;
    ConstIterator& operator++() const;
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
};

template<typename T>
Queue<T>::ConstIterator::ConstIterator(Node<T>* pointer): m_pointer(pointer)
{

}

template<typename T>
Queue<T>::ConstIterator::ConstIterator(const Iterator& it): m_pointer(it->m_pointer)
{

}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    if (this->m_size == INITIAL_SIZE)                              //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(this->m_head->m_nextNode);                //->m_nextNode
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(m_tail->m_nextNode);
}

template<typename T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() const
{
    if(this->m_pointer->m_nextNode == nullptr)                   //new: throw
    {
        throw InvalidOperation(); 
    }
    m_pointer=m_pointer->m_nextNode;
    return *this;
}

template<typename T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return m_pointer->m_data;
}

template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const
{
    return this->m_pointer!=i->m_pointer;                      //new: changed i.pointer to i->pointer
}


template<typename T>
Queue<T>::Queue() : m_size(INITIAL_SIZE), m_head(new Node<T>()), m_tail(this->m_head)
{
}


template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    this->m_head= Queue();                           //new: implemented
    for(Iterator it = q.begin(); it != q.end(); ++it)
    {
        this.pushBack(it->m_pointer->m_data);
    }
    this->m_size = q.size();
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)             //new: implemented
{
    if(*this == &q)
    {
        return *this;
    }
    for(Iterator it = q.begin();  it!= q.end(); ++it)
    {   
        this->popFront();
        this.pushBack(it->m_pointer->m_data);
    }
    if(this->m_size > q.size())
    {
        for(Iterator it = this.begin();  it != this->m_size- q.end(); ++it)
        {
            this.popFront();
        }
    }
    this->m_size = q.size();
}

template <typename T>
Queue<T>::~Queue()                                   //new: implemented
{   
    while(this->m_head != this->m_tail)
    {
        Node<T>* toDelete = this-> m_head;
        this->m_head=this->m_head->m_nextNode;
        delete toDelete;
    }
    delete toDelete;
}

template <typename T>
void Queue<T>:: pushBack(const T& data)
{
    this->m_tail->m_nextNode= new Node<T>();
    if(this->m_tail->m_nextNode == nullptr)          //new: throw
    {
        throw std::bad_alloc();
    }
    this->m_tail= this->m_tail->m_nextNode;
    this->m_tail->m_data= data;
    ++this->m_size;
}

template <typename T>
T& Queue<T>:: front()
{
    if(this->m_size == INITIAL_SIZE)                       //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
void Queue<T>:: popFront()
{
    if(this->m_size == INITIAL_SIZE)                //new: throw
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
        this->m_head->m_nextNode= m_head->m_nextNode->m_nextNode;
    }
    delete toDelete;
    --this->m_size;
}

template <typename T>
int Queue<T>:: size() const
{
    return this->m_size;
}

bool Queue<T>::operator==(const Queue& q)
{
    if(this->m_size != q.size())
    {
        return DIFF;
    }
    for(Iterator it = q.begin(); it != q.end(); ++it)
    {
        if(this.front() != q.front())
        {
            return DIFF;
        }
    }
    return !DIFF;
}

template <typename T, typename S>
Queue<T> filter(Queue<T>& q, S func)
{
    Queue<T> newQueue = q;
    for(Iterator it = q.begin(); it != q.end(); ++it)        //new: iterator
    {
        if(!*func(newQueue.front()))
        {
            newQueue.popFront();
        }
    }
    return newQueue;
}

template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
    for(Iterator it = q.begin(); it != q.end(); ++it)        //new: iterator
    {
        *func(newQueue.front());
        q.pushBack(q.front());
        q.popFront();
    }
}

#endif