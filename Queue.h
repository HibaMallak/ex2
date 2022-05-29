#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

static const int INITIAL_SIZE = 0;
static const bool DIFF = false;

template <typename T>
class Queue
{
private:
    template <typename S>
    class Node
    {
        S m_data;
        Node<S> *m_nextNode= nullptr;
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
    Queue<T>::Node<T>* m_pointer;
    Node<T> * get_m_pointer()
    {
        return this->m_pointer;
    }

public:
    Iterator(Node<T>* pointer);
    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation{};                             //new
};


template<typename T>
class Queue<T>::ConstIterator
{
private:

    Node<T>* m_pointer;
    Node<T>* get_m_pointer()
    {
        return this->m_pointer;
    }


public:
    ConstIterator(Node<T>* pointer);
    ConstIterator(const Iterator& it);
    const T& operator*() const;
    ConstIterator& operator++() const;
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;

    class InvalidOperation {};
};

template<typename T>
Queue<T>::Iterator::Iterator(Node<T>* pointer): m_pointer(pointer)
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
    return Iterator(nullptr);
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_pointer.get_m_nextNode() == nullptr)                   //new: throw
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    this->m_pointer= this->m_pointer.get_m_nextNode();
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
Queue<T>::ConstIterator::ConstIterator(Node<T>* pointer): m_pointer(pointer)
{

}

template<typename T>
Queue<T>::ConstIterator::ConstIterator(const Iterator& it): m_pointer(it.get_m_pointer()) //??
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
    return ConstIterator(nullptr);
}

template<typename T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() const
{
    if(this->m_pointer->m_nextNode == nullptr)                   //new: throw
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    this->m_pointer= this->m_pointer.get_m_nextNode();
    return *this;
}

template<typename T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return this->m_pointer.get_m_data();
}

template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const
{
    return this->m_pointer!= i.get_m_pointer();                      //new: changed i.pointer to i->pointer
}


template<typename T>
Queue<T>::Queue() : m_head(new Node<T>()), m_tail(this->m_head), m_size(INITIAL_SIZE)
{

}


template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    this->m_head= Queue();

    for( typename Queue<T>::ConstIterator it = this->begin(); it != this->end(); ++it)
    {
        this.pushBack(it.get_m_pointer().get_m_data());         //??
    }
    this->m_size = q->size();
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)             //new: implemented
{
    if(*this == &q)
    {
        return *this;
    }

    for( typename Queue<T>::ConstIterator it = this->begin(); it != this->end(); ++it)
    {
        this->popFront();
    }

    for( typename Queue<T>::ConstIterator it = this->begin(); it != this->end(); ++it)
    {
        this.pushBack(q->begin());
        q->popFront();
    }
    this->m_size = q->size();
}

template <typename T>
Queue<T>::~Queue()                                   //new: implemented
{
    for( typename Queue<T>::ConstIterator it = this->begin(); it != this->end(); ++it)
    {
        Node<T> *toDelete = this->m_head;
        this->m_head= this->m_head.get_m_nextNode();
        delete toDelete;
    }
}

template <typename T>
void Queue<T>:: pushBack(const T& data)
{
    this->m_tail.get_m_nextNode()= new Node<T>();
    this->m_tail= this->m_tail.get_m_nextNode();
    this->m_tail.get_m_nextNode().get_m_data()= data;
    ++this->m_size;
}

template <typename T>
T& Queue<T>::front()
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
    Queue<T>* toDelete = this->m_head.get_m_nextNode();
    if(toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }
    else
    {
        this->m_head.get_m_nextNode()= m_head.get_m_nextNode().get_m_nextNode();    //new
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
    if(this->m_size != q->size())
    {
        return DIFF;
    }

    for( typename Queue<T>::ConstIterator it = this->begin(); it != this->end(); ++it)
    {
        if(this->front() != q->front())
        {
            return DIFF;
        }
    }
    return !DIFF;
}

template <typename T, typename S>
Queue<T> filter(Queue<T>& q, S func)
{
    Queue<T> newQueue;
    for( typename Queue<T>::ConstIterator it = q->begin(); it != q->end(); ++it)
    {
        if(func(newQueue->front()))
        {
            newQueue->pushBack(it);
        }

    }
    return newQueue;
}

template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
    //Queue<T> q1=q;                    //new: implemented
    while (q->size()>0)    //new: iterator
    {
        *func(q->front());
        q->pushBack(q.front());
        q->popFront();
    }
}

#endif