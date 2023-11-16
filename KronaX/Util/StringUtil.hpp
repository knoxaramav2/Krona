#ifndef KR_SUTIL
#define KR_SUTIL

#include <string>
#include <vector>

namespace StrUtil {
	std::vector<std::string> split(std::string& v, const char* delim);
	std::vector<std::string> split(std::string& v, std::string& delim);

}


#endif