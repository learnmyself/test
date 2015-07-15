#include<iostream>
#include<cmath>
using namespace std;

/*struct travel_time
{
	int hours;
	int mins;
};

const int Mins_per_hr = 60;

travel_time sum(travel_time& t1, travel_time& t2);
void show_time(travel_time t);

void countdown(int n);
*/

const int Len = 66;
const int Divs = 6;
static int count = 0;

void subdivide(char ar[], int low, int high, int level)
{
	cout<<"first..........: "<<count++ <<endl;
	if (level == 0)
		return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}

long sum(int a, int n)
{
	long total = 0;
	while(n) {
		total += pow(a, n);
		cout<< n<< ":"<<total<<endl;
		n--;	
}

	return total;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 *lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	cout<< lines << "lines will take ";
	cout<< (*pf)(lines) << "hour(s) \n";
}

int main()
{
	int code;
	cout << "How many lines of code do you need? ";
	cin >> code;
	cout << "Here's Betsy's estimate: \n";
	estimate(code, betsy);
	cout << "Here's Pam's estimate: \n";
	estimate(code, pam);


/*
	char ruler[Len];
	int i;
	for(i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';
	int max = Len -2;
	int min = 0;
	ruler[min] = ruler[max]  = '|';
	cout<< ruler << "\n";
	for(i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		cout<< ruler << "\n";
		for(int j = 1; j < Len -2; j++)
			ruler[j] = ' ';
	}
	

	subdivide(ruler, min, max, Divs);
	cout<<"total count: "<<sum(2, 6)<<endl;


	travel_time day1 = {5, 45};
	travel_time day2 = {4, 55};

	travel_time trip = sum(day1, day2);
	cout<< "Two-day total: ";
	show_time(trip);
	
	travel_time day3 = {4, 32};
	cout<< "Threeday total: ";
	show_time(sum(trip, day3));

	countdown(5);
*/
	return 0;
}

/*travel_time sum(travel_time& t1, travel_time& t2)
{
	travel_time total;
	total.mins = (t1.mins + t2.mins)%Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins)/ Mins_per_hr;
	return total;
}

void show_time(travel_time t)
{
	cout<<t.hours << "hours, " << t.mins << "minutes\n";
}

void countdown(int n)
{
	cout<< "Counting down ... "<<n <<endl;
	if(n >0)
		countdown(--n);
	cout<< n << ":Kaboom! \n";
}
*/
