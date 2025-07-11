#include <iostream>
#include <cstring>

using namespace std;

struct MyType {
	char * name;
	char * favorite_color;
	char * hair_color;
	char * eye_color;
	char * favorite_band;

	void copy(const MyType& other);
	void clear();

	MyType();
	~MyType();
	MyType(const MyType& other);
};

struct MyNodeType {
	MyType data;
	MyNodeType * next;

	void copy_data(const MyType & _data);
	
	MyNodeType(const MyType & _data);
};

int main()
{
	MyType temp_obj;
	temp_obj.name = new char[6];
	strcpy(temp_obj.name, "Suzie");
	temp_obj.favorite_color = new char[6];
	strcpy(temp_obj.favorite_color, "brown");
	temp_obj.hair_color = new char[7];
	strcpy(temp_obj.hair_color, "blonde");
	temp_obj.eye_color = new char[10];
	strcpy(temp_obj.eye_color, "eye color");
	temp_obj.favorite_band = new char[6];
	strcpy(temp_obj.favorite_band, "AC/DC");

	MyNodeType * head = new MyNodeType(temp_obj);
	MyType copy = temp_obj; //same as copy(temp_obj);
	MyType copy_no2 = copy;

	delete head;
}

MyNodeType::MyNodeType(const MyType & _data)
{
	data.copy(_data);
	next = nullptr;
}

MyType::MyType()
{
	name = nullptr;
	favorite_color = nullptr;
	hair_color = nullptr;
	eye_color = nullptr;
	favorite_band = nullptr;
}

void MyType::clear()
{
	delete [] name;
	name = nullptr;

	delete [] favorite_color;
	favorite_color = nullptr;
	
	delete [] hair_color;
	hair_color = nullptr;
	
	delete [] eye_color;
	eye_color = nullptr;
	
	delete [] favorite_band;
	favorite_band = nullptr;
}

MyType::~MyType()
{
	clear();
}

void MyType::copy(const MyType& other)
{
	clear();

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	favorite_color = new char[strlen(other.favorite_color) + 1];
	strcpy(favorite_color, other.favorite_color);
	
	hair_color = new char[strlen(other.hair_color) + 1];
	strcpy(hair_color, other.hair_color);
	
	eye_color = new char[strlen(other.eye_color) + 1];
	strcpy(eye_color, other.eye_color);
	
	favorite_band = new char[strlen(other.favorite_band) + 1];
	strcpy(favorite_band, other.favorite_band);
}

MyType::MyType(const MyType& other)
{
	name = nullptr;
	favorite_color = nullptr;
	hair_color = nullptr;
	eye_color = nullptr;
	favorite_band = nullptr;

	copy(other);
}
