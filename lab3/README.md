# Hash Hash Hash
TODO introduction
This is a serial hash table implementation and two concurrent hash table implementation

## Building
```shell
make
```
## Running
```shell
./hash-table-tester -t 8 -s 50000

Output:
Generation: 309,923 usec
Hash table base: 3,266,216 usec
  - 0 missing
Hash table v1: 6,128,329 usec
  - 0 missing
Hash table v2: 6,739,487 usec
  - 0 missing

TODO how to run and results
```

## First Implementation
In the `hash_table_v1_add_entry` function, I added TODO

So this implementation protects the data structure making it so that only one thread can access the hash table at a time without any problems.

### Performance
```shell
TODO how to run and results
```
./hash-table-tester -t 8 -s 50000                 130 ↵
Generation: 286,488 usec
Hash table base: 3,156,997 usec
  - 0 missing
Hash table v1: 6,409,727 usec
  - 0 missing
Hash table v2: 4,867,065 usec
  - 0 missing

Version 1 is a little slower/faster than the base version. As TODO

## Second Implementation
In the `hash_table_v2_add_entry` function, I TODO

This implementation separates the has table into smaller parts which allows multiple threads to access the different buckets without waiting for each other.

### Performance
```shell
TODO how to run and results
```
./hash-table-tester -t 8 -s 50000                 130 ↵
Generation: 286,488 usec
Hash table base: 3,156,997 usec
  - 0 missing
Hash table v1: 6,409,727 usec
  - 0 missing
Hash table v2: 4,867,065 usec
  - 0 missing

TODO more results, speedup measurement, and analysis on v2

## Cleaning up
```shell
TODO how to clean
make clean

```