#include <bits/stdc++.h>
#include <sys/stat.h>

#include "api.h"
using namespace std;

int main(int argc, char const *argv[])
{
	char path[50];
	int opt=0;
	do{
		cout<<endl<<"1. Get file info"<<endl<<
			"2. Get files list"<<endl<<
			"0. Exit"<<endl;
		cout<<"Option: ";
		cin>>opt;
		switch(opt){
			case 1: 
			{
				cout<<"Filename: ";
				cin>>path;
				cin.ignore(80,'\n');
				struct stat attr = get_file_info(path);
				cout<<endl<<"Size: "<<attr.st_size<<endl;
				break;
			}
			case 2:
			{
				/*int sort;
				cout<<"1. Sort by name"<<endl<<
					"2. Sort by name"<<endl<<
					"3. Sort by name"<<endl;
				cout<<"Option: ";
				cin>>sort;*/
				vector<char *> list = get_sorted_list();
				for(char * file:list){
					cout<<file<<endl;
				}
				break;
			}
			case 0:
			{
				break;
			}
		}
	} while (opt);

	return 0;
}