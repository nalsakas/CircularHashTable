#include <catch2/catch_test_macros.hpp>
#include "CircularHashMap.h"

TEST_CASE("Circular Hash Table tests", "")
{
    CircularHashMap table;

    table.add("a");
    bool check = table.hashTable['a'].status == OCCUPIED && table.hashTable['a'].item == "a";
    REQUIRE(check == true);

    table.add("a");
    check = table.hashTable['b'].item != "a";
    REQUIRE(check == true);

    table.add("aa");
    check = table.hashTable['b'].status == OCCUPIED && table.hashTable['b'].item == "aa";
    REQUIRE(check == true);

    table.del("a");
    check = table.hashTable['a'].status == TOMBSTONE && table.hashTable['a'].item == "a";
    REQUIRE(check == true);

    table.del("aa");
    check = table.hashTable['b'].status == TOMBSTONE && table.hashTable['b'].item == "aa";
    REQUIRE(check == true);

    table.add("z");
    check = table.hashTable['z'].status == OCCUPIED && table.hashTable['z'].item == "z";
    REQUIRE(check == true);

    table.add("zz");
    check = table.hashTable['c'].status == OCCUPIED && table.hashTable['c'].item == "zz";
    REQUIRE(check == true);

    table.del("zz");
    check = table.hashTable['c'].status == TOMBSTONE && table.hashTable['c'].item == "zz";
    REQUIRE(check == true);

    check = table.hashTable['d'].status == NEVER_USED &&
        table.hashTable['e'].status == NEVER_USED &&
        table.hashTable['f'].status == NEVER_USED &&
        table.hashTable['g'].status == NEVER_USED &&
        table.hashTable['h'].status == NEVER_USED &&
        table.hashTable['k'].status == NEVER_USED &&
        table.hashTable['l'].status == NEVER_USED &&
        table.hashTable['m'].status == NEVER_USED;
    REQUIRE(check == true);
}