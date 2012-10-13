//DISPLAY 14.2 Iterative Version of the Function in Display 14.1
//Uses iostream:
void write_vertical(int n)
{
    int tens_in_n = 1;
    int left_end_piece = n;
    while (left_end_piece > 9)
    {
        left_end_piece = left_end_piece/10;
        tens_in_n = tens_in_n*10;
    }
    //tens_in_n is a power of ten that has the same number 
    //of digits as n. For example, if n is 2345, then 
    //tens_in_n is 1000.
 
    for (int power_of_10 = tens_in_n;
           power_of_10 > 0; power_of_10 = power_of_10/10)
    {
        cout << (n/power_of_10) << endl;
        n = n%power_of_10;
    }
}


