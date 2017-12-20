#pragma once

#include <string>
#include <vector>

using ip = std::vector<std::string>;
using iplist = std::vector<ip>;
using vstr = std::vector<std::string>;

iplist filter(const iplist &, int);
iplist filter(const iplist &, int, int);
iplist filter_any(const iplist &, int);
