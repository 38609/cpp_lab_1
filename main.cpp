#include <iostream>
#include <map>

using namespace std;

unsigned long convertFromReadable(string value);

int main() {
    cout << convertFromReadable("4") << endl; // Not found unit in units map -> return 0
    cout << convertFromReadable("4S") << endl; // Not found unit in units map -> return 0
    cout << convertFromReadable("4M") << endl;
    cout << convertFromReadable("2.1G") << endl;
    cout << convertFromReadable("1.2421G") << endl;
    cout << convertFromReadable("94T") << endl;
    cout << convertFromReadable("84.23333P") << endl;
    cout << convertFromReadable("6.434E") << endl;
}

unsigned long convertFromReadable(string value) {
    map<char, int> units = {{'M', 6},{'G', 9},{'T', 12},{'P', 15},{'E', 18}};

    int shift = 0;
    int positionDot = 0;
    char size = value.back();
    auto unit = units.find(size);
    value.erase(remove(value.begin(), value.end(), size), value.end());

    if (unit == units.end()) return 0;

    positionDot = value.find('.');
    shift = unit->second;

    if (positionDot > 0) {
        value.erase(remove(value.begin(), value.end(), '.'), value.end());
        shift = unit->second - (value.length() - positionDot);
    }

    for (int i = 0; i < shift; i++)
        value += '0';

    return stoul(value);
}
