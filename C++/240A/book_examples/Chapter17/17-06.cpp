//DISPLAY 17.6 Implementation of GenericList
//This is the implementation file: genericlist.cpp 
//This is the implementation of the class template named GenericList. 
//The interface for the class template GenericList is in the 
//header file genericlist.h.
#ifndef GENERICLIST_CPP
#define GENERICLIST_CPP
#include <iostream>
#include <cstdlib>
#include "genericlist.h"//This is not needed when used as we are using this file,
                 //but the #ifndef in genericlist.h makes it safe.
using namespace std;

namespace listsavitch
{
    //Uses cstdlib:
    template<class ItemType>
    GenericList<ItemType>::GenericList(int max) : max_length(max), 
                                                  current_length(0)

    {
          item = new ItemType[max];
    }

    template<class ItemType>
    GenericList<ItemType>::~GenericList( )


{
        delete [] item;
    }

    template<class ItemType>
    int GenericList<ItemType>::length( ) const
    {
        return (current_length);
    }

    //Uses iostream and cstdlib:
    template<class ItemType>
    void GenericList<ItemType>::add(ItemType new_item)
    {
        if ( full( ) )
        {
            cout << "Error: adding to a full list.\n";
            exit(1);
        }
        else
        {
            item[current_length] = new_item;
            current_length = current_length + 1;
        }
    }

    template<class ItemType>
    bool GenericList<ItemType>::full( ) const
    {
        return (current_length == max_length);
    }

    template<class ItemType>
    void GenericList<ItemType>::erase( )
    {
        current_length = 0;
    }

    //Uses iostream:
    template<class ItemType>
    ostream& operator <<(ostream& outs, const GenericList<ItemType>& the_list)


{
        for (int i = 0; i < the_list.current_length; i++)
            outs << the_list.item[i] << endl;

        return outs;
    }
}//listsavitch
#endif // GENERICLIST_CPP Notice that we have enclosed all the template 
       // definitions in #ifndef... #endif.