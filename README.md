# Lab 9: Hash Table Implementations

This lab includes two hash table implementations in C++:

- `hash_lp`: linear probing
- `hash_chn`: chained hashing

Both versions support inserting, finding, erasing, and reporting the number of records.

## Files

- `hash_lp.h` / `hash_lp.cpp`: linear probing table
- `hash_chn.h` / `hash_chn.cpp`: chained hashing table
- `drv_hwlp.cpp`: test driver for the linear probing version
- `drv_hwch.cpp`: test driver for the chained hashing version

## Build

Use a C++ compiler such as `g++`.

Linear probing:

```bash
g++ -std=c++17 drv_hwlp.cpp hash_lp.cpp -o hwlp.exe
```

Chained hashing:

```bash
g++ -std=c++17 drv_hwch.cpp hash_chn.cpp -o hwch.exe
```

## Run

Linear probing:

```bash
./hwlp.exe
```

Chained hashing:

```bash
./hwch.exe
```

On Windows PowerShell, run the executables with:

```powershell
.\hwlp.exe
.\hwch.exe
```

## Menu Commands

- `I` - insert a record
- `E` - erase a record
- `F` - find a record
- `S` - show the number of records
- `Q` - quit

## Notes

- The linear probing version uses tombstones for deleted entries so searches continue past erased slots.
- The chained hashing version removes matching nodes from the linked list in each bucket.


