/// Question 1: This question requests you to fix all compile errors in the main function and any classes. Address
/// the comments given inside the code.
/// Your code should run and compile without any warnings or errors.

/*
I coded this without changing the compiler flags. On my computer that meant everything is set to C++98. 

Anyways I changed the compile flags, I used C++17 for Q2 onwards, but like, this already works ¯\_(ツ)_/¯
*/

#include <iostream>
#include <map>
#include <vector>
//#include <initializer_list> // NOT SUPPORTED IN C++98
#include <memory> // for unique_ptr

// 1: use namespace std clear up 3 errors immediately
// (also removed all the now-redundant std::'s )
using namespace std;

const int values[] = { 1,2,3,4,5 };
const int val_size = sizeof(values) / sizeof(int);
// 2: added brackets

class Foo {
private:
    vector<int> mElements;
public:
Foo(int arr[], int size){
        for (int i = 0; i < size; i++) {
            mElements.push_back(arr[i]);
        }
    }
// 3: Sent this code back to 20th century (WHY C++98?!)

};


struct Person{
    int age;
    float weight;
};
// 4: changed the syntax to name the struct, rather than instantiate, renamed to follow BP

void show_output(int** pp)
// 5: show_output now takes non-consts 
{
    cout << pp << " : " << *pp << " : " << **pp << endl;
// 6: Switched c to c++ code
}



int main() {

    int x = -10;
    int y = 15;
    cout << " " << x << " " << y << endl;
// 7: cleaned up the syntax so it, like, compiles n' stuff

    // print integer ratios of y:x WHILE x < y
    // invalid ratios should print 0
// 8: The discord said your comment was wrong - so I fixed it :)
    while (x < y)
    {
        if (x != 0){
            cout << "ratio: " << (y/x) << endl;
        } else {
            cout << "ratio: " << 0 << endl;
        }
// 9: Added conditional logic to meet requirements
        x++;
        y--;
    }


    int i = 1, j = 1; // don't change values
    if ((i == !3) && (j == 1))
// 10: switched to double equal signs and logical AND (instead of the assignment operators and bitwise AND)
    {
        cout << "j is 1 and i is not 3\n";
    }
    else {
        cout << "either j is NOT 1, or i is set to 3\n";
    }


    typedef map<int, double> ValMap;
// 11: renamed to follow bp (https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/)
    ValMap m;

    for (int i = 0; i < val_size; i++) {
// 12: incorrect variable name + added braces for clarity
        m.insert(make_pair(values[i], pow(values[i], .5)));
    }
    m.erase(1);
    m.insert(make_pair(1, 2.));
// 13: not sure what you wanted me to do about the double-mapping, but this was my best guess


    int n = 1;
    int* p = &n;
    int** pp = &p;
    show_output(pp);
// 14: added a pointer pointer (was this the intended behaviour?)

    // Initialise a person on the heap with the use of smart pointers (unique_ptr) instead. Check.
    //struct Person* ptr;
    unique_ptr<Person> ptr(new Person);
// 15: COMP1511 got me into bad habits... switched c code for c++
// 16: std::make_unique is c++14 plus. sad.
    ptr->age = 10;
    ptr->weight = 55.5;

    // Initialise with 5 integers
    int arr[5] = {1,2,3,4,5};
    Foo foo (arr, 5);
// 17: Did it boss

    return 0;
}
