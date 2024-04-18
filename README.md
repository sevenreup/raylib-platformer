## Setup

You need the following stuff setup

- [Cmake](https://cmake.org/download)
- [Make](https://www.gnu.org/software/make)
- [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started)

I am using GCC to build, the project, you can setup [Mingw](https://www.mingw-w64.org) or choose another compiler by changing the `generator` in the `CMakePresets.json`

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
