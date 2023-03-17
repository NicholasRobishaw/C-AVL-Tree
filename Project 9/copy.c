#include "AVL_Tree_Utility.h"

  // https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

/*
Name: clearTree
Process: recursively removes all nodes from tree and returns memory to OS,
         uses post order traversal strategy
Function input/parameters: pointer to root/ working pointer (AvlTreeNodType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
AvlTreeNodeType *clearTree( AvlTreeNodeType *wkgPtr )
  {
  // use post order
  // when arriving at a node
  // check if current is NULL
  if( wkgPtr != NULL )
    {
    // try recurse left
    clearTree( wkgPtr->leftChildPtr );
    
    //  try recurse right
    clearTree( wkgPtr->rightChildPtr );
    
    // free current
  	free( wkgPtr );
    }
  // return sucess 	
  return NULL;	
  }

/*
Name: compareRoomNumbers
Process: compares room numbers as follows:
         - if left room number is greater than the right room number, 
         returns value greater than zero (not necessarily 1)
         - if left room number is less than the right room number, 
         returns value less than zero (not necessarily -1)
         - if room numbers are equal but one is longer, longer one is greater
         - otherwise, returns zero
Function input/parameters: two room numbers (as strings)
                           to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/---: none
Device output/---: none
Dependencies: isDigit
*/
int compareRoomNumbers( const char *roomNbrOne, const char *roomNbrTwo )
  {
  // variables	
  int sum, index = 0;	
  
  // add case for if one is NULL
  if( roomNbrOne == NULL)
    {
    return 0;
    }
  
  // iterate through string of numbers
  while( roomNbrOne[ index ] != NULL_CHAR &&
                               roomNbrTwo[ index ] != NULL_CHAR )	
    {           
    // check if roomNbrOne and roomNbrTwo is a digit
    if( isDigit( roomNbrOne[ index ] ) && isDigit( roomNbrTwo[ index ] ) )
      {
      // sub roomNbrOne and roomNbrTwo  
      sum = roomNbrOne[ index ] - roomNbrTwo[ index ];
    
      // if sum is not zero
      if( sum != 0)
        {
        // return sum
        return sum;    
        }  
      }
       
    // else iterate index and try next  
    index++;   
    }

  // if roomNbrOne is larger in length
  if( roomNbrOne[ index ] != NULL_CHAR && 
                                roomNbrTwo[index] == NULL_CHAR )
    {
    // return 1;
    return 1;
    }
	
  // other wise roomNbrTwo is larger in length
  else if( roomNbrOne[ index ] == NULL_CHAR && 
                                roomNbrTwo[index] != NULL_CHAR )
    {
    // return -1 
    return -1;
    }
    
  // return the sum
  return sum;
  }

/*
Name: copyString
Process: copies string from source to destination
Function input/parameters: source string (const char *)
Function output/parameters: destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyString( char *dest, const char *source )
  {
  // variables
  int index = 0;
  
  // copy string while not at NULL_CHAR
  while( source[index] != NULL_CHAR )
    {
    // set the character from srcStr at the index to the dest at the index
    dest[index] = source[index];
    
    // increment index
    index++;
    
    // set the next destIndex to NULL_CHAR
    dest[index] = NULL_CHAR;
    } 
  }

/*
Name: copyTree
Process: creates duplicate copy of given tree, allocates all new nodes,
         returns pointer to root of new tree or NULL if original tree was empty,
         uses pre order traversal strategy
Function input/parameters: tree root/working pointer (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: tree root of copied tree
                          or NULL as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
AvlTreeNodeType *copyTree( AvlTreeNodeType *rootPtr )
  {	 	
  // variables
  AvlTreeNodeType *newTree = NULL;
  
  // check if the current is not NULL
  if( rootPtr != NULL )
    {	   	
    // copy the current value into the new tree
    newTree = createTreeNodeFromNode( *rootPtr );
  
    // try to copy left chiild
    newTree->leftChildPtr = copyTree( rootPtr->leftChildPtr );
  
    // try to copy right child 
  	newTree->rightChildPtr = copyTree( rootPtr->rightChildPtr );
    }
  	
  // return pointer
  return newTree;
  }

/*
Name: createTreeNodeFromData
Process: captures data from individual data items, 
         dynamically creates new node,
         copies data, sets child pointers to NULL,
         and returns pointer to new node         
Function input/parameters: room number, building room, 
                           and class setup (const char *), capacity (int)
Function output/parameters: none
Function output/returned: pointer to new node as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, copyString
*/
AvlTreeNodeType *createTreeNodeFromData( const char *rmNumber, 
                   const char *buildingRm, const char *clsSetup, int capacity )
  {
  // variables
  // create the struct variables
  AvlTreeNodeType *newNode;
  
  // allocate the memeory for the treeNode
  newNode = (AvlTreeNodeType *)malloc( sizeof(AvlTreeNodeType) );
  
  // set child pointers to NULL
  newNode->leftChildPtr = NULL;
  newNode->rightChildPtr = NULL;
  
  // copy data into new node
  copyString( newNode->buildingRoom, buildingRm );
  copyString( newNode->roomNumber, rmNumber );
  copyString( newNode->classSetup, clsSetup );
  newNode->roomCapacity = capacity;
  
  // return pointer to the newly created node
  return newNode;	
  }

