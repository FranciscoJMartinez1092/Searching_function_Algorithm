#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;



void search(const int a[], size_t first, size_t last, int target, bool& found, size_t& location)
// Precondition: The array segment starting at a[first] and containing size elements is sorted
// from smallest to largest. 
// Precondition: First is less than or equal to last
// Postcondition: The array segment starting at a[first]  has been 
// searched for the target up to the last element. If the target was present, then found is true, and location is set so 
// that target == a[location]. Otherwise, found is set to false. 
// Library facilities used: cstdlib (provides size_t from namespace std) 
{ size_t middle;

	
	if(!(first <= last))
		found = false;
	else 
	{
		middle = (first + last) / 2;
		if (target == a[middle])
		{ 
			location = middle; 
			found = true; 
		}
		else if (target < a[middle]) 
			// The target is less than a[middle], so search before the middle. 
			search(a, first, middle - 1, target, found, location);
		else 
			// The target must be greater than a[middle], so search after the middle. 
			search(a, middle+1, last, target, found, location); 
	}
}

int main()
{
	bool found;
	size_t location;
	int a[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	search(a, 0, 6, 5, found, location);
	if (found)
	{
		cout << "True" << endl;
		cout << location;
	}
	else
		cout << "False";
	return 0;
}

