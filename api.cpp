#include <bits/stdc++.h>
#include <sys/stat.h>

using namespace std;

struct file_info{
	struct file_info * next;
	struct stat info;
	char path[50];
};

struct file_info * head = NULL;

void test(){
	cout<<"test"<<endl;
}

void store(struct stat attr, char * path){
	if(head==NULL){
		head = new file_info;
		head->next = NULL;
		head->info = attr;
		strcpy(head->path, path);
	} 
	else {
		struct file_info * curr = new file_info;
		curr->next = NULL;
		curr->info = attr;
		strcpy(curr->path, path);
		struct file_info * itr;
		itr = head;
		while(itr->next){
			itr = itr->next;
		}
		itr->next = curr;
	}
}

void print_list(){
	struct file_info * itr;
	itr = head;
	while(itr){
		cout<<itr->path<<"\t"<<itr->info.st_size<<endl;
		itr = itr->next;
	}
}

void get_mime_type(char * path){
	char cmd[50];
	sprintf(cmd, "file -i %s", path);
	system(cmd);
}

vector<char *> get_sorted_list(){
	vector<char *> list;
	vector<struct file_info * > fi;
	struct file_info * itr;
	itr = head;
	while(itr){
		fi.push_back(itr);
		itr = itr->next;
	}
	for(struct file_info * f:fi){
		list.push_back(f->path);
	}
	return list;
}

struct stat get_file_info(char * path){
	struct stat attr;
	if(stat(path, &attr) < 0){
		cout<<"Error: "<<strerror(errno)<<endl;
	} else {
		get_mime_type(path);
		store(attr, path);
	}
	return attr;
}