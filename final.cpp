#include <iostream>

using namespace std;

class Animal
{
private:
public:
    string st;
    Animal(string st)
    {
        this->st = st;
    }
    virtual void speak() 
    {
        cout << "Animal " << st;
    }
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

class Dog : public Animal
{
private:
    /* data */
public:
    Dog(string st) : Animal(st)
    {
        cout << st;
    }
    void speak()
    {
        cout << "Dog =" << st;
    }
};

class Cat : public Animal
{
private:
    /* data */
public:
    Cat(string st) : Animal(st)
    {
        cout << st;
    }
    void speak()
    {
        cout << "cat " << st;
    }
};

class Cow : public Animal
{
private:
    /* data */
public:
    Cow(string st) : Animal(st)
    {
        cout << st;
    }
    void speak()
    {
        cout << "cow " << st;
    }

};

class AnimalFactory {
public:
    static Animal* createAnimal(const string& type, const string& sound) {
        if (type == "dog") {
            return new Dog(sound);
        } else if (type == "cat") {
            return new Cat(sound);
        } else if (type == "cow") {
            return new Cow(sound);
        } else {
            return nullptr; // Unknown animal type

        }
    }
};

int main() {
    Animal* animal = AnimalFactory::createAnimal("dog", "woof");
    if (animal) {
        // Use dynamic_cast to access derived class methods
        if (Dog* dog = dynamic_cast<Dog*>(animal)) {
            dog->speak();
        }
        delete animal; // Don't forget to free memory
    }
    return 0;
}
