#include "List.h"
#include "swatches.h"
using namespace std;

int main()
{
	List<int> mylist;
	for (int i=1; i<10; i++) {mylist.front_insert(i*i);}
	mylist.output_list();
	for (int i=1; i<10; i++) {mylist.rear_insert((i*i)-2);}
	mylist.output_list();
	for (int i=1; i<10; i++) {mylist.front_remove();}
	mylist.output_list();
	List<int> lit;
	for (int i=1; i<10; i++) {lit.front_insert(i*(i-1));}
	lit.output_list();
	lit = mylist;
	lit.output_list();
	List<int>::iterator it;
	it=mylist.begin();
	mylist.output_list();
	List<double>::iterator testit;
	List<double> testlist;
	testit=testlist.begin();
	testlist.remove(testit);
	testlist.insert_before(testit, 9.9);
	testlist.insert_before(testit, 9.8);
	testlist.insert_before(testit, 9.7);
	testlist.output_list();
	testlist.remove(testit);
	testlist.output_list();
	while (testit!=testlist.r_begin())
	{
		++testit;
	}
	testlist.remove(testit);
	testlist.output_list();
	testlist.insert_after(testit, 2.1);
	testlist.insert_after(testit, 3.4);
	testlist.remove(testit);
	testlist.output_list();
	Swatch dox;
	dox.get_color();
	cout << dox;
}