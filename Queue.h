#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

static const int INITIAL_SIZE = 0;

template <typename T>
class Queue
{
private:
    struct Node
    {
        private:
            T m_data;
            Node *m_nextNode= nullptr;
            Node<T>()=default;
            Node<T>(const Node<T>& node)=default;
            Node& operator=(const Node<T>& node)=default;
            ~Node()=default;
    };

    Node *m_head;
    Node *m_tail;
    int m_size;

public:
    class Iterator;
    Iterator begin();
    Iterator end();
    Iterator begin() const;
    Iterator end() const;
    Queue();
    Queue(const Queue<T> &q);
    ~Queue();
    Queue& operator=(const Queue<T>& q);
    void pushBack(const T& data);
    T& front();
    void popFront();
    int size() const;

    class EmptyQueue{};

};

template<typename T>
class Queue<T>::Iterator
{
    private:
        const Queue* m_queue;
        int m_index;
        Iterator(const Queue<T>* queue, int index);
        friend class Queue<T>;

    public:
        const T& operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator& it) const;
        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;

        class InvalidOperation&{};
};

template<typename T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int index): m_queue(queue), m_index(index)
{

}
template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_queue->m_tail->m_nextNode == nullptr)
    {
        throw InvalidOperation();
    }
    ++index;
    return this*;   
}

template<typename T>
const T& Queue<T>::Iterator::operator*() const
{

}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const 
{
    return this->m_index != i.m_index;
}


template<typename T>
Queue<T>::Queue() : m_size(INITIAL_SIZE), m_head(new Node<T>()), m_tail(this->m_head)
{
    //do we need bad_alloc here??
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
        m_head= m_head->m_nextNode;
        delete toDelete;
    }

    //  delete m_head; //??
    // delete m_tail; //??
}
template <typename T>
void Queue<T>::pushBack(const T& data)
{
    this->m_tail->m_nextNode= new Node<T>();
    if(this->m_tail->m_nextNode == nullptr)
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
    if (m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
void Queue<T>:: popFront()
{
    if (m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    Node<T>* toDelete = this-> m_head.m_nextNode;
    if (toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }
    m_head->m_nextNode= m_head->m_nextNode->m_nextNode;
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