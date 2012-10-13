//DISPLAY 3.10 The Increment Operator as an Expression
//Calorie-counting program.
#include <iostream>
using namespace std;

int main( )
{
    int number_of_items, count,
        calories_for_item, total_calories;

    cout << "How many items did you eat today? ";
    cin >> number_of_items;

    total_calories = 0;
    count = 1;
    cout << "Enter the number of calories in each of the\n"
         << number_of_items << " items eaten:\n";

    while (count++ <= number_of_items) 
    {
        cin >> calories_for_item;
        total_calories = total_calories
                         + calories_for_item;
    }

    cout << "Total calories eaten today = " 
         << total_calories << endl;
    return 0;
}
