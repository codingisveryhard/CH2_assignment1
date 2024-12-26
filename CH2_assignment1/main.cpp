#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "Animal 생성자 호출" << endl;
	}
	virtual void makeSound() = 0;
	virtual ~Animal() {
		cout << "Animal 소멸자 호출" << endl;
	}
};

class Zoo : public Animal
{
public:
	Zoo() {
		cout << "Zoo 생성자 호출" << endl;
	}
	void addAnimal(Animal* animal) {

	}

	virtual void makeSound() override {
		cout << "동물원에서 동물들이 울어요!" << endl;
	}
	virtual ~Zoo() {
		delete[] animal;
		cout << "Zoo 소멸자 호출" << endl;
	}
private:
	Animal* animal[10];
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "Dog 생성자 호출" << endl;
	}
	virtual void makeSound() override {
		cout << "댕! 댕! " << endl;
	}
	~Dog() {
		cout << "Dog 소멸자 호출" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() {
		cout << "Cat 생성자 호출" << endl;
	}
	virtual void makeSound() override {
		cout << "떼껄룩!" << endl;
	}
	~Cat() {
		cout << "Cat 소멸자 호출" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow() {
		cout << "Cow 생성자 호출" << endl;
	}
	virtual void makeSound() override {
		cout << "음메~!" << endl;
	}
	~Cow() {
		cout << "Cow 소멸자 호출" << endl;
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
