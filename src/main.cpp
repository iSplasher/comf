import <iostream>;

import service;
import system;
import watcher;


int main() {
    auto system = core::System();
    system.start();
    auto watcher = core::Watcher();
    watcher.start();
    system.sleep(15000);
    std::cout << "Hello, World!" << std::endl;
    watcher.stop();
    system.stop();
}