export module service;

import std;

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
