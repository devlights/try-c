# try-c
my clang tutorial (C11)

[![CodeFactor](https://www.codefactor.io/repository/github/devlights/try-c/badge)](https://www.codefactor.io/repository/github/devlights/try-c)
[![Gitpod Ready-to-Code](https://img.shields.io/badge/Gitpod-Ready--to--Code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/devlights/try-c) 

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
