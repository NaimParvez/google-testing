
# Google Testing with GTest (C++)

This repository contains simple C++ programs and corresponding **unit tests** using the **Google Test framework (GTest)**.

## 📁 Project Structure

```
.
├── googletest/              # Cloned GoogleTest repo
├── build.sh                 # Bash script to compile tests
├── test_bignum.cpp          # Test cases using GTest
├── bignum / test_bignum     # Executable output
├── *.cpp                    # Other practice programs
└── README.md
```

## 🧪 Sample Test: `test_bignum.cpp`

This file contains unit tests for a function that finds the **biggest among three numbers**.

Example function tested:

```cpp
int findBiggestNumber(int num1, int num2, int num3);
```

GTest is used to check various conditions like:
- First/Second/Third is largest
- All values equal
- Handling negative numbers

## 🔧 Build and Run Tests

Make sure you have `g++` installed and the [GoogleTest](https://github.com/google/googletest) repo cloned inside this project under `googletest/`.

### ✅ Compile
Use the provided `build.sh` script:

```bash
chmod +x build.sh
./build.sh test_bignum.cpp
```

This will generate an executable `test_bignum`.

### ▶️ Run
```bash
./test_bignum
```

## 📦 Dependencies

- [Google Test](https://github.com/google/googletest)
- `g++` (C++ compiler)
- `pthread` library (linked automatically)

To clone GTest (if not already present):
```bash
git clone https://github.com/google/googletest.git
```

## 📜 License

This project is licensed under the MIT License. Feel free to use and extend it.

---

Happy testing! ✅
