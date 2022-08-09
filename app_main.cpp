#pragma once

#include <string>
#include <vector>
#include "App.h"

int main(int argc, char **argv)
{
	std::vector<std::wstring> args(argv + 1, argv + argc);
	foodApp::App::main(args);
}

