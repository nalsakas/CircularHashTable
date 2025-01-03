# CircularHashTable

## Info
Languages C++.  
Build tool CMake.  
Testing tool Catch2.  

## Description
Circular hash table implemented as a map<char, Entity>.  
Keys are char, and values are Entity structure who got status and item members.  
Status of a cell is either "never used", "occupied" or "tombstone".  
"never used" ones are free to be filled. "occupied" ones already taken.   
"tombstone" ones represent deleted ones. Deleted ones remains in table and their place never used again.  
Table is circular and keys are in range 'a' - 'z', total keys length is 26 and fixed.  
Strings are added to the table based on their hash.  
If collision occurs next available slot is taken until all slots are visited.   
That means this table is doomed to fill up. After filled up, it can never be used again.  

## Testing
Building is done with CMake, whereas testing is done with Catch2.  
