#include<iostream>

//~   #include <bits/stdc++.h> 
//*   above line shows errors but works pretty fine
// The bits/stdc++.h header is a shortcut that includes a vast number of standard C++ libraries, making it easier to access a wide range of functions and classes without specifying each library individually. It's a time-saving approach for programmers, especially when you need several standard libraries in your code.

using namespace std; //By adding using namespace std; at the beginning of your program, you're telling the compiler that you want to use all the names from the std namespace without explicitly specifying std:: each time. This can make your code cleaner and more concise.

int main() {
    cout << "Hey, Striver!"<< endl;
    cout << "Hey, Kaushik! \n";
    cout << "Hey, Arya!";


    int x;
    cout << "\nEnter the value of x: ";
    cin >> x;
    cout << "Value of x: " << x;
// Loop statements
    int age=10;
    if (age >= 18) {
       cout << "You are an adult." << endl;
    }
    else{
        cout << "You are not an adult." << endl;
    }
// switch case statements
    int day = 4;
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid";
        


    return 0;
}




