#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void WriteVarIntToArray(uint32_t val, vector<uint8_t>& array)
{
    while(val >= 0x80)
    {
        uint8_t t = static_cast<uint8_t>(val | 0x80);
        val >>= 7;
        array.push_back(t); 
    }
    array.push_back(val);
}

void ReadArrayToVal(uint32_t& val, vector<uint8_t>& array)
{
    uint32_t t = 0;
    int shift = 0;
    for(int i = 0; i < array.size(); i++)
    {
        t |= ((array[i] & 0x7f)<<shift);
        shift += 7;
        if((array[i] & 0x80) == 0)
        {
            break;
        }
    }
    val = t;
}