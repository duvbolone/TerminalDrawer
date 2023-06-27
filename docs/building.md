# Building the program

TerminalDrawer does not provide the binaries by default, so you'll have to built the program youself.

## Using CMAKE

Assuming you have [CMAKE](https://cmake.org/) installed you simply run the following commands:

```sh
mkdir build
cd build
cmake .. && make
```

This should successfully build the program, and make it available at `build/TerminalDrawer`.