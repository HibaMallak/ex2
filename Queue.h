#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

static const int INITIAL_SIZE = 0;
template <typename T>
class Queue
{
    private:
        struct Node
        {
            T m_data;
            Node *m_nextNode;
            Node::Node(T data)
            {
                this->m_data= data;
                this->m_nextNode= nullptr;
            }
            Node::Node(const Node& node)
            {
                Node newNode= new Node(node->m_data);
            }
            Node& Node::operator=(const Node& node)
            {
                this->m_data= node->m_data;
                this->m_nextNode= node->m_nextNode;
            }
            Node::Node~Node()
            {
                delete *this;
            }
        };
        Node *m_head;
        Node *m_tail;
        int m_size;

    public:
        Queue::Queue<T>(): this->m_size= INITIAL_SIZE,
                           this->m_head= new Node(nullptr), 
                           this->m_tail= this->m_head 
        {

        }

        Queue::Queue<T>(const Queue<T> &q)
        {
            Queue<T> newQueue= new Queue<T>();

        }

        Queue& Queue::operator=(Queue& q)
        {
            if(*this== q)
            {
                return *this;
            }
            int* temp =Queue();
            //unfinished
        }

        ~Queue()
        {
            if(this->m_size < INITIAL_SIZE)
            {
                return;
            }
            this->m_head.~Queue();
            this->m_head.~Node();

        }

        int Queue::pushBack(T& data)
        {
            this->m_tail->m_nextNode= new Node(data);
            this->m_tail= this->m_tail->m_nextNode;
            ++this->m_size;
        }

        T& Queue::front()
        {
            return (this->m_head->m_nextNode)->m_data;
        }

        void Queue::popFront()
        {
            //שגיאה=חריגה
            /*if(this->m_size == INITIAL_SIZE)
            {
                Queue temp= this->m_tail;
                this->m_tail= this->m_head;
            }*/
            Queue temp= new Queue<T>(); 
            temp->m_tail= this->m_head->m_nextNode();
            this->m_head->m_nextNode= (this->m_head->m_nextNode)->m_nextNode;
            --this->m_size;
            temp.~Queue();
        }

        int& Queue::size()
        {
            return this->m_size;
        }

};

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