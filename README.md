# try-c
This is my TUTORIAL project for C.

## Requirements

- gcc or clang
- make

## Add example

```sh
$ make init-example NAME="the/example/directory"
$ tree the
the
└── example
    └── directory
        ├── main.c
        └── Makefile

2 directories, 2 files
```

## Run

1. Go to the directory of the sample you want to run.
2. run make

### Example

```sh
$ cd basic/01.helloworld
$ make run
```

or

```sh
$ make -C basic/01.helloworld run
```

### Makefile template

- https://gist.github.com/devlights/16a96258d3859b9d25876a536d07d4dd
