// There is no Stack DS in JavaScript, but we can easily implement one using an Array.
// Recall that the lists have push and pop operations already. We can simply use them
// to implement a Stack
//
class Stack{
  constructor(){
    this.S = [];
  } //end-constructor

  // Push an object to the stack 
  push(item){this.S.push(item);}

  // Return the item at the top of the stack without removing it
  top(){
    if (this.S.length == 0) return null;
    else                    return this.S[this.S.length-1];
  } //end-top

  // Removes the item at the top of the stack and returns it     
  pop(){
    if (this.S.length == 0) return null;
    else                    return this.S.pop();
  } //end-pop
    
  // Returns true if the stack is empty, false otherwise
  isEmpty(){
    if (this.S.length == 0) return true;
    else                    return false;  
  } //end-isEmpty
} //end-Stack

// Test code for the stack        
S = new Stack();
console.log("Adding 1 to the Stack");
S.push(1);

console.log("Adding 2 to the Stack");
S.push(2);

console.log("Adding John to the Stack");
S.push("John");

console.log("Adding 4.5 to the Stack");
S.push(4.5);

console.log(`Item at the top of the stack: ${S.top()}`);
console.log(`Removing the item at the top of the stack: ${S.pop()}`);

console.log("Adding Alice to the Stack");
S.push("Alice");

console.log("Adding 10 to the Stack");
S.push(10);

str = "Popping off all stack elements: "
while (!S.isEmpty()){str += `${S.pop()}, `;}
console.log(str);
