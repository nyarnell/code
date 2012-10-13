//DISPLAY 5.3 Use of return in a void  Function
//Function Declaration
void ice_cream_division(int number, double total_weight);
//Outputs instructions for dividing total_weight ounces of 
//ice cream among number customers. 
//If number is 0, nothing is done.
//Function Definition
//Definition uses iostream:
void ice_cream_division(int number, double total_weight)
{
    using namespace std;
    double portion;

    if (number == 0)
        return;
    portion = total_weight/number;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Each one receives " 
         << portion << " ounces of ice cream." << endl;
}
