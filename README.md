## Setup

You need the following stuff setup

- [Cmake](https://cmake.org/download)
- [Mingw](https://www.mingw-w64.org) - I am using GCC to build, the project, you can choose another compiler by changing the `generator` in the `CMakePresets.json`
- [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started)

## Running

Install all the required packages

```bash
make prepare
```

Build the application

```bash
make @build
```

Build and run the application

```bash
make run
```
