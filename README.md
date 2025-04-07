# Parameter Dumper

A simple C++ utility that dumps all command-line parameters to a text file.

## Building the Project

### Option 1: Using PowerShell Script (Recommended for Windows)
Simply run the PowerShell build script:
```powershell
.\build.ps1
```

### Option 2: Manual Build
1. Create a build directory:
```bash
mkdir build
cd build
```

2. Generate build files with CMake:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

## Usage

Run the executable with any parameters:
```bash
./param_dumper arg1 arg2 "arg 3" --flag
```

The program will create a text file named `param_dump_YYYY-MM-DD_HH-MM-SS.txt` in the same directory, containing all the parameters passed to the executable.

## Output Format

The output file will contain:
- Timestamp of the dump
- Total number of parameters
- List of all parameters with their indices 