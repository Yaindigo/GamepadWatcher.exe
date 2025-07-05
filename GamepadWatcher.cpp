
#include <Windows.h>
#include <Xinput.h>
#include <iostream>
#include <thread>
#include <chrono>

#pragma comment(lib, "Xinput.lib")

void SimulateAltF4() {
    INPUT input[4] = {};

    // Íàæàòèå Alt
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = VK_MENU; // Alt

    // Íàæàòèå F4
    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = VK_F4;

    // Îòïóñêàíèå F4
    input[2].type = INPUT_KEYBOARD;
    input[2].ki.wVk = VK_F4;
    input[2].ki.dwFlags = KEYEVENTF_KEYUP;

    // Îòïóñêàíèå Alt
    input[3].type = INPUT_KEYBOARD;
    input[3].ki.wVk = VK_MENU;
    input[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(4, input, sizeof(INPUT));
    std::cout << "[INFO] Alt+F4 simulated." << std::endl;
}

bool IsControllerConnected() {
    XINPUT_STATE state;
    ZeroMemory(&state, sizeof(XINPUT_STATE));
    return (XInputGetState(0, &state) == ERROR_SUCCESS);
}

int main() {
    std::cout << "=== Gamepad Watcher Started ===" << std::endl;

    bool wasConnected = IsControllerConnected();
    if (wasConnected) {
        std::cout << "[INFO] Gamepad initially connected." << std::endl;
    }
    else {
        std::cout << "[INFO] Gamepad initially NOT connected." << std::endl;
    }
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    while (true) {
        bool connected = IsControllerConnected();

        if (!connected && wasConnected) {
            std::cout << "[EVENT] Gamepad disconnected!" << std::endl;
            SimulateAltF4();
        }

        wasConnected = connected;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
