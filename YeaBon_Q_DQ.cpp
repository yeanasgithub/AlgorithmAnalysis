// Queues using arrays
// Yeana Bond
#include <iostream>

using namespace std;


class RingBuffer
{
    private:

        int size;
        string * names;
        int front;
        int back;

        bool is_empty()    // return front == back
        {
            if (front == back) 
            {
                return true;
            }

            else
                return false;

        }

        bool is_full() // return ( (back+1)%size == front )
        {
            if ((back + 1) % size == front)
            {
               return true;
            }
            else
               return false; 

        }

        


    public:
        RingBuffer(int arr_size)  // arr_size is defined in main()
        {
            size = arr_size;  // save the arr_size in the variable size
            names = new string[size];  // initialize names as a dynamic array if string size
            front = 0;
            back = 0;

            for (int i = 0; i < size ; i++)
            {
                names[i] = "";  //fill all element of the array with blank string
            
            }
            
        }

        ~ RingBuffer() // de - Structor of the constructor RingBuffer() above
        {
            delete []names; // deleting names string

        }

        bool enqueue(string name)
        {
            if ( !is_full())
            {
                names[back] = name;  // back index points to the next location to enqueue
                back = (back + 1) % size; // back index has to increment to point the next location to enqueue
                return true; // enqueue successful
            }
            return false;
        }

        string dequeue()
        {
            string deQ;  
            if (is_empty())  // if array is empty, it returns an blank string
            {
                deQ = "";
            }

            else
            {
                deQ = names[front];  // front index points to next location to dequeue
                front = ( front + 1 ) % size; // front index has to increment to point the next locationi to dequeue
             

            }
            return deQ; // exract the name of the element at the position front 
                        // return the name to main()

        }

        friend void show(RingBuffer & rb);


        
};

void show(RingBuffer & rb)
{
    int counter = rb.front;
    while ( counter != rb.back)
    {
        cout << rb.names[counter] << " ";
        counter = (counter + 1) % rb.size; 
    }

    //show the contents of actual queue contents
    //use while loop that starts from front and loops to back
    //use counter initialized at front and advancing as long as it is not equal to back
    //immediately after the while loop, you will have to show names[i] at the current value of i 
    //to account for the last item


}

int main()
{
    RingBuffer buffer(15);  // array size is 15, but by the 14th element, it will say the queue is full.
    char action;
    string name = "";
    bool added;

    do
    {
        cout << "e - Enqueue" << endl;
        cout << "d - Dequeue" << endl;
        cout << "q - Quit" << endl;
        cout << "\nAction: ";
        cin >> action;

        if (action == 'e')
        {
            cout << "Name: ";
            cin >> name;
            if (buffer.enqueue(name))
            {
                cout << "Added " << name << endl;
            }
            else
            {
                cout << name << " was not added. Queue is full" << endl;
            }

        }

        else if (action == 'd')
        {
            name = buffer.dequeue();
            if (name == "")
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Dequeued " << name << endl;
            }
        }

        show(buffer);

        cout << "\n-------Above shows current element(s) inside of array-------" << endl << endl;

    } while (action != 'q');

    cout << "Good bye!" << endl;


 
    return 0;
}










