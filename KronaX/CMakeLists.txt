# CMakeList.txt : CMake project for KronaX, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (KronaX "KronaX.cpp" "KronaX.h"   "Global/CLI.hpp" "Global/CLI.cpp" "Global/Config.hpp" "Global/Config.cpp" "Util/StringUtil.hpp" "Util/StringUtil.cpp")

# TODO: Add tests and install targets if needed.
