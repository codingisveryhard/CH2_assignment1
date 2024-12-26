#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "Animal ������ ȣ��" << endl;
	}
	virtual void makeSound() = 0;
	virtual ~Animal() {
		cout << "Animal �Ҹ��� ȣ��" << endl;
	}
};

class Zoo : public Animal
{
public:
	Zoo() {
		cout << "Zoo ������ ȣ��" << endl;
	}
	void addAnimal(Animal* animal) {

	}

	virtual void makeSound() override {
		cout << "���������� �������� ����!" << endl;
	}
	virtual ~Zoo() {
		delete[] animal;
		cout << "Zoo �Ҹ��� ȣ��" << endl;
	}
private:
	Animal* animal[10];
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "Dog ������ ȣ��" << endl;
	}
	virtual void makeSound() override {
		cout << "��! ��! " << endl;
	}
	~Dog() {
		cout << "Dog �Ҹ��� ȣ��" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() {
		cout << "Cat ������ ȣ��" << endl;
	}
	virtual void makeSound() override {
		cout << "������!" << endl;
	}
	~Cat() {
		cout << "Cat �Ҹ��� ȣ��" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow() {
		cout << "Cow ������ ȣ��" << endl;
	}
	virtual void makeSound() override {
		cout << "����~!" << endl;
	}
	~Cow() {
		cout << "Cow �Ҹ��� ȣ��" << endl;
	}
};

int main()
{
	Animal* animal[3];
	animal[0] = new Dog();
	animal[1] = new Cat();
	animal[2] = new Cow();
	for (int i = 0; i < 3; i++)
	{
		animal[i]->makeSound();
	}
	for (int i = 0; i < 3; i++)
	{
		delete animal[i];
	}

	return 0;
}
