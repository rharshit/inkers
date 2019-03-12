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
				int sort;
				cout<<"1. Sort by size"<<endl<<
					"2. Sort by name"<<endl<<
					"3. Sort by access date"<<endl;
				cout<<"Option: ";
				cin>>sort;
				if(sort>=1 && sort<=3){
					vector<char *> list = get_sorted_list(sort);
					for(char * file:list){
						cout<<file<<endl;
					}
				} else {
					cout<<"Invalid option"<<endl;
				}
				break;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout<<"Invalid option"<<endl;
				break;
			}
		}
	} while (opt);

	return 0;
}