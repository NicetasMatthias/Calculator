#ifndef QUEUE_H
#define QUEUE_H


#include "node.h"



template <class N>
class Queue
{

private:
    Node<N> *head;
    Node<N> *tail;





public:
    Queue()
    {
        this->head = new Node<N>;
        this->tail = this->head;
    }
    ~Queue()
    {
        while(1)
        {
            bool empty;
            N *tmp = this->pop(&empty);
            if (empty)
            {
                break;
            }
            else
            {
                delete tmp;
            }
        }
        delete this->head;
    }
    N* pop(bool* empty)
    {
        if (this->head==this->tail)
        {
            *empty = true;
            return nullptr;
        }
        else
        {
            *empty = false;
            Node<N> *tmp_node = this->head;
            this->head = tmp_node->get_previous();
            this->head->set_next(nullptr);
            delete tmp_node;
            N *tmp_n = this->head->get_data();
            this->head->set_data(nullptr);
            return tmp_n;
        }
    }
    void push(N* new_item)
    {
        Node <N> *new_node = new Node <N>(new_item);
        this->tail->set_previous(new_node);
        new_node->set_next(this->tail);
        this->tail = new_node;
    }
    int size()
    {
        int count = 0;
        Node <N> *tmp = this->tail;
        while(tmp!=this->head)
        {
            count++;
            tmp = tmp->get_next();
        }
        return count;
    }

};
#endif // QUEUE_H
