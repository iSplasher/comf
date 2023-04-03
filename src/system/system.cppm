export module system;

import <iostream>;
import <thread>;
import <chrono>;

export namespace core {

    class System {
        public:
            System() = default;
            ~System() = default;

            void sleep( unsigned long milliseconds ) {
                std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
            }

            void start() {
                std::cout << "System started" << std::endl;
            }
            void stop() {
                std::cout << "System stopped" << std::endl;
            }
    };

}