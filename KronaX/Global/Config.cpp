#include <string>

#include "Config.hpp"

using namespace std;
using namespace Config;

ConfigTLL::ConfigTLL()
{
	
}

ConfigTLL* Config::ConfigTLL::GetInstance()
{
	static ConfigTLL* _inst;

	if (_inst == nullptr) {
		_inst = new ConfigTLL();
	}

	return _inst;
}

ConfigIASM::ConfigIASM()
{
}

ConfigIASM* Config::ConfigIASM::GetInstance()
{
	static ConfigIASM* _inst;
	if (_inst == nullptr) {
		_inst = new ConfigIASM;
	}

	return _inst;
}

ConfigGlobal::ConfigGlobal()
{
	this->_bitvrs = BITVRS_SYS;
	this->_debug = false;
}

std::string Config::ConfigGlobal::exePath()
{
	return this->_exePath;
}

void Config::ConfigGlobal::setExePath(std::string path)
{
	size_t dotPosf = path.find_last_of('/');
	size_t dotPosb = path.find_last_of('\\');
	if (dotPosf != string::npos || dotPosb != string::npos) {

		dotPosb = dotPosb == string::npos ? 0 : dotPosb;
		dotPosf = dotPosf == string::npos ? 0 : dotPosf;
		size_t pos = dotPosb > dotPosf ? dotPosb : dotPosf;
		path = path.substr(0, pos);
	}

	this->_exePath = path + '/';
}

int Config::ConfigGlobal::bitVrs()
{
	return this->_bitvrs;
}

void Config::ConfigGlobal::setBitVrs(int v)
{
	this->_bitvrs = v;
}

bool Config::ConfigGlobal::dbg()
{
	return this->_debug;
}

void Config::ConfigGlobal::setDbg(bool v)
{
	this->_debug = v;
}

ConfigGlobal* Config::ConfigGlobal::GetInstance()
{
	static ConfigGlobal* _inst;
	if (_inst == nullptr) {
		_inst = new ConfigGlobal;
	}

	return _inst;
}

