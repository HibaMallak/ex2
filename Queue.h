#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

static const int INITIAL_SIZE = 0;
template <typename T>
class Queue
{
    private:
        struct Node
        {
             int m_data;
             Node *m_nextNode;
             Node(int data);
             Node(const int &data);
             Node(const Node &);
             ~Node();
        };
        Node *m_head;
        Node *m_tail;
        int m_size;

    public:
        Queue<int>()
        {
            this->m_size= INITIAL_SIZE;
            this->m_head= new Node;
            this->m_tail= this->m_head;
        }

        Queue<int>(const Queue<int> &q)
        {
            //unfinished
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
            //unfinished
        }

        int Queue::pushBack(T& data)
        {
            this->m_tail->m_nextNode= new Node();
            this->m_tail= this->m_tail->m_nextNode;
            this->m_tail= new T(data);
            ++this->m_size;
        }
        int Queue::front()
        {
            return (this->m_head->m_nextNode)->m_data;
        }

        void Queue::popFront()
        {
            if(this->m_tail== nullptr)
            {
                return;
            }
            --this->m_size;
            if(this->m_size==INITIAL_SIZE)
            {
                Node temp= this->m_tail;
                this->m_tail= this->m_head;
            }
            else
            {
                Node temp= this->m_head->m_nextNode;
                this->m_head->m_nextNode= (this->m_head->m_nextNode)->m_nextNode;
            }
            temp.~Node();
        }

        int Queue::size()
        {
            return this->m_size;
        }








    
        


};






#endif