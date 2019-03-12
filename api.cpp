#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

void test(){
	cout<<"test"<<endl;
}

struct stat get_file_info(char * path){
	struct stat attr;
	if(stat(path, &attr) < 0){
		cout<<"Error: "<<strerror(errno)<<endl;
	}
	return attr;
}