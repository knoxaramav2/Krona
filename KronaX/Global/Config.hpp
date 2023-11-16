#ifndef KR_CONFIG
#define KR_CONFIG

#include<string>
namespace Config {
	class ConfigTLL {
		ConfigTLL();
	public:
		static ConfigTLL* GetInstance();
	};

	class ConfigIASM {
		ConfigIASM();
	public:
		static ConfigIASM* GetInstance();
	};

	class ConfigGlobal {

		std::string _exePath;

		int _bitvrs;
		bool _debug;

		ConfigGlobal();
	public:
		
		std::string exePath();
		void setExePath(std::string);

		int bitVrs();
		void setBitVrs(int v);

		bool dbg();
		void setDbg(bool v);

		static const unsigned int BITVRS_SYS = 0;
		static const unsigned int BITVRS_8 = 1;
		static const unsigned int BITVRS_16 = 2;
		static const unsigned int BITVRS_32 = 3;
		static const unsigned int BITVRS_64 = 4;


		static ConfigGlobal* GetInstance();
	};
}



#endif