/*
Name: createTreeNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, sets child pointers to NULL, 
         and returns pointer to new node,
         one line of code         
Function input/parameters: node to be copied (const AvlTreeNodeType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
AvlTreeNodeType *createTreeNodeFromNode( const AvlTreeNodeType sourceNode )
  {	
  return createTreeNodeFromData( sourceNode.roomNumber, 
  sourceNode.buildingRoom, sourceNode.classSetup, sourceNode.roomCapacity );
  }

/*
Name: displayChars
Process: recursively displays a specified number of characters
Function input/parameters: number of characters (int), output character (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: characters displayed as specified
Dependencies: displayChars (recursively)
*/
void displayChars( int numChars, char outChar )
  {
  // check if we are out of values
  if( numChars > 0 )
    {
    // print the character
    printf( "%c", outChar );
    
    // recursivly call back
    displayChars( numChars - 1, outChar );       
    }       
  }

/*
Name: findBalanceFactor
Process: finds balance factor by subtracting
         height differences between left and right subtrees
Function input/parameters: pointer to current tree location (TreeNodeType *)
Function output/parameters: none
Function output/returned: difference between two subtree heights (int)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
int findBalanceFactor( AvlTreeNodeType *wkgPtr )
  {
  // variables
  int heightOfLeft, heightOfRight;    
      
  // find height of left subtree
  heightOfLeft = findTreeHeight( wkgPtr->leftChildPtr );
  
  // find height of right subtree
  heightOfRight = findTreeHeight( wkgPtr->rightChildPtr );
  
  // return balance
  return heightOfLeft - heightOfRight;
  }

/*
Name: findMax
Process: finds maximum between two values, returns larger
Function input/parameters: two values (int)
Function output/parameters: none
Function output/returned: larger of two values (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int findMax( int one, int other )
  {      
  // if one is bigger than other    
  if( one > other )
    {
    // return one    
    return one;    
    }    
  
  // else return other
  return other;    
  }

/*
Name: findTreeHeight
Process: recursively finds tree height from current node to bottom of tree
Function input/parameters: pointer to current tree location (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: -1 if empty tree, 0 if no subtrees,
                          max height of subtrees otherwise
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
int findTreeHeight( AvlTreeNodeType *wkgPtr )
  {
  // variables
  int height = 0, sumLeft = 0, sumRight = 0;
  
  // check if empty
  if( wkgPtr == NULL )
    {        
    // return -1
    return -1;
    }
  
  else
    {        
    //  try to recurse left
    sumLeft = findTreeHeight( wkgPtr->leftChildPtr );
    
    // try to recurse right 
    sumRight = findTreeHeight( wkgPtr->rightChildPtr ); 
    
    // find the maximun
    height = findMax( sumRight, sumLeft );
    
    // return the height plus current node
    return height + 1; 
    }      
  }

/*
Name: initializeTree
Process: returns NULL to set tree to empty
Function input/parameters: none
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: none
*/
AvlTreeNodeType *initializeTree()
  {
  // return NULL    
  return NULL;
  }

