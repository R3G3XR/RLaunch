```bash
 ____  _                           _     
|  _ \| |    __ _ _   _ _ __   ___| |__  
| |_) | |   / _` | | | | '_ \ / __| '_ \ 
|  _ <| |__| (_| | |_| | | | | (__| | | |
|_| \_\_____\__,_|\__,_|_| |_|\___|_| |_|
```

# RLaunch

RLaunch is a robust OSRS RuneLite Launcher command-line utility designed to streamline the process of setting up and running Java applications. It simplifies the configuration of environment variables and execution parameters, making it easier to manage Java-based projects.

OSRS Jagex Launcher Launchpad

**RLaunch GUI**

If your not comfortable with command line we went ahead and built a fully functional GUI that allows you to load up any of the popular provider clients such as squire, storm, tribot, and dreambot with a jagex launcher account. You can also load up multiple clients at once from different providers on the same machine with the RLaunchGui. If you have any questions feel free to reach out to our support in our discord server: [Join our Discord server](https://recoderz.org)


https://github.com/R3G3XR/RLaunch/releases/download/v1.0.0/RLaunchGui.exe

## Features

- **Easy Configuration:** Set essential environment variables for Java applications through command-line arguments.
- **Customizable Java and JAR Paths:** Specify custom paths for JDK and JAR files.
- **Flexible VM Arguments:** Customize Java Virtual Machine (JVM) arguments to optimize performance.
- **User-Friendly Help Command:** Access detailed usage instructions with a simple command.

## Getting Started

### Prerequisites

- Windows Operating System
- Java Development Kit (JDK) installed

### Installation

To use RLaunch, clone the repository to your local machine:

```bash
git clone https://github.com/R3G3XR/RLaunch.git
```

Navigate to the cloned directory:

```bash 
cd RLaunch
```

Compile the source code (ensure you have a C++ compiler installed):

```bash 
g++ -o RLaunch RLaunch.cpp
``` 

Or just open the sln in Visual Studios.

## Usage

Run RLaunch with the required options:

```bash 
RLaunch.exe [OPTIONS]
```

Available Options
```bash
--character-id [ID]: Sets the JX_CHARACTER_ID environment variable.
--display-name [NAME]: Sets the JX_DISPLAY_NAME environment variable.
--session-id [ID]: Sets the JX_SESSION_ID environment variable.
--jar-path [PATH]: Sets the path to the JAR file.
--jdk-path [PATH]: Sets the path to the JDK.
--vm-args [ARGS]: Sets the virtual machine arguments.
--help, -h: Displays the help message.
```

## Example

```bash
RLaunch.exe --character-id "123456" --display-name "User" --session-id "ABC123" --jar-path "C:\Path\To\JarFile.jar" --jdk-path "C:\Path\To\JDK\bin\java.exe" --vm-args "-Xmx1G -Xss2m"
```
