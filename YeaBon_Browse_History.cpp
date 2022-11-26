//Yeana Bond
//Simulation Browse History
#include <iostream>

using namespace std;

struct Location
{
    string name;
    string address;

};

struct VisitNode
{
    Location loc;
    VisitNode * next; // pointer to the next node
 
};


class Stack 
{
    private:
       VisitNode * head; //the very top of the stack

       VisitNode * create() // function to create and return a newnode
                  
       {
           // USAGE: To create a new node, use as as follows
           // VisitNode * new VisitNode;

           VisitNode * newnode;

           try
           {
               newnode = new VisitNode;
           }

           catch (bad_alloc)
           {
               newnode = NULL;
           }

           return newnode;

       }
       
       
       void deallocate(VisitNode * node)  // this part is the task for lab 09
       {
        
          if (node != NULL)
          
          {
             // cout << endl;
             // cout << "current node " << node << endl;
             // cout << "next " << node->next << endl;
             // cout << "deleting the current node" << node << endl;
              delete node;  
              node = node->next;
             // cout << "recursive " << node << endl << endl;
              deallocate(node);

          }
          
         
          node = nullptr;
             
       
       }

       /*    
       {
           VisitNode * temp = head; // assign temp to head before deleting the top node
           while ( head != NULL ) // this loop till the end of list then deleting the nodes
           {
               
               head = head->next;
               delete temp;
               temp = head; // re-assign temp to head to delete the next node

           }

           //head = nullptr;

       }  */


       

    public:

       ~ Stack() // destructor should always be in PUBLIC
       {
           deallocate(head);
           head = nullptr;

       }

       bool push(string name, string address) 
       {
           VisitNode * newnode = create(); //create a new newnode (VisitNode) using the create() function written earlier
           
           while (newnode != NULL)
           {
               newnode->loc.name = name;
               newnode->loc.address = address;

               if (head == NULL)
               {
                   head = newnode; //since head was pointing to  MULL, head points to the first pushed item
                   newnode->next = NULL; // newnode that just got pushed points to null now, since it is the last node as well as the first
               }

               else  // head is no longer pointing null, from this point, we just have to make head point to the newely added item, and the newnode becomes the head node ( first node)
               {
                   newnode->next = head;
                   head = newnode;
               }

               return true;       
        
           }
           return false;
       }

       
       string pop(); //  

       friend void show(Stack & S); // have the prototype in the function, but have the body outside of the class due to cout


};

// removes the top node and returns name from loc
// if stack is empty, it returns empty string

string Stack :: pop()

{
    if (head == NULL) // there is no data
    {
        return "";
    }
    else  // there is data
    {
        string value = head->loc.name; //copy the value from the top node
        VisitNode * temp = head; //create a temp node to delete first node
        head = head->next; // move head to the next node in stack // head now holds the address of the next node

        delete temp; // deleting the top node
        return value;  // return value so it shows where it is clicked back from in main()
    }
};

void shownode(VisitNode * node)
{
    if (node != NULL)
    {
        
        cout << node->loc.name << endl;
        shownode(node->next);
    }
}


void show(Stack & S)  // PBR
{
            // friend fuction can access the private data of teh class member
            // traverse the entire list and print every node's loc.name in one line
            // to traverse the list, make a pointer (iterator)

            VisitNode * ptr = S.head;
            shownode(S.head);
          /*  while ( ptr != NULL ) // loop so it displays the node's value 
            {
                cout << ptr->loc.name << " ";
                ptr = ptr->next; // move the pointer so it points to the next node
            }*/

};   


// main uses the Stack class as an abstract data type (ADT)
// from the perspective of the object browser, it does not even care that a linked-list is the mechanism 
// that makes LIFO (Last in, but First out) work


int main()
{
    Stack * browser = new Stack;
    //simulate a browser history
    
    browser->push("Google", "https://google.com");
    browser->push("Amazon", "https://amazon.com");
    browser->push("LinkedIn", "https://LinkedIn.com");
    browser->push("Reddit", "https://reddit.com");

    show( * browser); // show() should show the entire history
    delete browser;
    // simulate clicking Back button

   // string top = browser.pop();
/*    cout << endl;

    if (top != "")
    {
        cout << endl << "Clicked back from " << top << endl;
    }

    show(browser);
    // simulate clicking Back button again
    top = browser.pop();
   
    cout << endl;

    if (top != "")
    {
        cout << endl << "Clicked back from " << top << endl;
    }
    
    show(browser);

    top = browser.pop();

    cout << endl;

    if (top != "")
    {
        cout << endl << "Clicked back from " << top << endl;
    }

    show(browser);

    top = browser.pop();

    cout << endl;

    if (top != "")
    {
        cout << endl << "Clicked back from " << top << endl;
    }

    show(browser); */

    return 0;

}




