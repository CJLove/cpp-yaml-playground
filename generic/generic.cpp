#include <iostream>
#include <fstream>
#include <unistd.h>
#include "yaml-cpp/yaml.h"


void usage() {
    std::cout << "Usage:\n"
    << "generic [-f <file>]\n";
    exit(1);
}

int main(int argc, char**argv)
{
    const char *file = "../inputs/sample.yaml";
    int c = 0;

    while ((c = getopt(argc,argv,"f:?")) != EOF) {
        switch (c) {
        case 'f':
            file = optarg;
            break;
        case '?':
            usage();
            break;
        default:
            std::cerr << "Unexpected arg " << (char)c << "\n";
            usage();
        }
    }
    
    auto yaml = YAML::LoadFile(file);

    std::cout << "Loaded " << file << "\n";
    
    // Pretty-print:
    // std::cout << yaml << "\n";

    if (yaml["top-string"])
        std::cout << "top-string: " << yaml["top-string"].as<std::string>() << "\n";

    if (yaml["top-bool"]) {
        std::cout << "top-bool: " << yaml["top-bool"].as<bool>() << "\n";
        std::cout << "top-bool: " << yaml["top-bool"].as<std::string>() << "\n";
    }

    if (yaml["top-list"]) {
        // Throws YAML::TypedBadConversion
        //std::cout << "top-list: " << yaml["top-list"].as<std::string>() << "\n";

        // 3rd item of list
        std::cout << "top-list[2]: " << yaml["top-list"][2].as<std::string>() << "\n";
    }

    if (yaml["top-dict"]) {
        // value for key "key2"
        std::cout << "top-dict[\"key2\"]: " << yaml["top-dict"]["key2"].as<std::string>() << "\n";
    
    }


}