class Node<T>
{
    public T data;
    public Node<T> next;

    public Node(T data, Node<T> p)
    {
        this.data = data;
        this.next = p;
    }
}

class LinkedList<T>
{

    protected Node<T> head = null;
    private int size = 0;

    public void add_start(T data)
    {
        Node<T> ptr = new Node<>(data,head);
        head = ptr;
        size++;
    }

    public void add_end(T data)
    {
        /*
        Creating a temp node and then traversing to the end node and adding the new node
        */
        if (head!=null)
        {
            Node<T> temp = head;
            while(temp.next!=null)
                temp = temp.next;
            temp.next = new Node<>(data,null);
            size++;
        }
        else
            // If there is no element then add at start
            add_start(data);
    }

    public void add(int index, T data)
    {
        if (index >size || index < 0)
        {
            System.out.println("Index out of range");
            System.exit(0);
        }
        // Traversing to the index and adding a new node and poiting the new node to the next elemnt
        if (index == 0 )
        {
            add_start(data);
            return;
        }
        Node <T>temp = head;
        for (int i=0;i<size;i++)
        {
            if (i == index-1)
            {
                temp.next = new Node<>(data,temp.next);
                break;
            }
            temp = temp.next;
        }
        size++;
    }

    public void remove(int index)
    {
        if (index >size-1 || index < 0)
        {
            System.out.println("Index out of range");
            System.exit(0);
        }
        // Traversing to the index before the entered index and poiting it to the next element skipping the current index
        Node<T> temp = head;
        if (index == 0)
            head = head.next;
        else
        {
            for (int i=0; i<size-1; i++)
            {
                if (i == index-1)
                {
                    temp.next = temp.next.next;
                    break;
                }
                temp = temp.next;
            }  
        }

        size--;
    }

    public int length()
    {
        return size;
    }

    public void display()
    {
        if (head!=null)
        {
            Node<T> temp = head;
            while(temp.next!=null)
            {
                System.out.print(temp.data + " -> ");
                temp = temp.next;
            }
            System.out.println(temp.data + " -> *");
        }
        
    }

    public T getdata(int index)
    {
        if (index >size-1 || index < 0)
        {
            System.out.println("Index out of range");
            System.exit(0);
        }

        Node<T> temp = head;

        for (int i=0; i<size;i++)
        {
            if (i == index)
                return temp.data;
            temp = temp.next;
        }

        T t=null;
        return t;
    }
}


class Iterator<T>
{

    private Node<T> node;
    private Node<T> head;
    private int size;
    private int current = 0;
    Iterator(LinkedList<T> n)
    {
        node = n.head;
        head = n.head;
        size = n.length();
    }

    boolean has_next()
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
        T temp = node.data;
        node = node.next;
        current++;
        return temp;
    }
}

class LinkedListTest
{
    public static void main(String[] args)
    {
        LinkedList<Double> l = new LinkedList<>();
        l.display();
        l.add_end(0.1);
        l.add_start(10.1);
        l.add_end(80.1);
        l.add_start(20.1);
        l.add_start(30.1);
        l.add_start(40.1);
        l.add_end(50.1);
        l.add_start(130.1);
        l.display();
        l.add(5,100.1);
        l.display();
        l.remove(3);
        l.display();
        l.remove(7);
        l.display();
        System.out.println(l.getdata(1));
        Iterator <Double> Iter = new Iterator<>(l);

        while(Iter.has_next())
        {
            System.out.println(Iter.data());
        }
    }
}