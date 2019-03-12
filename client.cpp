#include <bits/stdc++.h>
#include <sys/stat.h>

#include "api.h"
using namespace std;

int main(int argc, char const *argv[])
{
	char path[50];
	while(1){
		cout<<"Filename: ";
	cin>>path;
	cin.ignore(80,'\n');
	cout<<get_file_info(path).st_size<<endl;
	}
	cout<<"Filename: ";
	cin>>path;
	cin.ignore(80,'\n');
	cout<<get_file_info(path).st_size<<endl;
	return 0;
}