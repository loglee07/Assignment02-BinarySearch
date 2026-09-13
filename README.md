# Assignment 02: Binary Search and Recursive Analysis

## Description

This C++17 program compares linear search, iterative binary search, and recursive binary search. Each method returns the target’s index or `-1` when the target is missing. The program also counts how many elements each method checks.

## Tests

The program searches for:

* The first element
* The last element
* The middle element
* A missing value below the range
* A missing value inside the range

## Complexity

* Linear search: O(n) time and O(1) extra space
* Iterative binary search: O(log n) time and O(1) extra space
* Recursive binary search: O(log n) time and O(log n) extra space

## How to Run

Compile:

`g++ -std=c++17 main.cpp -o binary_search`

Run:

`./binary_search`

## Files

* `main.cpp` contains all search functions and tests.
* `README.md` explains the project and how to run it.

## Sources and Collaboration

The assignment instructions were provided through the course. ChatGPT was used for explanations, code organization, and debugging help.
