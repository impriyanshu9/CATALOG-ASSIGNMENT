# CATALOG-ASSIGNMENT

Running the C++ Program
Prerequisites
1.C++ Compiler: Make sure you have a C++ compiler installed, such as g++. You can install it via:

Windows: Use MinGW or install through WSL (Windows Subsystem for Linux).
Linux: Install using your package manager. For example, on Ubuntu, run:
bash
sudo apt update
sudo apt install g++
macOS: Install Xcode Command Line Tools:
bash
xcode-select --install

2.JSON Library: The program uses the jsoncpp library for JSON parsing. You need to install it:

Using vcpkg (recommended for Windows):
bash
git clone https://github.com/microsoft/vcpkg.git
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install jsoncpp
On Linux:
bash
sudo apt-get install libjsoncpp-dev

3.Program Files
Make sure you have the following files in your project directory:
main.cpp (your C++ source code)
input.json (your input JSON file)
Building the Program
Open a terminal (or command prompt).
Navigate to the directory where your main.cpp file is located.
Compile the program using the following command:
bash
g++ -o my_program main.cpp -ljsoncpp
This command creates an executable named my_program.

4.Running the Program
Execute the compiled program with:

bash
./my_program
(On Windows, you would use my_program.exe)

The program will read from input.json, decode the values, and output the constant term (c).

************************************************


Approach Summary
Input Reading:

Read data from a JSON file that contains key-value pairs representing points in various numerical bases. Each point consists of a base and a value.
Data Decoding:

For each point in the JSON, convert the value from its specified base to decimal using a decoding function. Store these values along with their corresponding indices (used as x-coordinates) in a vector of pairs.
Point Selection:

From the decoded points, select the first k points (as specified in the JSON) for interpolation. This selection is crucial for performing Lagrange interpolation, which requires k data points.
Lagrange Interpolation:

Implement the Lagrange interpolation formula to compute the constant term (the polynomial value at x = 0). This involves calculating the contribution of each point to the polynomial based on its x and y values.
Output the Result:

Finally, print the computed constant term, which represents the value of the polynomial evaluated at x = 0.
Key Concepts
Lagrange Interpolation: A mathematical technique to construct a polynomial that passes through a given set of points.
Base Conversion: The process of converting numbers from various bases to a common base (decimal) for mathematical operations.
Dynamic Storage: Using vectors to handle a flexible number of input points, demonstrating efficient memory management in C++.
