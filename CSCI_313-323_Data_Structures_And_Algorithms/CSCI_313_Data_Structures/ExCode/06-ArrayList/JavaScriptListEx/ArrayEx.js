// JavaScript only has array objects, and methods to manipulate arrays. 
// Arrays correspond to ArrayList/LinkedList in other programming languages.
// Unlike strongly-typed PLs, JS arrays can store items of different types
//
function PrintListItems(L){
  str = "List items: [";
  L.forEach(item => {str = str + item + ", ";})
  console.log(str + "\b\b]");
} //end-PrintListItems

A = [5, 4, 9, 1, 3]
console.log(`A = [${A}]`);
console.log(`Length of the list is ${A.length}`)

console.log(A)
PrintListItems(A);

// push(obj): Append the specified obj to the end of the array
// unshift(obj): Insert an object at the beginning of the array
//
A.push(20)
A.push(15)
A.unshift(12)
PrintListItems(A);

// pop(): Removes and returns the last item in the list
// shift(): Removes and returns the first item in the list
//
console.log(`Removing the last item from the list: ${A.pop()}`);
console.log(`Removing the first item from the list: ${A.shift()}`);
PrintListItems(A);

// Add lists together
B = [50, 51, 60, 55];
C = A.concat(B);       // Concatenates A and B and returns a new Array
PrintListItems(B);
PrintListItems(C);

// WARNING: This does not make a copy of the list. This is just a pointer assignment
D = A;        // Just points D to the same list
A[0] = 33;
D[0] = 44;
PrintListItems(A);
PrintListItems(D);

// Find the index of 1
console.log(`Index of item 1 is: ${A.indexOf(1)}`);

// sort: Sorts the list in ascending order
D.sort((a, b)=>{return a-b;});
PrintListItems(D);

