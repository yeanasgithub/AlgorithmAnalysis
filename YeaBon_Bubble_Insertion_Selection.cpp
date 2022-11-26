// Yeana Bond Lab 13
// Bubble sort organize elements in increasing order. 
// Bubble sort's time comparion when different order was given: Random > Decreasing > Increasing (increasing time != 0 )
// Insertion sort organize elements in increasing order.
// Insertions sort's time comparsion when differen order was given: Decreasing > Random > Increasing (increasing time = 0 )
// + Selection sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void fill_array_random(int array[], int size, int lbounds, int ubounds);
void fill_array_inc(int arra[], int size);
void fill_array_dec(int array[], int size);
void bubble_sort(int array[], int size);
void insertion_sort(int array[], int size);
void selection_sort(int array[], int size);
void show_array(int array[], int size);
void bubble_time(); 
void insertion_time();
void selection_time();

int main()
{
   srand(time(NULL));
    

   cout << endl;
   bubble_time();
   insertion_time();
   selection_time();

    return 0;


}


void fill_array_random(int array[], int size, int lbounds, int ubounds)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % (ubounds - lbounds)) + lbounds;
    }

}

void fill_array_inc(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = ( i + 1 );
    }

}



void fill_array_dec(int array[], int size)
{
    int val = size;
    for (int i = 0; i < size; i++)
    {
        array[i] = val;
        val--;
    }

}


void bubble_time()
{
    int arraysize;
    cout << "Enter a positive number for Bubble sort: ";
    cin >> arraysize;

    int array[arraysize];


    fill_array_random(array, arraysize, 1000, 1000000);

   // show_array(array, arraysize);

    auto start = chrono::steady_clock::now();
    bubble_sort(array, arraysize);
    auto end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Bubble sort (Random) took ";
    cout <<    chrono::duration_cast<chrono::milliseconds>(end-start).count()   << " milli-second(s)." << endl;

    cout << endl;
    cout << "After Bubble:" << endl;
   // show_array(array, arraysize);
    

    cout << endl << endl;
    cout << "(Increasing) order: "  << endl;
    fill_array_inc(array, arraysize);
  //  show_array(array, arraysize);

    
    start = chrono::steady_clock::now();
    bubble_sort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Bubble sort (Increasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;

    cout << endl;
    cout << "After Bubble:" << endl;
  //  show_array(array, arraysize);


    cout << endl << endl;
    cout << "(Decreasing) order: " << endl;

    fill_array_dec(array, arraysize);
  //  show_array(array, arraysize);
    
    start = chrono::steady_clock::now();
    bubble_sort(array, arraysize);
    
    end = chrono::steady_clock::now(); 
    cout << endl; 
    cout << "Bubble sort (Decreasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;
   
 
    cout << endl;
    cout << "After Bubble:" << endl;
 //   show_array(array, arraysize); 
    cout << "      -----End of Bubble sort!-----" << endl;
 
}

void insertion_time()
{
    int arraysize;
    cout << endl;
    cout << "Enter a positive number for Insertion sort: ";
    cin >> arraysize;

    int array[arraysize];


    cout << endl << endl; 
    cout << "(Random) order: " << endl;
    fill_array_random(array, arraysize, 1000, 1000000);

  //  show_array(array, arraysize);
    auto start = chrono::steady_clock::now();
    insertion_sort(array, arraysize);
    auto end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Insertion sort (Random) took ";
    cout <<   chrono::duration_cast<chrono::milliseconds>(end-start).count()  <<  " milli-second(s)." << endl;
    
    cout << endl;
    cout << "After Insertion sort:" << endl;
  //  show_array(array, arraysize);

    cout << endl << endl;
    cout << "(Increasing) order:" << endl;
    fill_array_inc(array, arraysize);

  //  show_array(array, arraysize);
    
    start = chrono::steady_clock::now();
    insertion_sort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Insertion sort (Increasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;

    cout << endl;
    cout << "After Insertion sort:" << endl;

 //   show_array(array, arraysize);

    cout << endl << endl;
    cout << "(Decreasing) order:" << endl;
    fill_array_dec(array, arraysize);

 //   show_array(array, arraysize);
    
    start = chrono::steady_clock::now();
    insertion_sort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Insertion sort (Decreasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;

    cout << endl; 
    cout << "After Insertion sort:" << endl;
  //  show_array(array, arraysize);
    cout <<   "      -----End of Insertion sort!-----" << endl;

  
}

void selection_time()
{
    int arraysize;
    cout << endl;
    cout << "Enter a positive number for Selection sort: ";
    cin >> arraysize;

    int array[arraysize];
    cout << endl << endl; 
    cout << "(Random) order: " << endl;
    fill_array_random(array, arraysize, 1000, 1000000);

  //  show_array(array, arraysize);
    auto start = chrono::steady_clock::now();
    selection_sort(array, arraysize);
    auto end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Selection sort (Random) took ";
    cout <<   chrono::duration_cast<chrono::milliseconds>(end-start).count()  <<  " milli-second(s)." << endl;
    
    cout << endl;
    cout << "After Selection sort:" << endl;
 //   show_array(array, arraysize);

    cout << endl << endl;
    cout << "(Increasing) order:" << endl;
    fill_array_inc(array, arraysize);

 //   show_array(array, arraysize);
    
    start = chrono::steady_clock::now();
    selection_sort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Selection sort (Increasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;

    cout << endl;
    cout << "After Selection sort:" << endl;

  //  show_array(array, arraysize);

    cout << endl << endl;
    cout << "(Decreasing) order:" << endl;
    fill_array_dec(array, arraysize);

 //   show_array(array, arraysize);
    
    start = chrono::steady_clock::now();
    selection_sort(array, arraysize);
    end = chrono::steady_clock::now();
    cout << endl; 
    cout << "Selection sort (Decreasing) took ";
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() <<  " milli-second(s)." <<endl;

    cout << endl;
    cout << "After Selection sort:" << endl;
  //  show_array(array, arraysize);
    cout << "      -----End of Selection sort!-----" << endl;



}


void swap(int *xval, int *yval)
{
    int temp = *xval;
    *xval = *yval;
    *yval = temp;
}


void selection_sort(int array[], int size)
{
    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min]) // find the min in the unsorted section
            {
                min = j;  
            }

            //swap(&array[min], &array[i]);

        }

            swap(&array[min], &array[i]);
    }

}


//         i   
//    25  37  99  45  12  27 
//                    j
void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

            }
         
                 
        }

    }

}



void insertion_sort(int array[], int size)  // array[i] and array[j] are same array
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while ( j >= 0 && array[j] > key )
        {
            array[j + 1] = array[j];
            j--; // do not forget to decrement j here!
        }
        array[j + 1] = key;  // inserting the element at the right spot 

    }

}

void show_array(int array[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout.width(7);
        cout << array[i] << " ";

        if (( i + 1 ) % 5  == 0)
        {
            cout << endl;     // new line after 5th element in the array
        }

    }
    cout << endl;

}




