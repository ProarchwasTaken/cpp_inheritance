#include <iostream>
#include <string>

using std::string;

class Person {
  /* The base class that all other classes will derive from. For holding
   * basic information about a person. Also has a method that will print
   * that information out into the console.
   *
   * The introduction method can be overridden by other classes that
   * derive this base class. The "virtual" keyword is used to tell the
   * compiler that the method is meant to be overidden I think.*/
protected:
  string first_name, last_name;
  int age;
  
public:
  Person(string first_name, string last_name, int age) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->age = age;
  }

  virtual void introduction();
};

void Person::introduction() {
  std::cout << "Name: " << first_name << " " << last_name << "\n" 
  << "Age: " << age << "\n";
}


class Programmer: public Person {
  int known_languages;
  string best_project;

public:
  Programmer(string first_name, string last_name, int age, int known_languages, string best_project):
    Person(first_name, last_name, age) {
    this->known_languages = known_languages;
    this->best_project = best_project;
  }
    
  void introduction();
};

void Programmer::introduction() {
  Person::introduction();

  std::cout << "Occupation: Programmer" << "\n" << 
    "Known Programming Languages: " << known_languages << "\n" << 
    "Best Programming project: " << best_project << "\n";
}


class PkmnTrainer: public Person {
  int pokemon_caught;

public:
  PkmnTrainer(string first_name, string last_name, int age, int pokemon_caught): 
    Person(first_name, last_name, age) {
    this->pokemon_caught = pokemon_caught;
  }
  void introduction();
};


void PkmnTrainer::introduction() {
  Person::introduction();

  std::cout << "Occupation: Pokemon Trainer" << "\n" <<
    "Pokemon Caught: " << pokemon_caught << "\n";
}


int main() {
  /* Hi, I made this program to learn more about class inheritance, and using
   * it to create an working mixed type array. Well sort off, but I figured it
   * out! I also took the opportunity to try to learn more about pointers, and
   * dynamic memory allocation.*/
  std::cout << "Person base class size: " << sizeof(Person) << "\n";
  std::cout << "Programer derived class size: " << sizeof(Programmer) << "\n";
  std::cout << "PkmnTrainer derived class size: " << sizeof(PkmnTrainer) << "\n";
  std::cout << "===================" << "\n";
  
  Person *person_list[] = {
    new Person("Joe", "Average", 30),
    new Programmer("Tyler", "Dillard", 18, 2, "Project Lorenzo"),
    new PkmnTrainer("Ash", "Ketchum", 10, 98)
  };

  int memory_allocated = 0;

  for (Person *person : person_list) {
    person->introduction();
    std::cout << "===================" << "\n";

    memory_allocated += sizeof(*person);
    delete person;
  }

  std::cout << "Total Bytes in memory that was allocated in this program: " << memory_allocated;
  return 0;
}

