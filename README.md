
# Inverted Search in C

## Project Description

Inverted Search is a file indexing and searching application developed using the C programming language.

The project creates an inverted index by reading multiple text files, extracting words, and storing their occurrences in a Hash Table using a Linked List data structure.

It allows users to search for a word and identify the files in which it appears, along with the number of occurrences in each file.

## Features

- Create a database from multiple text files.
- Validate input files before processing.
- Store words using a Hash Table.
- Handle collisions using Linked Lists.
- Display the complete database.
- Search for a specific word.
- Update the database using additional files.
- Save the database into a file.
- Maintain word frequency and file-wise occurrence counts.

## Technologies Used

- Programming Language: C
- Data Structures:
  - Hash Table
  - Singly Linked List
- Concepts:
  - Pointers
  - Structures
  - Dynamic Memory Allocation
  - File Handling
  - String Manipulation

## Data Structure

The project uses:

1. Hash Table – Stores words based on their first character.
2. Main Node – Stores each unique word and the number of files containing it.
3. Sub Node – Stores filenames and the occurrence count of each word in those files.

## Project Structure

```text
Inverted_Search/
│
├── main.c
├── create.c
├── display.c
├── read_validate.c
├── search.c
├── update.c
├── save.c
├── inverted_search.h
├── makefile
├── file1.txt
├── file2.txt
└── README.md
```

## Compilation

Compile the project using the Makefile:

```bash
make
```

Alternatively, use GCC:

```bash
gcc *.c -o inverted
```

## Execution

```bash
./inverted
```

## Operations

1. Create Database
2. Display Database
3. Search Word
4. Update Database
5. Save Database
6. Exit

## Learning Outcomes

- Gained practical experience in C programming.
- Understood Hash Table implementation.
- Improved knowledge of Linked Lists.
- Practiced file handling and string operations.
- Learned dynamic memory allocation.
- Improved problem-solving and debugging skills.

## Author

Arjun K C

## GitHub Repository

https://github.com/Arjun-124/Inverted_Search
