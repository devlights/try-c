# try-c
This is my TUTORIAL project for C.

[![CodeFactor](https://www.codefactor.io/repository/github/devlights/try-c/badge)](https://www.codefactor.io/repository/github/devlights/try-c)
[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/devlights/try-c) 

## Environment

```shell
$ cc --version | head -n 1
cc (Ubuntu 8.3.0-6ubuntu1) 8.3.0
$ c++ --version | head -n 1
c++ (Ubuntu 8.3.0-6ubuntu1) 8.3.0
$ gcc --version | head -n 1
gcc (Ubuntu 8.3.0-6ubuntu1) 8.3.0
$ cmake --version | head -n 1
cmake version 3.16.2
```

## Editor

- JetBrains CLion
- VSCode

## Build

```shell script
$ make
$
```

## Show avaiable examples

```shell script
$ make list
$
```

## Run

```shell script
$ make run example=example name
$
```

### e.g: Run helloworld example

```shell script
$ make run example=helloworld
$
```

## VSCode Settings

- ```.vscode/c_cpp_properties.json```

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64",
            "compileCommands": "${workspaceFolder}/cmake-build-debug/compile_commands.json"
        }
    ],
    "version": 4
}
```

## Reference

- [ソースコードの分割](https://programming.pc-note.net/c/header.html)
