#include "lib.h"
#include "version.h"
#include <algorithm>

iplist filter(const iplist & l, unsigned n_bytes, ...)
{
    va_list vl;
    va_start(vl, n_bytes);
    ip chunks(n_bytes);
    
    for (auto i = 0; i < n_bytes; i++)
    {
        chunks[i] = va_arg(vl, unsigned);
    }
    va_end(vl);

    
    iplist result;

    std::copy_if(l.begin(), l.end(), std::back_inserter(result),
                 [chunks] (const ip & a)
                 {
                     return std::search(a.begin(), a.end(),
                                        chunks.begin(), chunks.end())
                                    == a.begin();
                 }
                );
    
    return result;
}

iplist filter_any(const iplist & l, unsigned char any_byte)
{
    iplist result;

    std::copy_if(l.begin(), l.end(), std::back_inserter(result),
                 [any_byte] (const ip & a)
                 {
                     return std::find(a.begin(), a.end(), any_byte) != a.end();
                 }
                );

    return result;
}
