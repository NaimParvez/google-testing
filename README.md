# 🧪 Google Testing with GTest (C++)

This repository demonstrates how to use [GoogleTest](https://github.com/google/googletest) to write and run unit tests for C++ programs. It includes an example test for a function that finds the largest of three numbers.

---

## 📁 Repository Contents

```
google-testing/
├── example.cpp       # Example test file using GoogleTest
├── build.sh          # Your build script (you will create this)
├── googletest/       # Auto-generated when you build for the first time
├── test_bignum.cpp   # Unit tests using GTest
├── *.cpp             # Practice programs
└── README.md
```

---

## 🚀 How to Use This Project

### 1. Clone This Repository

```bash
git clone https://github.com/NaimParvez/google-testing.git
cd google-testing
```

---

### 2. Create the Build Script

Create a file named `build.sh` in the root of the repo, and paste the following code into it:

```bash
#!/bin/bash

# Check if at least one argument (source file) is provided
if [ $# -eq 0 ]; then
    echo 'Usage: ./build.sh <source_file.cpp> [output_file]'
    exit 1
fi

# Set output file
output=$(basename "$1" .cpp)
if [ $# -eq 2 ]; then
    output=$2
fi

# GoogleTest directory setup
GTEST_DIR="googletest"
GTEST_LIB="$GTEST_DIR/build/lib/libgtest.a"

# Clone and build googletest if not already done
if [ ! -f "$GTEST_LIB" ]; then
    echo "GoogleTest not found. Cloning and building GoogleTest..."
    git clone https://github.com/google/googletest.git -b release-1.12.0
    cd "$GTEST_DIR" || exit
    mkdir -p build
    cd build || exit
    cmake .. -DBUILD_GMOCK=OFF
    make
    cd ../../
else
    echo "GoogleTest already built. Skipping clone/build..."
fi

# Compile the program
echo "Compiling $1..."
g++ "$1" "$GTEST_LIB" -lpthread -I "$GTEST_DIR/googletest/include" -o "$output"

echo "Build complete. Output: $output"
```

Then make the script executable:

```bash
chmod +x build.sh
```

---

### 3. Build and Run the Test

```bash
./build.sh example.cpp
./example
```

- The first time you run it, the script will:
  - Clone GoogleTest (release-1.12.0)
  - Build GoogleTest from source
  - Compile your C++ test file

---

## 📦 Requirements

- `g++` (C++ compiler)
- `pthread` (POSIX thread library)

### 🧪 Example Test Case

The included `example.cpp` tests the function:

```cpp
int findBiggestNumber(int a, int b, int c);
```

using multiple unit test cases with GoogleTest.

---

## 💡 Notes

- Tested on **Linux** (Ubuntu/Debian-based systems).
- Only needs to download GoogleTest once.
- You can replace `example.cpp` with any test file you write.

---

## 📎 Manual GoogleTest Setup (Optional)

If you prefer to manually clone and build GoogleTest:

```bash
git clone https://github.com/google/googletest.git -b release-1.12.0
cd googletest
mkdir build
cd build
cmake .. -DBUILD_GMOCK=OFF
make
```

The resulting static libraries will be in `googletest/build/lib/`.

---

Feel free to fork this repo and use it as a base for your own C++ testing projects!
