#include <iomanip>
#include <iostream>
using namespace std;

int celsius(int fahrenheitTemperature)
{
    return (fahrenheitTemperature - 32) * 5 / 9;
}

int fahrenheit(int celsiusTemperature)
{
    return celsiusTemperature * 9 / 5 + 32;
}

int main()
{
    cout << "Celsius to Fahrenheit" << endl;
    cout << "  C     F    C     F    C     F    C     F" << endl;

    for (int c{0}; c <= 100; c += 4)
    {
        for (int column{0}; column < 4 && c + column <= 100; ++column)
        {
            int temperature{c + column};
            cout << setw(3) << temperature << setw(6) << fahrenheit(temperature);
        }

        cout << endl;
    }

    cout << "\nFahrenheit to Celsius" << endl;
    cout << "  F     C    F     C    F     C    F     C" << endl;

    for (int f{32}; f <= 212; f += 4)
    {
        for (int column{0}; column < 4 && f + column <= 212; ++column)
        {
            int temperature{f + column};
            cout << setw(3) << temperature << setw(6) << celsius(temperature);
        }

        cout << endl;
    }

    return 0;
}
