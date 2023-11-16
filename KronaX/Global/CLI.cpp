#include <string>
#include <stdio.h>

#include "CLI.hpp"
#include "Config.hpp"
#include "../Util/StringUtil.hpp"

using namespace std;
using namespace Config;

bool ParseDDash(string& k, string& v, ConfigGlobal& cfg) {

	if (k == "--bitvrs") {
		if (v == "sys") {
			cfg.setBitVrs(ConfigGlobal::BITVRS_SYS);
		}
	}

	return true;
}

bool ParseSDash(char v, ConfigGlobal& cfg) {

	switch (v) {
		
	case 'd': cfg.setDbg(true); break;

	default:
		printf("Unrecognized option '%c'\r\n", v);
		return false;
	}

	return true;
}

int ParseCLI(int argc, char** argv, char** argz) {

	bool ret = true;
	ConfigTLL* tll = ConfigTLL::GetInstance();
	ConfigIASM* iasm = ConfigIASM::GetInstance();
	ConfigGlobal* glbl = ConfigGlobal::GetInstance();

	glbl->setExePath(argv[0]);

	for (int i = 1; i < argc; ++i) {
		string op = string(argv[i]);
	
		if (op.length() == 1 || op[0] != '-') {
			printf("Invalid inpit '%s'\r\n", op.c_str());
			ret = false;
			continue;
		}

		if (op[1] == '-') {
			vector<string> args = StrUtil::split(op, "=");
			string k = args[0];
			string v = args.size() == 2 ? args[1] : "";
			ParseDDash(k, v, *glbl);
		}
		else {
			
			ParseSDash(op[1], *glbl);
		}
	}

	return ret;
}