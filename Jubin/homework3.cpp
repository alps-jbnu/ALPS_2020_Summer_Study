#include <iostream>
#include <algorithm>
#include <cassert>

#include "MyHashMap.h"

int main()
{
    MyHashMap<int, 100> hashMap;

    hashMap.Insert("key1", 50);
    assert(hashMap.Get(std::string("key1")) == 50);
    assert(hashMap.Get("key1") == 50);

    assert(hashMap.HasKey("key1"));
    assert(hashMap.HasKey(std::string("key1")));

    hashMap.Insert(std::string("key1"), 70);
    assert(hashMap.Get(std::string("key1")) == 70);
    assert(hashMap.Get("key1") == 70);

    assert(hashMap.Delete("key1"));
    assert(!hashMap.HasKey("key1"));
    assert(!hashMap.HasKey(std::string("key1")));
    assert(!hashMap.Delete(std::string("key1")));

    hashMap.Insert(std::string("key1"), 100);
    hashMap.Insert("year", 2020);
    hashMap.Insert(std::string("month"), 8);
    hashMap.Insert("day", 3);
    hashMap.Insert("day", 0);

    const char* keys[] = { "key1", "year", "month", "day" };
    const int expectedValue[] = { 100, 2020, 8, 0 };

    for (int i = 0; i < 4; ++i)
    {
        const char* key = keys[i];
        assert(hashMap.Get(key) == expectedValue[i]);
        assert(hashMap.Get(std::string(key)) == expectedValue[i]);
    }

    for (auto& pair : hashMap.GetEntries())
    {
        std::cout << "key: " << pair.first << '\t'
            << "value: " << pair.second << '\n';
    }

    return 0;
}