export module service;

import <iostream>;


export namespace core {

class Service {
    public:
        Service() = default;
        ~Service() = default;
        void start() {
            std::cout << "Service started" << std::endl;
        }
        void stop() {
            std::cout << "Service stopped" << std::endl;
        }
};

}
