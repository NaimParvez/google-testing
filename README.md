# 🧪 Google Testing with GTest (C++)

This repository demonstrates how to write and run **unit tests in C++** using the **Google Test (GTest)** framework. It includes example programs, a shell script for building tests, and Google Test itself — no extra setup required!

---

## 📁 Project Structure

```
.
├── googletest/              # GoogleTest framework (already included)
├── build.sh                 # Bash script to compile test files
├── test_bignum.cpp          # Unit tests using GTest
├── test_bignum              # Executables
├── *.cpp                    # Practice programs
└── README.md
```

---

## 💻 Tested On

- ✅ Linux (Ubuntu/Debian)
- ⚠️ Not tested on Windows or macOS (but should work with some tweaks)

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/NaimParvez/google-testing.git
cd google-testing
```

> ✅ No need to install GoogleTest manually — it's already included in the `googletest/` folder.

---

## 🛠 Compile and Run Tests

### 2️⃣ Make `build.sh` Executable

```bash
chmod +x build.sh
```

### 3️⃣ Compile a Test File

```bash
./build.sh test_bignum.cpp
```

This will create an executable named `test_bignum`.

### 4️⃣ Run the Tests

```bash
./test_bignum
```

You'll see the test output in GTest's clean and readable format.

---

## 🔎 Function Being Tested

```cpp
int findBiggestNumber(int num1, int num2, int num3);
```

Test cases include:
- First, second, or third number being the biggest
- Negative numbers
- All numbers equal

---

## 📦 Requirements (for Linux)

Make sure the following are installed:

- `g++`
- `make` (optional but useful)
- `libpthread` (usually already included)

Install via:

```bash
sudo apt update
sudo apt install g++
```

---

## 🤝 Contributing

Feel free to fork this repo and add:
- More functions to test
- Better test coverage
- Build system improvements (e.g., using `CMake`)

---

## 📜 License

MIT License

---

Happy Testing! 🧪🧠
