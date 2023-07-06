#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ArcaUtils.h"
#include "Lexxer.h"

int main(int argc, char** argv)
{
    if (argc <= 1) {
        ThrowSTDError("Invalid arguments passed.");
        return -1;
    }
    ThrowWarning("drhlang is still experimental.");
    std::string file_name = argv[1];
    std::vector<std::string> Lines = GrabContents(file_name);
    LexicalAnalysis(Lines);
}