#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    string s{"Hello, world!"};
    array<string, 3> colors{"red", "green", "blue"};

    for (string s : colors)
        cout << s << " ";

    cout << endl;

    cout << "colors.begin(): " << colors.begin() << endl;
    cout << "colors.end(): " << colors.end() << endl;

    sort(colors.begin(), colors.end());

    for (string s : colors)
        cout << s << " ";

    cout << endl;

    for (string& s : colors)
    {
        s = "yellow";
        cout << s << " ";
    }

    cout << endl;

    for (string s : colors)
        cout << s << " ";
}
