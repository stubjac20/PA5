# PA5 - Amazon Inventory REPL (Sorting Upgrade)

Built on PA4. This version adds sorting for the `listInventory` command.

## Commands
`find <id>` prints product info
`listInventory <category>` default sort by price (insertion sort, ascending)
`listInventory <category> desc` insertion sort, descending
`listInventory <category> merge` merge sort, ascending
`listInventory <category> merge desc` merge sort, descending
`:help` list commands
`:quit` exit

# insertionSort (default)
Easy to use for small data
Slower on larger category lists

# mergeSort
Faster with bigger lists
A bit more code overhead but works well

Sorting works using `std::vector<Product*>` and lambda comparators on price.

# Files Added for PA5

`sorts.h` my own insertion sort + merge sort
updated `InventorySystem.cpp/.h` handles sort logic
updated `main.cpp` parses new REPL command formats

# How to Run

```bash
make
./mainexe
