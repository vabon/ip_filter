#pragma once

#include <cstdarg>
#include <string>
#include <vector>

using ip = std::vector<unsigned char>;
using iplist = std::vector<ip>;
using vstr = std::vector<std::string>;

iplist filter(const iplist &, unsigned, ...);
iplist filter_any(const iplist &, unsigned char);
