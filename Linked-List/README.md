# Linked List Data Structure

### Example

```cpp
#include <iostream>
#include "LinkedList.h"

// Create a new Linked List with strings.
LinkedList<std::string> list("I am a string");

// Push new strings
list.add("I am another string");

// Search for a node with the specific string. Returns nullptr if not found.
Node<std::string> *searchedNode = list.search("I am another string");

// Check if it has been found and log the data.
if (searchedNode)
{
    std::cout << searchedNode->getData() << std::endl;
}

// Get the id of that Node and delete it. The function returns true if delete was successful or false if it wasn't.
long int id = searchedNode->getID();
bool result = list.deleteNode(id);

// Check if delete was successful
if (result)
{
    std::cout << "The Node has been deleted successfully!" << std::endl;
}
```

### Output

> \> I am another string
> 
> \> The Node has been deleted successfully!
