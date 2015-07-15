#include<mysql/mysql.h>
#include<iostream>
using namespace std;

int main()
{
	MYSQL* mysql = mysql_init(NULL);
	cout<<"mysql is running"<<endl;
	return 0;
}
