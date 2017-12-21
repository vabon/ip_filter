#include "lib.h"
#include "version.h"
#include <algorithm>

iplist filter(const iplist & l, int first_byte)
{
    auto query = std::to_string(first_byte);
    
    iplist result;
    
    for (const auto & addr : l)
    {
        if (!addr[0].compare(query))
            result.push_back(addr);
    }
    
    return result;
}

iplist filter(const iplist & l, int first_byte, int second_byte)
{
    auto query1 = std::to_string(first_byte);
    auto query2 = std::to_string(second_byte);
    
    iplist result;
    
    for (const auto & addr : l)
    {
        if (!addr[0].compare(query1) && !addr[1].compare(query2))
            result.push_back(addr);
    }
    
    return result;
}

iplist filter_any(const iplist & l, int any_byte)
{
    auto query = std::to_string(any_byte);
    
    iplist result;

    for (const auto & addr : l)
    {
        if (std::find(addr.begin(), addr.end(), query) != addr.end())
            result.push_back(addr);
    }
    
    return result;
}
