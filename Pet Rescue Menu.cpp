#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cat{
public: 
  string name;
  string breed;
  int age;
  bool rescued;
  int mood;
  int hunger;

  // Constructor.
  Cat (string n, string b, int a, bool r, int m, int h) {
    name = n;
    breed = b;
    age = a;
    rescued = r;
    mood = m;
    hunger = h;
  }

  // Method to increase hunger of the cat by one.
  void feed() {
    if (hunger < 10) {
      hunger += 1;
    }
  }

  // Method to increasee mood of the cat by one.
  void play() {
    if (mood < 10) {
      mood += 1;
    }
  }

  // Method to display all details about the cat.
  void status() {
    cout << "Name: " << name << endl;
    cout << "Breed: " << breed << endl;
    cout << "Age: " << age << endl;
    cout << "Rescued Status: " << (rescued ? "Yes" : "No") << endl;
    cout << "Mood: " << mood << endl;
    cout << "Hunger: " << hunger << endl;
  }
};

int main() {
  
  // Objects.
  Cat garfield ("Garfield", "Exotic Shorthair", 7, true, 2, 10);
  Cat tom ("Tom", "Domestic Shorthair", 5, true, 1, 5);
  vector<Cat> cats = {garfield, tom};

  // Loop to go through the menu.
  while (true) {
    cout << "\n---- Pet Rescue Menu ----\n";
    cout << "1. View all pets" << endl;
    cout << "2. Feed a pet" << endl;
    cout << "3. Play with a pet" << endl;
    cout << "4. Check a pet's status" << endl;
    cout << "5. Exit" << "\n\n";

  // Input to choose the menu.
    cout << "Type a number from the menu: ";
    int choice;
    cin >> choice;
    cout << "\n\n";
    // Check for invalid inputs
    if (choice < 0 && choice > 5) {
      cout << "Invalid number, please re-enter: ";
      continue;
    }

    // Navigating through the menu.
    switch (choice) {
    case 1:
        // View all pets    
        cout << "Listing all pets:\n";
        for (int i = 0; i < cats.size(); i++) {
            cout << i + 1 << ". " << cats[i].name << " (" << cats[i].breed << ")\n";
        }
        break;

    case 2:
        // Feed a pet
        cout << "Which pet do you want to feed? ";
        int feedChoice;
        cin >> feedChoice;
        if (feedChoice >= 1 && feedChoice <= cats.size()) {
            cats[feedChoice - 1].feed();
            cout << cats[feedChoice - 1].name << " has been fed!\n";
        } else {
            cout << "Invalid pet choice.\n";
        }
        break;

    case 3:
        // Play with a pet
        cout << "Which pet do you want to play with? ";
        int playChoice;
        cin >> playChoice;
        if (playChoice >= 1 && playChoice <= cats.size()) {
            cats[playChoice - 1].play();
            cout << cats[playChoice - 1].name << " is happier now!\n";
        } else {
            cout << "Invalid pet choice.\n";
        }
        break;

    case 4:
        // Check status
        cout << "Which pet’s status do you want to check? ";
        int statusChoice;
        cin >> statusChoice;
        if (statusChoice >= 1 && statusChoice <= cats.size()) {
            cats[statusChoice - 1].status();
        } else {
            cout << "Invalid pet choice.\n";
        }
        break;

    case 5:
        cout << "Exiting program... Goodbye!\n";
        return 0;

    default:
        cout << "Invalid choice, try again.\n";
    }

  }

}