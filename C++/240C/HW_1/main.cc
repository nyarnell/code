#include <fstream>
#include "List.h"
#include "swatches.h"

int main()
{
	List<Swatch> colors;
	Swatch temp;
	List<Swatch>::iterator blue, middle;
	char x;
	int items = 2;
	ifstream ins;
	ins.open("swatches.txt");
	ins >> temp;
	if (temp.get_red()>temp.get_blue() && temp.get_red()>temp.get_green())
			{colors.front_insert(temp); x='r';}
	else if (temp.get_green()>temp.get_blue() && temp.get_green()>temp.get_red())
			{colors.rear_insert(temp); x='g';}
	else 	{colors.insert_after(blue, temp); x='b';}
	blue=colors.begin();
	ins >> temp;
	// while (!ins.eof())
	// {
		// items++;
		// if (temp.get_red()>temp.get_blue() && temp.get_red()>temp.get_green())
		// {
			// colors.front_insert(temp);
		// }
		// else if (temp.get_green()>temp.get_blue() && temp.get_green()>temp.get_red())
		// {
			// colors.rear_insert(temp);
		// }
		// else
		// {
			// if (x=='r')
			// { colors.insert_before(blue, temp); }
			// else if (x=='g')
			// { colors.insert_after(blue, temp); }
			// else colors.insert_before(blue, temp);
		// }
		// ins >> temp;
	// }
	while (!ins.eof())
	{
		if (temp.get_red()>temp.get_blue() && temp.get_red()>temp.get_green())
		{ colors.front_insert(temp);}
		else if (temp.get_green()>temp.get_blue() && temp.get_green()>temp.get_red())
		{ colors.rear_insert(temp);}
		else
		{
			List<Swatch>::iterator it=colors.begin();
			for (int i = 0; i>items/2; ++it, ++i) {}
			colors.insert_before(it, temp);	
		}
		items++;
		ins >> temp;
	}
	ins.close();
	List<Swatch> colorcopy;
	colorcopy=colors;
	colorcopy.front_remove();
	colorcopy.rear_remove();
	middle=colorcopy.begin();
	for (int count = 0; count< (items-2)/2; count++) {++middle;}
	colorcopy.remove(middle);
	cout << endl << endl;
	for (List<Swatch>::iterator it = colors.begin(); it!=colors.end(); ++it)
	{ cout << *it << endl;}
	cout << endl << endl;
	for (List<Swatch>::iterator it = colorcopy.begin(); it!=colorcopy.end(); ++it)
	{ cout << *it << endl;}
	cout << endl << endl;
	for (List<Swatch>::iterator it = colors.r_begin(); it!=colors.r_end(); --it)
	{ cout << *it << endl;}
	cout << endl << endl;
	List<Swatch>::iterator front, back;
	front = colors.begin();
	back = colors.r_begin();
	while (items>1)
	{
		--items;
		cout << *front << " <-HEAD" << endl;
		++front;
		colors.front_remove();
		if (items>1)
		{
			--items;
			cout << *back << " <-TAIL" << endl;
			--back;
			colors.rear_remove();
		}
	}
	cout << endl << endl;
	for (List<Swatch>::iterator it = colorcopy.r_begin(); it!=colorcopy.r_end(); --it)
	{ cout << *it << endl;}
	cout << endl << endl;
}