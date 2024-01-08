#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <map>

void displayHelp() {
    std::cout << "RLaunch - Command-Line Tool Help\n";
    std::cout << "Usage:\n";
    std::cout << "  RLaunch.exe [OPTIONS]\n\n";
    std::cout << "Options:\n";
    std::cout << "  --character-id [ID]  Sets the JX_CHARACTER_ID environment variable\n";
    std::cout << "  --display-name [NAME]  Sets the JX_DISPLAY_NAME environment variable\n";
    std::cout << "  --session-id [ID]  Sets the JX_SESSION_ID environment variable\n";
    std::cout << "  --jar-path [PATH]  Sets the path to the JAR file\n";
    std::cout << "  --jdk-path [PATH]  Sets the path to the JDK\n";
    std::cout << "  --vm-args [ARGS]  Sets the virtual machine arguments\n";
    std::cout << "  --help, -h  Displays this help message\n";
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    std::cout << " ____  _                           _     \n";
    std::cout << "|  _ \\| |    __ _ _   _ _ __   ___| |__  \n";
    std::cout << "| |_) | |   / _` | | | | '_ \\ / __| '_ \\ \n";
    std::cout << "|  _ <| |__| (_| | |_| | | | | (__| | | |\n";
    std::cout << "|_| \\_\\_____\\__,_|\\__, |_| |_|\\___|_| |_|\n";
    if (argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
        displayHelp();
        return 0;
    }
    std::map<std::string, std::string> params;
    for (int i = 1; i < argc; i += 2) {
        params[argv[i]] = argv[i + 1];
    }
    if (params["--character-id"].empty()) {
        printf("Character Id is required.\n");
        displayHelp();
        return 0;
    }
    if (params["--display-name"].empty()) {
        printf("Display name is required.\n");
        displayHelp();
        return 0;
    }
    if (params["--session-id"].empty()) {
        printf("Session id is required.\n");
        displayHelp();
        return 0;
    }
    const char* envVariables[][2] = {
        {"JX_CHARACTER_ID", params["--character-id"].c_str()},
        {"JX_DISPLAY_NAME", params["--display-name"].c_str()},
        {"JX_SESSION_ID", params["--session-id"].c_str()}
    };

    for (const auto& variable : envVariables) {
        SetEnvironmentVariableA(variable[0], variable[1]);
    }
    wchar_t userProfile[MAX_PATH];
    DWORD userProfileSize = sizeof(userProfile) / sizeof(wchar_t);
    if (GetEnvironmentVariableW(L"USERPROFILE", userProfile, userProfileSize) > 0) {
        std::wstring jarPath = params["--jar-path"].empty() ?
            (std::wstring(userProfile) + L"\\AppData\\Local\\RuneLite\\RuneLite.jar") :
            std::wstring(params["--jar-path"].begin(), params["--jar-path"].end());
        if (params["--jdk-path"].empty()) {
            printf("JDK INVALID\n");
            return 0;
        }
        std::wstring javaExecutablePath = std::wstring(params["--jdk-path"].begin(), params["--jdk-path"].end());

        std::wstring vmArgs = params["--vm-args"].empty() ?
            L"-XX:+DisableAttachMechanism -Drunelite.launcher.nojvm=true -Xmx1G -Xss2m -XX:CompileThreshold=1500 -Djna.nosys=true -Dsun.java2d.noddraw=false -Dsun.java2d.opengl=false -Djava.net.preferIPv4Stack=true -Djava.net.preferIPv4Addresses=true" :
            std::wstring(params["--vm-args"].begin(), params["--vm-args"].end());

        std::wstring command = javaExecutablePath + L" " + vmArgs + L"-jar " + jarPath;

        STARTUPINFOW si = {};
        PROCESS_INFORMATION pi = {};

        if (CreateProcessW(NULL, const_cast<wchar_t*>(command.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
        }
        else {
            std::wcerr << L"Failed to start Java application. Error code: " << GetLastError() << std::endl;
        }
    }
    else {
        std::wcerr << L"Failed to retrieve USERPROFILE environment variable. Error code: " << GetLastError() << std::endl;
    }
    return 0;
}
