//Yeana Bond HW 01
#include <iostream>

using namespace std;

struct Window
{
    string appname;
    Window * next;
    Window * prev;

};

class WindowManager
{
    private:
        Window * head;
        Window * dummy;
        Window * current;
        Window * create()
        {
            Window * newnode;
            try
            {
                newnode = new Window;
            }
            
            catch (bad_alloc)
            {
                newnode = NULL;
            }

            return newnode;


        }

        void deallocate() // comment are not erased to remember how to trouble shoot free(): double free detected in tchache 2 Aborted error
        {
            Window * deallo = head;
           
            Window * deallo2 = NULL;
            while (deallo != dummy)
            {
                deallo2 = deallo->next;     // make copy of first deallo pointer to deallo2
              //  cout << "deallo2 is " << deallo2->appname << endl;
               // cout << "deleting " << deallo->appname << endl; 
                delete deallo;
                deallo = deallo2;
               // cout << "deallo is now " << deallo2->appname << endl;
                deallo2 = nullptr;
            }
           // cout << "deallo is now null" << endl;
            deallo = nullptr;
            

        }

    public:
        WindowManager() // establishing a default constructor
        {
            Window * newnode = create();  // Usage:
            dummy = newnode;
            dummy->prev = dummy;
            dummy->next = dummy;
            head = dummy->next;  // head is always next to dummy in this plot
            newnode->appname = ""; // setting the appname property of the dummy node 
            current = NULL; // no app is up yet
        }

        ~ WindowManager()
        {
            deallocate();
            head = NULL;
              
        }

        bool start_app(string name)
        {
            bool started = false;
            Window * newnode = create();
            if (newnode == NULL)
            {
                started = false;
            }
            else
            {
                newnode->next = dummy;
                newnode->prev = dummy->prev;
                dummy->prev->next = newnode;
                dummy->prev = newnode;
                current = newnode;
                head = dummy->next; 
                newnode->appname = name;
                started = true;
            }
            return started;

        }

        Window * find_app(string name)
        {
            Window * temp = current;
            Window * temp2 = current; // circle completer // action 3 scenario
            Window * appFinder = NULL;

            while (temp->appname != name || temp2 == NULL )
            {
               // cout << "In find While " << endl; // action 3 scenario
                temp = temp->next; // keep traversing
                temp2 = temp2->next; // temp2 is a companion of temp but when it reaches current, it made a circle. When completing one circle, it implies there was no matching name. 
                if (temp2 == current)
                
                {
                    temp2 = NULL;
                    return temp2;
                }
                
            }

            if ( temp->appname == name )
            {
                appFinder = temp;
            }
            
            else
            {
                appFinder = NULL;
                temp = nullptr; 
                temp2 = nullptr;
            }

            return appFinder;
        }

        bool close_app(string name)
        {
            bool answer = false;
           // cout << "In close app " << endl; // troubleshoot action 3 scenario
            Window * finder = find_app(name);
            if ( finder != NULL )
            {
                finder->prev->next = finder->next;
                finder->next->prev = finder->prev;
                current = finder->next; 
                
                if ( current == dummy && dummy->next != dummy ) 
                {
                    current = current->next;
                }
                answer = true;
            }

            else
            {
               // cout << "finder is null" << endl;
                finder = NULL;
                answer = false;
            }

            return answer;


        }

        string get_current()
        {
            string curr_appname = "";
            if (current != NULL)
            {
                curr_appname = current->appname;

            }
            return curr_appname;

        
        }

        string goto_next()
        {
            if (current != NULL)
            {
                current = current->next;

                if ( current == dummy )
                {
                    current = current->next;
                }

            }
            return get_current();

        }
        string goto_previous()
        {
            if (current != NULL)
            {
                current = current->prev;

                if ( current == dummy)
                {
                    current = current->prev;
                }

            }
            return get_current();

        }
};

int main()
{
    WindowManager winman;
    
    
    winman.start_app("Neflix");
    winman.start_app("PowerPoint");
    winman.start_app("Calculator");
    winman.start_app("Firefox");

    int action;
    string current_app;
    string closing_app;
    string next_app;
    string prev_app;
    string new_app;

    do
    {
        cout << "Press 1 - to launch a new app" << endl;
        cout << "Press 2 - to close the current app" << endl;
        cout << "Press 3 - to find an app and close it" << endl;
        cout << "Press 4 - to go to the next app" << endl;
        cout << "Press 5 - to go to the previous app" << endl;
        cout << "Press 0 - to quit" << endl;

        cin >> action;

        if (action == 1)
        {
            
            cout << "Enter a new app name: ";
            cin >> new_app;
            
            
            winman.start_app(new_app);
            cout << new_app << " is up." << endl;
        }

        else if ( action == 2)
        {
            current_app = winman.get_current();
            if (winman.close_app( current_app ) && current_app != "")
            {
                cout << "Closing..." << endl;
                cout << current_app << " is now closed." << endl;
                cout << "---Current app: " << winman.get_current() << endl;
            }
            else
            {
                cout << "All apps are closed!" << endl;
            }

        }

        else if ( action == 3)
        {            
            cout << "What app do you want to close? " << endl;
            cin >> closing_app;
            if (winman.close_app(closing_app))
            {
                cout << closing_app << " is now closed!" << endl;
                cout << "---Current app is now " << winman.get_current() << endl;
            }
            else
            {
                cout << closing_app << " could not be found!" << endl;
            }

        }

        else if ( action == 4)
        {
            current_app = winman.get_current();
            next_app = winman.goto_next();

            if ( current_app == next_app )
            {
                cout << "There is no app to go to." << endl; 
                cout << "All apps are closed (or) there is only one open app." << endl;
                                    
            }
            else
            {
                cout << "Current app is now " << next_app << endl;
            }
        }

        else if ( action == 5)

        {
            current_app = winman.get_current();
            prev_app = winman.goto_previous();
           
            if ( current_app == prev_app )
            {
                cout << "There is no app to go to. Launch a new one or quit." << endl; 
                cout << "All apps are closed (or) there is only one open app." << endl;
            }
            else
            {
                cout << "Current app is now " << prev_app << endl; 
            }
        }

        else if ( action != 0 || action > 6 || action < 0 ) 
        {
            cout << "Invalid option" << endl;
        }

    } while ( action > 0 && action < 6 );

   cout << "Shutting down..." << endl; 
   return 0;

    

}



