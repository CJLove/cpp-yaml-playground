#include <iostream>
#include <unistd.h>


#include "yaml-cpp/yaml.h"
#include "sample.h"

void usage()
{
    std::cout << "Usage:\n"
    << "direct [-f <file>]\n";
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

    try {
        Sample sample = yaml.as<Sample>();

        std::cout << sample;
        
    } catch (std::exception &e) {
        std::cout << "Caught " << e.what() << "\n";
    }
}