// Dalton Wemer
// CSC 325: Algorithms and Advanced Data Structures
// Implmentation of the Binary Addition Algorithm

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addingBinaryNumbers(int n, string a, string b){ 

    // C is a vector that will hold the sum
    string C = "";

    int temp = 0;

    // Varibles that will be used as iterators
    int aSize = a.length()-1;
    int bSize = b.length()-1;

    // Starting from the last character add the binary numbers
    // until neither A or B have any characters left to add
    while (aSize >= 0 || bSize >= 0 || temp == 1)
    {
      // If our a or b are different sizes we must sub in a 0 for the missing place
      temp += ((aSize >= 0)? a[aSize] - '0': 0);
      temp += ((bSize >= 0)? b[bSize] - '0': 0);
      // Push the answer to the front of the C string
      C = char(temp % 2 + '0') + C;
      temp = temp / 2;
      // Decrement our itterators
      aSize--; 
      bSize--;
    }

    return C;
}

bool isValidBinary(string s)
{
  const string valid_chars = "01";

  for (auto it = s.cbegin() ; it != s.cend(); ++it) {
    
	  std::string c(1, *it);

	  if (strstr(valid_chars.c_str(), c.c_str()) == NULL)
    {
      return false;
    }
  }
  return true;
}


int main(){
    string tempA, tempB;
    string a, b;
    string tempN;

    cout << "What is the largest binary number you wish to add?" << endl;
    getline(cin, tempN); 

    cout << "Enter Addend 1" << endl;
    cin >> tempA;

    while(!isValidBinary(tempA))
    {
        cout << "Please only enter Binary numbers" << endl;
        cout << "Enter Addend 1" << endl;
        cin >> tempA;   

        if(isValidBinary(tempA))
        {
            break;
        }
    } 

        a = tempA; 

        cout << "Enter Addend 2" << endl;
        cin >> tempB;

        while(!isValidBinary(tempB))
        {
            cout << "Please only enter Binary numbers" << endl;
            cout << "Enter Addend 1" << endl;
            cin >> tempA;   
            if(isValidBinary(tempA))
            {
                break;
            }
        } 

    b = tempB;
    cout << "here ya go";
    cout << addingBinaryNumbers(5, a, b) << endl;
    addingBinaryNumbers(3, a, b);
}