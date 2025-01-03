# CircularHashTable

## Info
Languages C++.  
Build tool CMake.  
Testing tool Catch2.  

## Description
Circular hash table implemented as a map<char, Entity>. Entity is a structure with status and item members.  
Table is circular and keys are in range 'a' - 'z', total 26.  
Strings are added to the table based on their hash.  
If collision occurs next available slot is taken.  
Deleted slots are never used again.  

## Testing
Building is done with CMake, whereas testing is done with Catch2.  