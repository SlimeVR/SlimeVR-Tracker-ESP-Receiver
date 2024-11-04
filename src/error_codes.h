#pragma once

enum class ErrorCodes {
    NO_ERROR = 0x00,
    ESP_NOW_INIT_FAILED = 0x01,
    ESP_NOW_ADDING_BROADCAST_FAILED = 0x02,
    ESP_RECV_CALLACK_REGISTERING_FAILED = 0x03,
};