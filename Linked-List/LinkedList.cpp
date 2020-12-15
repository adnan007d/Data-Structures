#include<iostream>
using namespace std;

template <class T>
class Node;

template <class T>
class LinkedList;

template<class T>
class Iterator
{
    private:
    Node<T>* node;
    Node<T>* head;
    int size;
    int current = 0;

    public:
    Iterator(LinkedList<T>);

    bool has_next()
    {
        if (current<size)
        {
            return true;
        }
        else
        {
            current = 0;
            node = head;
            return false;
        }
    }

    T data()
    {
        T temp = node->data;
        node = node->next;
        current++;
        return temp;
    }
};


template<class T>
class Node
{
    public:
    T data;
    Node* next = NULL;

    Node(T d, Node* n)
    {
        data = d;
        next = n;
    }
};
template <class T>
class LinkedList
{
    private:
    Node<T>* head = NULL;
    int size = 0;

    public:

    void add_start(T data)
    {
        Node<T>* ptr = new Node <T>(data,head);
        head = ptr;
        size++;
    }

    void add_end(T data)
    {
        if (head)
        {
            Node<T>* temp = head;
            while(temp->next)
                temp = temp->next;
            temp->next = new Node<T>(data,NULL);
            size++;
        }
        else
        {
            add_start(data);
        }
        
    }

    void remove(int index)
    {
        if (index >size-1  || index < 0)
        {
            cout << "Index out of range" << endl;
            exit(0);
        }

        // Traversing to the index before the entered index and poiting it to the next element skipping the current index
        Node<T>* temp = head;
        if (index == 0)
            head = head->next;
        else
        {
            for (int i=0; i<size-1; i++)
            {
                if (i == index-1)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
        }

        size--;
    }
    
    void add(int index, T data)
    {
        if (index >size || index < 0)
        {
            cout << "Index out of range" << endl;
            exit(0);
        }

        // Traversing to the index and adding a new node and poiting the new node to the next elemnt
        if (index == 0 )
        {
            add_start(data);
            return;
        }
        Node<T>* temp = head;
        for (int i=0;i<size;i++)
        {
            if (i == index-1)
            {
                temp->next = new Node<T>(data,temp->next);
                break;
            }
            temp = temp->next;
        }
        size++; 
    }
    
    int length()
    {
        return size;
    }

    T getdata(int index)
    {
    {
        if (index >size-1 || index < 0)
        {
            cout << "Index out of range" << endl;
            exit(0);
        }

        Node<T>* temp = head;
        for (int i=0;i<size;i++)
        {
            if (i == index)
                return temp->data;
            temp = temp->next;
        }

        return 0;
    }      
    }

    friend Iterator<T> :: Iterator(LinkedList<T>);

    void display()
    {
        if (head)
        {
            Node<T>* temp = head;
            while(temp->next)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data << " -> *" << endl;
        }

    }
};

template<class T>
Iterator <T> :: Iterator(LinkedList<T> n)
{
    node = n.head;
    head = n.head;
    size = n.length();
}

int main()
{
    LinkedList <float> l;
    l.display();
    l.add_end(0.0);
    l.add_start(10.5);
    l.add_end(85.5);
    l.add_start(25.5);
    l.add_start(35.5);
    l.add_start(45.5);
    l.add_end(55.5);
    l.add_start(135.5);
    l.display();
    l.add(5,155.5);
    l.display();
    l.remove(3);
    l.display();
    l.remove(7);
    l.display();
    cout << l.getdata(1) << endl;
    Iterator<float> Iter(l);

    while(Iter.has_next())
    {
        cout << Iter.data()<< endl;
    }

}