import <iostream>;

import service;
import system;
import watcher;
import cli;


int main(int argc, char** argv)
{

    auto cli = core::CLI();
    cli.start(argc, argv);

     auto system = core::System();
    system.start();
    auto watcher = core::Watcher();
    watcher.start();




    system.sleep(15000);
    std::cout << "Hello, World!" << std::endl;
    watcher.stop();
    system.stop();


    return 0;
}