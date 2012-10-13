//DISPLAY 17.4 Interface for the Class Template GenericList
//This is the header file genericlist.h. This is the interface for the 
//class GenericList. Objects of type GenericList can be a list of items 
//of any type for which the operators << and = are defined.  
//All the items on any one list must be of the same type. A list that
//can hold up to max items all of type Type_Name is declared as follows:
//     GenericList<Type_Name> the_object(max);
#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
using namespace std;

namespace listsavitch
{
    template<class ItemType>
    class GenericList
    {
    public:
        GenericList(int max);
        //Initializes the object to an empty list that can hold up to
        //max items of type ItemType.
         ~GenericList( );
        //Returns all the dynamic memory used by the object to the freestore.

        int length( ) const;
        //Returns the number of items on the list.

        void add(ItemType new_item);
        //Precondition: The list is not full.
        //Postcondition: The new_item has been added to the list.

        bool full( ) const;
        //Returns true if the list is full.


void erase( );
        //Removes all items from the list so that the list is empty.

        friend ostream& operator <<(ostream& outs, 
                                           const GenericList<ItemType>& the_list);
        //Overloads the << operator so it can be used to output the
        //contents of the list. The items are output one per line.
        //Precondition: If outs is a file output stream, then outs has 
        //already been connected to a file.
    private:
        ItemType *item; //pointer to the dynamic array that holds the list.
        int max_length; //max number of items allowed on the list.
        int current_length; //number of items currently on the list.
    };
}//listsavitch
#endif //GENERICLIST_H


