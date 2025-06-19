# 🔍 VKInfo — Metrics Scraping Library

Asyncronous metrics scraper library written in C++ <br>
(uses Qt5 for showcasing performance)

## Screenshots

### Main Window

![Main Window](/img/window.png)

### Metrics Visualization

![Metrics Visualization](/img/metrics.png)


---

## 📁 Project Structure

VKInfo/ <br>
├── VKInfoLib/ # Core logic as a shared library <br>
├── VKInfoDriver/ # Executable that uses VKInfoLib <br>
├── VKInfoTest/ # Google Test-based unit tests <br>
├── bin/ # Binaries of VKInfoDriver <br>
├── lib/ # Libraries: GTest, VKInfoLib <br>
├── build.sh # Builds the project using CMake <br>
├── run.sh # Runs the VKInfoDriver binary <br>
└── test.sh # Runs unit tests with Google Test <br>

---

## ⚙️ Dependencies

This project is intended to run on **Debian-based Linux distributions** and requires the following:

- G++ compiler `>= 12.2.0`
- [CMake](https://cmake.org/) `>= 4.0.3`
- [GoogleTest](https://github.com/google/googletest) `1.17`
- [Doxygen](https://www.doxygen.nl/) `1.14.0`
- [gcov / lcov](https://ps-group.github.io/cxx/coverage_gcc) for code coverage
- [Qt5](https://www.qt.io/try-qt) `5.15.8`

---

## Build Instructions

To build the entire project (library, driver, and tests), simply run the provided shell script:

```bash
./build.sh
```

---

## Usage Instructions

Once built, you can run the driver interface:

```bash
./run.sh
```

Or you can **Test** the library:

```bash
./test.sh
```

Or you can see test coverage (works after running tests):

```bash
./cov.sh
```

---