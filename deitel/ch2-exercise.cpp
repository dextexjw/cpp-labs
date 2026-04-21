#include <iostream>

using namespace std;

void ex2_16(){
    int x{0}, y{0};
    cout << "input the two numbers: ";
    cin >> x >> y;

    cout << "Sum: " << x+y << endl; 
    cout << "Product: " << x*y << endl; 
    cout << "Division: " << x/y << endl; 
    cout << "Quotient: " << x%y << endl; 
}

void ex2_17(){
    cout << "VX " << "YZ";
    cout << "VX ";
    cout << "YZ";
}

void ex2_18(){
    int x{0}, y{0}; 
    cout << "Give me two ints: ";
    cin >> x >> y;

    if (x > y)
        cout << x << " greater then " << y;
    else if ( x == y)
        cout << x << " equals " << y;
    else
        cout << x << " less then " << y;

}

void hamza(){
    cout << "Ruhaan is awesome" << endl;
    cout << "Ibraheem is amazing" << endl;
    cout << "Zaynab is cute kitty" << endl;
}

void ex2_25(){
    int x,y,z;
    cout << "enter threee variables: ";
    cin >> x >> y >> z;
    if (y%x == 0)
        cout << "x is a factor of y" << endl;
    if (y%z == 0)
        cout << "z is a factor of y" << endl;
    if (y%z != 0 && y%x != 0)
        cout << "no factors here" << endl;
}

void ex2_26(){
    cout << "* * * * * * * * \n"
            " * * * * * * * *\n"
            "* * * * * * * * \n"
            " * * * * * * * *\n"
            "* * * * * * * * \n"
            " * * * * * * * *\n"
            "* * * * * * * * \n"
            " * * * * * * * *\n";
}

void ex2_27(){
    cout << "Give me a Character for ASCI print: ";
    char x{0};
    cin >> x;
    cout << static_cast<int>(x);
}

void ex2_28(){
    int x{1234}, a, b, c, d;
    cout << "Enter a 4-digit number: ";
    cin >> x;

    d = x % 10;
    x = x / 10;
    c = x % 10;
    x = x / 10;
    b = x % 10;
    x = x / 10;
    a = x % 10;
    x = x / 10;

    cout << d << "  " << c << "  " << b << "  " << a; 

}

int main(){

    // ex2_17();
    // ex2_18();
    // ex2_25();
    // ex2_26();
    // ex2_27();
    ex2_28();

    // hamza();
  
    return 0;
}
