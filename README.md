
# Backtrace
## Backtrace is a project designed to obscure and ultimately hide a program's stack trace, enhancing security and preventing reverse engineering.
## Installation

To install Backtrace, clone the repository using git with the --recurse-submodules option to ensure all submodules are cloned as well.

## Clone the Repository:
```bash
git clone --recurse-submodules --depth 1 https://github.com/logiclabsacademy/backtrace.git
```

Navigate to the backtrace directory:
```bash
cd backtrace
```


## Building the Project

The project is built using gcc with specific compiler flags and adheres to the C2x standard. Below are the steps to build and clean the project locally.
Building

To build the project, run the following command in the project directory:
```bash
make
```


This will compile the source files and generate the executable in the bin directory.
## Cleaning

To clean the build artifacts, run:
```bash
make clean
```
