#include "StringUtil.hpp"

using namespace std;

std::vector<std::string> StrUtil::split(std::string& v, const char* delim)
{
	vector<size_t> idxs;
	
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t ddx = 0; ddx < strlen(delim); ++ddx) {
			if (v[i] == delim[ddx]) {
				idxs.push_back(i);
				break;
			}
		}
	}

	//Insertion sort
	for (bool done = false; !done;) {
		done = true;
		for (size_t i = 0; i < idxs.size() - 1; ++i) {
			if (idxs[i] > idxs[i+1]) {
				size_t tmp = idxs[i];
				idxs[i] = idxs[i + 1];
				idxs[i + 1] = tmp;
				done = false;
			}
		}
	}

	vector<string> ret;
	size_t lIndex = 0;
	for (size_t idx : idxs) {
		string trm = v.substr(lIndex, idx-lIndex);
		ret.push_back(trm);
		lIndex = idx+1;
	}

	if (lIndex < v.size()) {
		ret.push_back(v.substr(lIndex, v.size()-lIndex));
	}

	return ret;
}

std::vector<std::string> StrUtil::split(std::string& v, std::string& delim)
{
	return StrUtil::split(v, delim.c_str());
}
