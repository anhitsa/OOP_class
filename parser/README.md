# Command Parser Project

## Overview

This Parser is a C++ program that allows users to input commands and perform various mathematical operations. This project demonstrates how to parse commands, execute mathematical operations, and handle errors using C++.

## Features

- Parse user commands from input streams.
- Perform mathematical operations such as addition, subtraction, multiplication, division, power, and square root.
- Handle invalid commands and provide error messages.
- Exit the program by entering the "quit" command.

## Components

The project is structured into several components:

- CommandParser: Parses user commands and extracts operation type and operands.
- CommandHistory: Contains saved commands. Adds and removes elements from the history of commands.
- OperationFactory: Creates specific operation objects based on the parsed command.
- Operation: Defines a common interface for all operations.
- AdditionOperation, SubtractionOperation, and other operation types: Inherit from Operation and implement specific operations.
- CommandExecutor: Executes parsed commands using the OperationFactory.
- Controller: Manages the main program flow, including user input and command execution.

## Getting Started

1. Clone the repository:

   ```bash
   git clone <repository-url>
2. Build the project using a C++ compiler (e.g., g++ or clang++):
   ```bash
   clang++ -g -I/path_to_parser path_to_parser/**/*.cpp path_to_parser/*.cpp -o /path_to_parser/main -std=c++20
3. Run the executable:
   ```bash
   ./main
4. Enter commands and see the results.


## Usage

- Enter mathematical commands, e.g., "add 3 4 5 6", "sub 10 2", "pow 2 6", etc.
- To write a command in history later to be executed, type 'create' befor a command, e.g. "create add 3 4 5 6"
- Use "run" to execute all the commands in history.
- Use "quit" to exit the program.

## Example
 ```bash
    Enter a command: add 3 4 5 6
    Result: 18

    Enter a command: sub 10 2
    Result: 8

    Enter a command: pow 2 6
    Result: 64

    Enter a command: addbb 2 3 4 
    Error: Not a valid operationType

    Enter a command: create add 3 4 5 6

    Enter a command: create sub 10 2

    Enter a command: run
    add 3 4 5 6 Result: 18
    sub 10 2 Result: 8

    Enter a command: quit
    quitting ...