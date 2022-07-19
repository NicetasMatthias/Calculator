#ifndef NODE_H
#define NODE_H

/*

*/
template <class T>

class Node {

private:
    T *data;
    Node *next;
    Node *previous;
public:
    Node()
    {
        this->data = nullptr;
        this->next = nullptr;
        this->previous = nullptr;
    }
    Node(T* setup_data)
    {
        this->data = setup_data;
        this->next = nullptr;
        this->previous = nullptr;
    }
    ~Node()
    {
        if(this->data!=nullptr)
            delete this->data;
    }

    void set_data(T* input_data)
    {
        this->data = input_data;
    }
    void set_next(Node* input_node)
    {
        this->next = input_node;
    }
    void set_previous(Node* input_node)
    {
        this->previous = input_node;
    }

    T* get_data()
    {
        return this->data;
    }
    Node* get_next()
    {
        return this->next;
    }
    Node* get_previous()
    {
        return this->previous;
    }



};


#endif // NODE_H
