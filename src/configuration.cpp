#include "configuration.h"

Configuration &Configuration::getInstance() {
    return instance;
}

void Configuration::setup() {
    bool status = LittleFS.begin();
    if (!status) {
        Serial.println("Could not mount LittleFS, formatting");

        status = LittleFS.format();
        if (!status) {
            Serial.println("Could not format LittleFS, aborting");
            return;
        }

        status = LittleFS.begin();
        if (!status) {
            Serial.println("Could not mount LittleFS, aborting");
            return;
        }
    }
    Serial.println("LittleFS is mounted");
}

uint8_t Configuration::getSavedTrackerCount() {
    if (!LittleFS.exists(savedTrackerCountPath)) {
        Serial.printf("%s doesn't exist, returning 0 saved trackers\n", savedTrackerCountPath);
        return 0;
    }

    auto file = LittleFS.open(savedTrackerCountPath, "r");
    uint8_t result;
    file.read(&result, sizeof(uint8_t));
    file.close();

    return result;
}

void Configuration::setSavedTrackerCount(uint8_t newValue) {
    Serial.printf("New saved trackers count: %d\n", newValue);
    auto file = LittleFS.open(savedTrackerCountPath, "w", true);
    file.write(&newValue, sizeof(uint8_t));
    file.close();
}

Configuration Configuration::instance;
