#include "personal_list.h"


void PersonList::add(string name, int age) {
	if ( rootname == NULL){
		my_node* itername = new my_node();
		itername->name = name;
		itername->age = age;
		rootage = itername;
		rootname = itername;
	}
	else{
		my_node* itername = new my_node();
		itername->name = name;
		itername->age = age;
		addToAgeList(itername);
		addToNameList(itername);

	}
	
}
bool PersonList::remove(string name) {
	my_node* iter = Find(name);
	if (iter != NULL)
	{
		removeagelist(iter);
		removenamelist(iter);
		delete iter;
		return true;
	}
	else
	{
		return false;
	}

}
void PersonList::update(string name, int age) {
	my_node* iter = Find(name);
	if (iter == NULL)
	{
		cout << name << " does not exist" << endl;
		return;
	}

	removeagelist(iter);
	iter->age = age;
	
	if (rootage == NULL){
		rootage = iter;
		return;
	}
	
	addToAgeList(iter);
}
void PersonList::printByAge() {

	
	

	for (my_node* iter = rootage; iter != nullptr; iter = iter->nextbyage)
	{
		cout << iter->name << "\t\t" << iter->age << endl;
	}
	cout << "end of list by age" << endl;
}
void PersonList::printByName() {
	

	for (my_node* iter = rootname; iter != nullptr; iter = iter->nextbyname)
	{
		cout << iter->name << "\t\t" << iter->age << endl;
	}
	cout << "end of list by name" << endl;
}
void PersonList::loadFile(string filename) {

	fstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		string string1;
		while (getline(file, string1)) {

			string name;
			int age;
			istringstream stream(string1);
			stream >> name;
			stream >> age;
			add(name, age);

		}
		file.close();
	}

}
void PersonList::saveToFileByAge(string nameoffile) {


	ofstream myfile(nameoffile);

	if (myfile.is_open())
	{
		for (my_node* temp = rootage; temp != NULL; temp = temp->nextbyage){
			myfile << temp->name << "  " << temp->age << endl;
		}
		
		myfile.close();
	}

}
void PersonList::saveToFileByName(string nameoffile) {

	ofstream myfile(nameoffile );

	if (myfile.is_open())
	{
		for (my_node* temp = rootname; temp != NULL; temp = temp->nextbyname)
		{
			myfile << temp->name << " " << temp->age << endl;
		}
		myfile.close();
	}
}
void PersonList::addToAgeList(my_node* temp) {
	if (rootage->age >= temp->age){
		temp->nextbyage = rootage;
		rootage = temp;
		return;
	}


	my_node* iter;
	for (iter = rootage; iter->nextbyage != NULL && iter->nextbyage->age <= temp->age; iter = iter->nextbyage);
	temp->nextbyage = iter->nextbyage;
	iter->nextbyage = temp;
}
void PersonList::addToNameList(my_node* temp) {
	if (compare(temp->name, rootname->name))
	{
		temp->nextbyname = rootname;
		rootname = temp;

	}
	else {
		my_node* iter = rootname;
		for (; iter->nextbyname != nullptr && compare(iter->nextbyname->name, temp->name); iter = iter->nextbyname);

		temp->nextbyname = iter->nextbyname;
		iter->nextbyname = temp;
	}


}
void PersonList::removeagelist(my_node* node) {

	if (rootage == node) {
		rootage = rootage->nextbyage;
	}
	for (my_node* iter = rootage; iter != NULL; iter = iter->nextbyage) {
		if (iter->nextbyage == node) {
			iter->nextbyage = iter->nextbyage->nextbyage;
		}
	}
}
void PersonList::removenamelist(my_node* node) {
	if (rootname == node) {
		rootname = rootname->nextbyname;
	}
	for (my_node* iter = rootname; iter != NULL; iter = iter->nextbyname) {
		if (iter->nextbyname == node) {
			iter->nextbyname = iter->nextbyname->nextbyname;
		}
	}

}
bool PersonList::compare(string& person_1, string& person_2) const {
	int length;
	if (person_1.size() > person_2.size()) {
		length = person_2.size();
	}
	else {
		length = person_1.size();
	}
	for (int i = 0; i < length; i++)
	{
		if (person_1[i] < person_2[i]) {
			return true;
		}
		else if (person_1[i] > person_2[i])
		{
			return false;
		}
	}
	return false;

}
my_node* PersonList::Find(string name) {
	for (my_node* iter = rootname; iter != nullptr; iter = iter->nextbyname)
		if (iter->name == name)
			return iter;
	return NULL;

}

