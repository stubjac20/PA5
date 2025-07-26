
There are two supported commands to search amazon inventory:
- `find <inventoryid>`: looks up a product by its unique ID and prints all details
- `listInventory <category_string>`: prints the IDs and names of all products in the given category

The app loads data from a CSV file, parses it, and stores products in two custom data structures: one hash table for lookup by ID, and one hash table for category-based lookup.

## Commands

`find <id>` → prints product details
`listInventory <category>` → shows all products in that category
`:help` → shows command list
`:quit` → exits

Built a hash table (no STL) using linked list chaining
two tables: 
one for product ID → Product
one for category → list of Product pointers

Categories split by `|`
If no category, set to `"NA"