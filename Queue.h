#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

template <typename T>
class Queue
{
private:
    static const int INITIAL_SIZE = 0;
    static const bool DIFF = false;
    template <typename R>
    struct Node
    {
        int m_data;
        Node *m_nextNode= nullptr; 
        T get_m_data()
        {
            return this->m_data;
        }       
        Node<T> get_m_nextNode()
        {
            return this->m_nextNode;
        }            
        Node()=default;                               //new
        Node(const Node& node)=default;            //new
        Node& operator=(const Node& node)=default; //new
        ~Node()=default;                              //new
    };

    Node<T> m_head;
    Node<T> m_tail;
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

    class EmptyQueue {};                                   //new
};


template<typename T>
class Queue<T>::Iterator
{
private:

    Node<T>* m_pointer;
    Iterator(Node<T>* pointer);
    Node<T>* get_m_pointer()
    {
        return this->m_pointer;
    }
    friend class Queue<T>;

public:
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation& {};                             //new
};


template<typename T>
Queue<T>::Iterator::Iterator(Node<T>*  pointer): m_pointer(pointer)
{
}

template<typename T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    if (this->m_size == INITIAL_SIZE)                      //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return Iterator(this->m_head.get_m_nextNode());             //->m_nextNode

}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(this->m_tail.get_m_nextNode());
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_pointer->get_m_nextNode() == nullptr)                   //new: throw
    {
        throw InvalidOperation(); 
    }
    this->m_pointer= this->m_pointer->get_m_nextNode();
    return *this;
}

template<typename T>
T& Queue<T>::Iterator::operator*() const
{
    return this->m_pointer->m_data;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const
{
    return this->m_pointer!= i.get_m_pointer();                      //new: changed i.pointer to i->pointer
}


template<typename T>
class Queue<T>::ConstIterator
{
private:

    Node<T>* m_pointer;
    Node<T>* get_m_pointer()
    {
        return this->m_pointer;
    }
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

    class InvalidOperation& {};
};

template<typename T>
Queue<T>::ConstIterator::ConstIterator(Node<T>* pointer): m_pointer(pointer)
{

}

template<typename T>
Queue<T>::ConstIterator::ConstIterator(const Iterator& it): m_pointer(it.get_m_pointer())//??
{

}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    if (this->m_size == INITIAL_SIZE)                              //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(this->m_head.get_m_nextNode());                //->m_nextNode
}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(this->m_tail.get_m_nextNode());
}

template<typename T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() const
{
    if(this->m_pointer->m_nextNode == nullptr)                   //new: throw
    {
        throw InvalidOperation(); 
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
    return this->m_pointer!= i.get_m_pointer();                      //new: changed i.pointer to i->pointer
}


template<typename T>
Queue<T>::Queue<T>() : m_head(new Node<T>()), m_tail(this->m_head), m_size(INITIAL_SIZE)
{
}


template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    this->m_head= Queue<T>();   
    ConstIterator it = q.begin();                        //new: implemented
    for( it; it != q.end(); ++it)
    {
        this.pushBack(it.get_m_pointer().get_m_data());         //??
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
    ConstIterator it = this.begin();
    for(it;  it!= this.end(); ++it)
    {
        this.popFront();
    }
    for(it = q.begin();  it!= q.end(); ++it)              //changed to constiterator
    {   
        this.pushBack(q.begin());
        q.popFront();
    }
    this->m_size = q.size();
}

template <typename T>
Queue<T>::~Queue()                                   //new: implemented
{   
    while(this->m_head != this->m_tail)
    {
        Node<T>* toDelete = this-> m_head;
        this->m_head= this->m_head.get_m_nextNode();
        delete toDelete;
    }
}

template <typename T>
void Queue<T>:: pushBack(const T& data)
{
    this->m_tail.get_m_nextNode()= new Node<T>();
    if(this->m_tail.get_m_nextNode() == nullptr)          //new: throw
    {
        throw std::bad_alloc();
    }
    this->m_tail= this->m_tail.get_m_nextNode();
    this->m_tail.get_m_nextNode()= data;
    ++this->m_size;
}

template <typename T>
T& Queue<T>:: front()
{
    if(this->m_size == INITIAL_SIZE)                       //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head.get_m_nextNode().get_m_data();
}

template <typename T>
void Queue<T>:: popFront()
{
    if(this->m_size == INITIAL_SIZE)                //new: throw
    {
        throw Queue<T>::EmptyQueue();
    }
    Node<T>* toDelete = this->m_head.get_m_nextNode();
    if(toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }
    else
    {
        this->m_head.get_m_data()= m_head.get_m_nextNode().get_m_nextNode();    //new
    }
    delete toDelete;
    --this->m_size;
}

template <typename T>
int Queue<T>:: size() const
{
    return this->m_size;
}

template <typename T>
bool Queue<T>::operator==(const Queue<T>& q)    //errortype??
{
    if(this->m_size != q.size())
    {
        return DIFF;
    }
    ConstIterator it = q.begin();                        //new: implemented
    for( it; it != q.end(); ++it)
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
    ConstIterator it = q.begin();                        //new: implemented
    for( it; it != q.end(); ++it)        //new: iterator
    {
        if(!func(newQueue.front()))
        {
            newQueue.popFront();
        }
    }
    return newQueue;
}

template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
    ConstIterator it = q.begin();                        //new: implemented
    for( it; it != q.end(); ++it)     //new: iterator
    {
        *func(q.front());
        q.pushBack(q.front());
        q.popFront();
    }
}

#endif