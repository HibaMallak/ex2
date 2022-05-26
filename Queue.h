#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

template <typename T>
class Queue
{
private:
    static const int INITIAL_SIZE = 0;
    struct Node
    {
        T m_data;
        Node *m_nextNode= nullptr;
    };

    Node *m_head;
    Node *m_tail;
    int m_size;

public:

    Queue();
    Queue(const Queue<T> &q);
    ~Queue();
    Queue& operator=(const Queue& q);
    void pushBack(const T& data);
    T& front();
    void popFront();
    int size() const;

};


template<typename T>
Queue<T>::Queue() : m_size(INITIAL_SIZE), m_head(new Node<T>()), m_tail(this->m_head)
{

}


template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
    // do with iterator & pushback
    // build a new one
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
    if(*this == &q)
    {
        return *this;
    }

    //do pop until rek - push - iterator (loop)
}

template <typename T>
Queue<T>::~Queue()
{
    while (this->m_head)
    {
        Node<T>* toDelete = this-> m_head;
        m_head=m_head->m_nextNode;
        delete toDelete;
    }

    //  delete m_head; //??
    // delete m_tail; //??
}
template <typename T>
void Queue<T>:: pushBack(const T& data)
{
    this->m_tail->m_nextNode= new Node<T>();
    this->m_tail= this->m_tail->m_nextNode;
    this->m_tail->m_data=data;
    ++this->m_size;
}

template <typename T>
T& Queue<T>:: front()
{
    if (m_size == 0)
        // throw
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
void Queue<T>:: popFront()
{
    if(this->m_size == INITIAL_SIZE)
    {
        // throw
    }

    Node<T>* toDelete = this-> m_head.m_nextNode;

    if (toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }

    m_head->m_nextNode=m_head->m_nextNode->m_nextNode;
     delete toDelete;
    --this->m_size;

}

template <typename T>
int Queue<T>:: size() const
{
    return this->m_size;
}


template <typename T, typename S>
Queue<T> filter(Queue<T>& q, S func)
{
    Queue<T> newQueue = q;
    while(newQueue.size() > INITIAL_SIZE)
    {
        if(!(*func(newQueue.front())))
        {
            newQueue.popFront();
        }
    }
    return newQueue;
}

template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
    int QueueSize = q.size();
    q.pushBack(q.front());
    q.popFront();
    while(QueueSize > INITIAL_SIZE)
    {
        *func(newQueue.front());
        q.pushBack(q.front());
        q.popFront();
        --QueueSize;
    }
}

#endif