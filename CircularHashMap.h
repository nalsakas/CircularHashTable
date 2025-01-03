#include <iostream>
#include <string>
#include <map>
using namespace std;

enum Status
{
    NEVER_USED,
    OCCUPIED,
    TOMBSTONE
};

struct Entry
{
    string item;
    Status status = {NEVER_USED};
};

class CircularHashMap
{
public:
    char hashit(const string& str)
    {
        char h = str.back();
        return h;
    }

    void add(const string str)
    {
        char h = this->hashit(str);
        Entry& e = this->hashTable[h];

        int count = 0;
        while (count < 26)
        {
            if (this->hashTable[h].item == str)
            {
                break;
            }

            if (this->hashTable[h].status == NEVER_USED)
            {
                this->hashTable[h].item = str;
                this->hashTable[h].status = OCCUPIED;
                break;
            }

            h += 1;
            h = (h - 'a') % 26 + 'a';
            count++;
        }
    }

    void del(const string str)
    {
        char h = this->hashit(str);
        Entry &e = this->hashTable[h];

        int count = 0;
        while (count < 26)
        {
            if (this->hashTable[h].item == str)
            {
                this->hashTable[h].status = TOMBSTONE;
                break;
            }

            h += 1;
            h = (h - 'a') % 26 + 'a';
            count++;
        }
    }

    void print()
    {
        for (auto const pair : this->hashTable)
        {
            switch (pair.second.status)
            {
                case NEVER_USED:
                    cout << pair.first << ": " << endl;
                    break;
                case OCCUPIED:
                    cout << pair.first << ": " << pair.second.item << endl;
                    break;
                case TOMBSTONE:
                    cout << pair.first << ": " << "TOMBSTONE" << endl;
                    break;
            }
        }
    }

    map<char, Entry> hashTable = {
        {'a', Entry()},
        {'b', Entry()},
        {'c', Entry()},
        {'d', Entry()},
        {'e', Entry()},
        {'f', Entry()},
        {'g', Entry()},
        {'h', Entry()},
        {'i', Entry()},
        {'j', Entry()},
        {'k', Entry()},
        {'l', Entry()},
        {'m', Entry()},
        {'n', Entry()},
        {'o', Entry()},
        {'p', Entry()},
        {'q', Entry()},
        {'r', Entry()},
        {'s', Entry()},
        {'t', Entry()},
        {'u', Entry()},
        {'v', Entry()},
        {'w', Entry()},
        {'x', Entry()},
        {'y', Entry()},
        {'z', Entry()}
    };
};