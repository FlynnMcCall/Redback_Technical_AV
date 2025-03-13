/// Question 1: This question requests you to fix all compile errors in the main function and any classes. Address
/// the comments given inside the code.
/// Your code should run and compile without any warnings or errors.


#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>

using namespace std;
// added namespace

const int values[] = { 1,2,3,4,5 };
const int val_size = sizeof(values) / sizeof(int);
// Added brackets


class Foo {
    std::vector<int> mElements;
public:
    Foo(std::initializer_list<int> list)
    : mElements(list) {}

    void Debug() {
        for( int &m : mElements){
            cout << m << " ";
        }
        cout << endl;
    }
};


// reordered struct syntax to define type
struct person{
    int age;
    float weight;
};


// now this takes non-const int**
void show_output(int** pp)
{
    //printf("%p : %p : %d", pp, *pp, **pp);
    cout << pp << " : " << *pp << " : " << **pp << endl;
    // switched to cout
}



int main() {

    int x = -10;
    int y = 15;
    cout << " x=" << x << " y=" << y << endl;

    // print integer ratios of y:x till x < y
    // invalid ratios should print 0
    while (x < y)
    {
        if (x == 0) {
            cout << "ratio: " << 0 << endl;
        }
        else {
            cout << "ratio: " << (y/x) << endl;
        }
        // added conditional logic
        x++;
        y--;
    }


    int i = 1, j = 1; // don't change values

    // se assign (=) to equals (==) and bitwise (&) to logic (&&)
    if ((i != 3) && (j == 1))
    {
        cout << "j is 1 and i is not 3\n";
    }
    else {
        cout << "either j is NOT 1, or i is set to 3\n";

    }


    typedef map<int, double> valmap;
    valmap m;

    for (int i = 0; i < val_size; i++) {
        // used the correct variable name and added braces
        m.insert(make_pair(values[i], pow(values[i], .5)));
    }
    m.erase(1);
    m.insert(make_pair(1, 2.0));
    // deleted original mapping, and inserted new mapping


    int n = 1;
    int* p = &n;
    int** pp = &p;
    show_output(pp);
    // made a int-pointer-pointer

    // Initialise a person on the heap with the use of smart pointers (unique_ptr) instead.
    struct person* ptr;
    ptr = (struct person*)malloc(sizeof(struct person));
    ptr->age = 10;
    ptr->weight = 55.5;

    // Initialise with 5 integers
    Foo foo({1,2,3,4,5});

    //foo.Debug();

    return 0;
}
