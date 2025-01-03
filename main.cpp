#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "CircularHashMap.h"

int main(int argc, char** argv)
{
    // Table
    CircularHashMap table;

    // Read command line
    for (int i = 1; i < argc; i++)
    {
        cout << argv[i] << " ";
    }
    cout << endl;

    string line;
    getline(cin, line);
    
    stringstream ss(line);

    vector<string> items;
    string item;
    while(ss >> item)
    {
        items.push_back(item);
    }

    // Process
    for (string item : items)
    {
        char op = item.front();
        item = item.substr(1);

        if (op == 'A')
        {
            cout << "ADD: " << item << endl;
            table.add(item);
        }
        else if (op == 'D')
        {
            cout << "DELETE: " << item << endl;
            table.del(item);
        }
    }

    table.print();
    return 0;
}