/*
Name: inOrderDisplay
Process: recursively iterates across tree using in order strategy,
         displays node values
Function input/parameters: pointer to current tree location (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: inOrderDisplay (recursively)
*/
void inOrderDisplay( AvlTreeNodeType *wkgPtr )
  {  
  // check if wkgPtr is not NULL
  if( wkgPtr != NULL )
    {    	
    // recurse left
    inOrderDisplay( wkgPtr->leftChildPtr );
    
    // print current
    printf( "%s, ", wkgPtr->roomNumber );
    
    // recurse right    
    inOrderDisplay( wkgPtr->rightChildPtr );
    }   
    
  }

/*
Name: insert
Process: recursively finds location to insert node, inserts node,
         then follows recursion back up tree to implement balancing,
         does not allow duplicate entries
Function input/parameters: pointer to current tree location (AvlTreeNodeType *),
                           room number, building room data, class setup (char *)
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: actions displayed as function progresses
Dependencies: createDataNode, compareRoomNumbers, findBalanceFactor,
              insert (recursively), printf, rotateLeft, rotateRight
*/
AvlTreeNodeType *insert( AvlTreeNodeType *wkgPtr, 
                     char *rmNmbr, char *bldgRm, char *clsSetup, int capacity )
  { 
  // variables 
  int sum = 0, balance = 0, space = 2;
   
  // check for current node NULL
  if( wkgPtr == NULL )
    {
    // return a new created node
    wkgPtr = createTreeNodeFromData( rmNmbr, bldgRm, clsSetup, capacity );
    }
  
  else
    {         
    // calculate sume
    sum = compareRoomNumbers( wkgPtr->roomNumber, rmNmbr ); 
      
    // check to see if the new value is less than the current node
    if( sum > 0 ) 
      {
      // make the recursive call to the left child
      // and assign it to the current node's left child
      wkgPtr->leftChildPtr = insert( wkgPtr->leftChildPtr, 
                       rmNmbr, bldgRm, clsSetup, capacity ); 
      }
    
    // otherwise, check to see if the new value, 
    // is greater than the current node data
    else if( sum < 0)  
      {
      // make the recursive call to the right child
      // and assign it to the curren node's right child
      wkgPtr->rightChildPtr = insert( wkgPtr->rightChildPtr, 
                         rmNmbr, bldgRm, clsSetup, capacity );
      }  
    
    // follow recursion back up tree to implement balancing
    balance = findBalanceFactor( wkgPtr );    
    
    // if the balance is greater than one and the new data is less than its parent data, 
    // there is a Left Left condition which will require right rotation
    if( balance > 1 && compareRoomNumbers( rmNmbr, 
                               wkgPtr->roomNumber ) < 0 )  
      {
      // display output message    
      displayChars( spaces, SPACE );
      printf( "identified: Left Left Case\n" );    
      displayChars( spaces+spaces, SPACE );
      printf( "- Rotating Right\n" );
          
      // rotate right
      wkgPtr = rotateRight( wkgPtr ); 
      }
  
    // If the balance factor is less than negative one, 
    // and the new data is greater than its parent data,
    // there is a Right Right condition which will require a left rotation
    else if( balance < -1 && compareRoomNumbers( rmNmbr, 
                                wkgPtr->roomNumber ) > 0 )  
      {
      // display output message
      displayChars( spaces, SPACE );
      printf( "identified: Right Right Case\n" );   
      displayChars( spaces+spaces, SPACE );
      printf( "- Rotating Left\n" );  
          
      // rotate left
      wkgPtr = rotateLeft( wkgPtr ); 
      }  
    
    // If the balance factor is greater than one, 
    // and the new data is greater than its parent data, 
    // there is a Left Right condition which will require 
    // a left rotation and then a right rotation
    else if( balance > 1 && compareRoomNumbers( rmNmbr, 
                               wkgPtr->roomNumber ) > 0 )  
      {
      // display output message
      displayChars( spaces, SPACE );
      printf( "identified: Left Right Case\n" );     
      displayChars( spaces+spaces, SPACE );
      printf( "- Rotating Left\n" );
      displayChars( spaces+spaces+spaces, SPACE );
      printf( "- Rotating Right\n" ); 
          
      // rotate left
      wkgPtr = rotateLeft( wkgPtr );  
    
      // rotate right
      wkgPtr = rotateRight( wkgPtr ); 
      }  
    
    // If the balance factor is less than negative one, 
    // and the new data is less than its parent data, 
    // there is a Right Left condition which will require 
    // a right rotation and then a left rotation
    else if( balance < -1 && compareRoomNumbers( rmNmbr, 
                                wkgPtr->roomNumber ) < 0 )  
      {
      // display output message
      displayChars( spaces, SPACE );
      printf( "identified: Right Left Case\n" );     
      displayChars( spaces+spaces, SPACE );
      printf( "- Rotating Right\n" );
      displayChars( spaces+spaces+spaces, SPACE );
      printf( "- Rotating Left\n" );     
          
      // rotate right
      wkgPtr = rotateRight( wkgPtr );  
    
      // rotate left
      wkgPtr = rotateLeft( wkgPtr );  
      }  

    }
  return wkgPtr;    
  }

