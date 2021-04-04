#pragma once

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class my_node
{
public:
	string name;
	int age;
	my_node* nextbyage;
	my_node* nextbyname;
	
};


class PersonList
{
public:
	PersonList() :rootage(NULL), rootname(NULL) {};
	void add(string name, int age);
	bool remove(string name );
	void update(string name, int age);
	void printByAge();
	void printByName();
	void loadFile(string name);
	void saveToFileByAge(string );
	void saveToFileByName(string);
private:
	void addToNameList(my_node* iter);
	void addToAgeList(my_node* iter);
	void removenamelist(my_node* iter);
	void removeagelist(my_node*iter);
	bool compare(string&, string&) const;
	my_node* Find(string);
	my_node* rootname;
	my_node* rootage;
};

