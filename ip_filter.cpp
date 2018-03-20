#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "lib.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
vstr split(const std::string &str, char d)
{
    vstr r;
    
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    
    r.push_back(str.substr(start));
    
    return r;
}

void print(iplist & ip_list)
{
    for (const auto & addr : ip_list)
    {
        for(auto ip_part = addr.cbegin(); ip_part != addr.cend(); ++ip_part)
        {
            if (ip_part != addr.cbegin())
            {
                std::cout << ".";
                
            }
            std::cout << +*ip_part;
        }
        std::cout << std::endl;
    }
}

ip to_ip(const vstr & v_str)
{
    ip v_uchar;

    std::transform(v_str.begin(), v_str.end(), std::back_inserter(v_uchar),
                   [](const std::string & str)
                   {
                       return static_cast<unsigned char>(std::stoi(str));
                   }
                  );

    return v_uchar;
}

int main(int argc, const char * argv[])
{
    
    try
    {
        iplist ip_pool;
        
        for(std::string line; std::getline(std::cin, line);)
        {
            vstr v = split(line, '\t');
            ip_pool.push_back(to_ip(split(v.at(0), '.')));
        }
        
        std::sort(ip_pool.begin(), ip_pool.end(), [](const ip & a, const ip & b){ return a > b; });
                
        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8
        
        print(ip_pool);
        
        // TODO filter by first byte and output
        // ip = filter(1)
        
        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8
        
        auto l = filter(ip_pool, 1, 1);

        print(l);

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
        
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        
        l = filter(ip_pool, 2, 46, 70);
        
        print(l);

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46

        l = filter_any(ip_pool, 46);
        
        print(l);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
