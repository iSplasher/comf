module;

#include "efsw/efsw.hpp"

export module watcher;

import <filesystem>;
import <iostream>;
import <vector>;


export namespace core {

    class WatcherListener : public efsw::FileWatchListener {
        public:
            WatcherListener() = default;
            ~WatcherListener() = default;
            void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename = "") {
                std::cout << "File action: " << dir << filename << std::endl;
            }
    };

    class Watcher {
        public:
            Watcher() : watcher(), listener() {
                addWatch(".");
            }
            ~Watcher() = default;

            void addWatch(const std::string& path) {
                watchIDs.push_back(watcher.addWatch(std::filesystem::absolute(path).string(), &listener));
            }

            void start() {
                std::cout << "Watcher started" << std::endl;
                watcher.watch();
            }
            void stop() {
                std::cout << "Watcher stopped" << std::endl;
                for (const auto watchID : watchIDs) {
                    watcher.removeWatch(watchID);
                }
            }

    private:
        efsw::FileWatcher watcher;
        std::vector<efsw::WatchID> watchIDs;

        WatcherListener listener;

    };



}