# Blockchain

## Identifying Information: 
1. Full name: Kihoon Yoo
2. Student ID: 2480883
3. Chapman Email: kiyoo@chapman.edu
4. Course number and section: CPSC-350-04
5. Assignment or exercise number: PA4: Blockchain Ledger

## Project Description
This project is a C++ simulation of a basic blockchain ledger, where each block contains an index, timestamp, transaction data, and cryptographic hashes linking it to the previous block. The program allows users to add new blocks, validate the blockchain's integrity, and save/load the blockchain from files. A simple custom hash function is used, and no STL containers are allowed—only primitive data structures like arrays.

## Key Features
- Block Class: Each block stores an index, timestamp, transaction data, previous hash, and its own computed hash.
- Blockchain Class: Manages a linked sequence of blocks, starting with a genesis block and supporting new block additions.
- Simple Custom Hash Function: Generates hashes by summing ASCII values of block content and converting to hexadecimal.
- Blockchain Validation: Verifies the integrity of the blockchain by checking that each block's previous hash matches the actual hash of the previous block.
- File I/O Operations: Save the blockchain to a file and load an existing blockchain from a file.
- Console-Based User Interface: Add new blocks, display the blockchain, validate the chain, save to file, load from file, and exit.

## Files
1. Block.cpp
2. Block.h
3. Blockchain.cpp
4. Blockchain.h
5. Main.cpp
6. UserInterface.cpp
7. Userinterface.h
8. myBlockChain.txt
9. blockchain
10. README.MD

## Known Error 
- There are no known errors in this program.

## References
- https://www.w3schools.com/CPP/cpp_files.asp
- https://www.w3schools.com/dsa/dsa_theory_hashtables.php
- https://www.w3schools.com/cpp/cpp_date.asp
- https://www.w3schools.com/dsa/dsa_data_hashsets.php
- Received debugging help from the Chapman TLC

## Instructions for compiling
- To compile: g++ -o blockchain main.cpp Block.cpp Blockchain.cpp UserInterface.cpp
- To run: ./blockchain
