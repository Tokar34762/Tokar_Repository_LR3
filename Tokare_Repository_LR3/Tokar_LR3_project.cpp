#include <iostream>
#include <vector>

using namespace std;

void inputArraySize(int &size) {
  cout << "Enter the array size: ";
  cin >> size;
  // Checking for correct input
  while (size <= 0) {
    cout << "The array size must be positive. Please enter again: ";
    cin >> size;
  }
}

void inputArrayValues(vector<int> &array) {
  cout << "Enter " << array.size() << " integer(s): ";
  for (int i = 0; i < array.size(); ++i) {
    cin >> array[i];
  }
}

int sumArray(const vector<int> &array) {
  int sum = 0;
  for (int num : array) {
    sum += num;
  }
  return sum;
}

double averageArray(const vector<int> &array) {
  if (array.empty())
    return 0.0; // Protection against division by zero
  return static_cast<double>(sumArray(array)) / array.size();
}

int main() {
  int choice;
  int size;
  vector<int> array;

  do {
    cout << "Menu:\n";
    cout << "1. Input array size\n";
    cout << "2. Input array values\n";
    cout << "3. Find sum of all elements of array\n";
    cout << "4. Find average value of array\n";
    cout << "0. Exit\n";
    cout << "Choose the menu item: ";
    cin >> choice;

    switch (choice) {
    case 1:
      inputArraySize(size);
      array.resize(size);
      break;
    case 2:
      inputArrayValues(array);
      break;
    case 3: {
      int sum = sumArray(array);
      cout << "The sum of all array elements: " << sum << endl;
      break;
    }
    case 4: {
      double average = averageArray(array);
      cout << "Average value of array elements: " << average << endl;
      break;
    }
    case 0:
      cout << "Exiting the program." << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  return 0;
}