/*
Name: isDigit
Process: reports if character provided is a character digit
Function input/parameters: test character (char)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isDigit( char testChar )
  {
  // return true if digit otherwise return false	
  return testChar >= '0' && testChar <= '9';
  }

/*
Name: isEmpty
Process: reports if tree is empty, using one line of code
Function input/parameters: pointer to current root node (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( AvlTreeNodeType *rootPtr )
  {
  // check if pointer is NULL	
  return rootPtr == NULL;	
  }

/*
Name: rotateLeft
Process: conducts left rotation by manipulation of given pointer
Function input/parameters: pointer to given subtree to rotate
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: rotation action displayed  ("- Rotating Left")
Dependencies: printf
*/
AvlTreeNodeType *rotateLeft( AvlTreeNodeType *oldParentPtr )
  {   
  // make temp ptr
  AvlTreeNodeType *tempPtr;
  
  // set temp ptr to old paretnes left child
  tempPtr = oldParentPtr->rightChildPtr;
  
  // set the paretns right to the temps left
  oldParentPtr->rightChildPtr = tempPtr->leftChildPtr;
  
  // set tempPtrs right child to oldParents left child
  tempPtr->leftChildPtr = oldParentPtr;
  
  // return tempPtr
  return tempPtr;   
  }

/*
Name: rotateRight
Process: conducts right rotation by manipulation of given pointer
Function input/parameters: pointer to given subtree to rotate
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: rotation action displayed  ("- Rotating Right")
Dependencies: printf
*/
AvlTreeNodeType *rotateRight( AvlTreeNodeType *oldParentPtr )
  {    
  // make temp ptr
  AvlTreeNodeType *tempPtr;
  
  // set temp ptr to old paretnes left child
  tempPtr = oldParentPtr->leftChildPtr;
  
  // set the paretns right to the temps left
  oldParentPtr->leftChildPtr = tempPtr->rightChildPtr;
  
  // set tempPtrs right child to oldParents left child
  tempPtr->rightChildPtr =oldParentPtr;
  
  // return tempPtr
  return tempPtr;
  }
 

/*
Name: search
Process: recursively searches tree for specified data using room number key
Function input/parameters: pointer to working subtree (AvlTreeNodeType *),
                           room number (const char *)
Function output/parameters: none
Function output/returned: pointer to found node (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: search (recursively)
*/
AvlTreeNodeType *search( AvlTreeNodeType *wkgPtr, const char *roomNumber )
  {
  // make sure not NULL
  if( wkgPtr != NULL )
    {  
    //variables
    int sum = 
      compareRoomNumbers( wkgPtr->roomNumber , roomNumber );
    
    // check for search val less than 0
    if( sum < 0 )
      {
      // try right
      wkgPtr = search( wkgPtr->rightChildPtr, roomNumber ); 	
      }
  
    // check for val greater than 0
    if( sum > 0 )
      {
      // try left
      wkgPtr = search( wkgPtr->leftChildPtr, roomNumber );         
      }
      
    return wkgPtr;  
    }
 
  // return NULL
  return NULL;
  }



