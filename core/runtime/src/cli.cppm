module;

#include "cxxopts.hpp"

export module cli;

import std;
export namespace core {

    class CLI {
        public:
            CLI() = default;
            ~CLI() = default;

            void start(int argc, char** argv) {
                cxxopts::Options options("MyProgram", "One line description of MyProgram");
                options.add_options()
                    ("d,debug", "Enable debugging")
                    ("f,file", "File name", cxxopts::value<std::string>())
                    ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
                    ("h,help", "Print help")
                ;

                auto result = options.parse(argc, argv);

                if (result.count("help"))
                {
                  std::cout << options.help() << std::endl;
                  exit(0);
                }

                bool debug = result["debug"].as<bool>();
                std::string bar;
                if (result.count("bar"))
                  bar = result["bar"].as<std::string>();
                int foo = result["foo"].as<int>();
            }
    };


}
