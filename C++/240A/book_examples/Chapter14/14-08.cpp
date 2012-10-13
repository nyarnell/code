//DISPLAY 14.8 Iterative Version of Binary Search
//Function Declaration
void search(const int a[], int low_end, int high_end,
                           int key, bool& found, int& location);
//Precondition: a[low_end] through a[high_end] are sorted in increasing 
//order.
//Postcondition: If key is not one of the values a[low_end] through 
//a[high_end], then found == false; otherwise, a[location] == key and 
//found == true.
//Function Definition
void search(const int a[], int low_end, int high_end,
                           int key, bool& found, int& location)
{
    int first = low_end;
    int last = high_end;
    int mid;

    found = false;//so far
    while ( (first <= last) && !(found) )
    {
        mid = (first + last)/2;
        if (key == a[mid])
        {
            found = true;
            location = mid;
        }
        else if (key < a[mid])
        {
            last = mid - 1;
        }
        else if (key > a[mid])
        {
            first = mid + 1;
        }
    }
}

