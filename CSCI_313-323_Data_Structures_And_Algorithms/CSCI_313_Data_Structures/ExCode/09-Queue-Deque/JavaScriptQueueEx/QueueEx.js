// This is NOT a good implementation of Queue, but it works!
class Queue{
  constructor(){this.Q = [];}

  // Enqueue an object to the end of the Queue 
  add(item){this.Q.push(item);}

  // Return the item at the front of the queue without removing it
  front(){
    if (this.Q.length == 0) return null;
    else                    return this.Q[0];
  } //end-front
  
  // Removes the item at the front of the queue and returns it     
  remove(){
    if (this.Q.length == 0) return null;
    else                    return this.Q.shift(); 
  } //end-remove
  
  // Returns true if the queue is empty, false otherwise
  isEmpty(){
    if (this.Q.length == 0) return true;
    else                    return false;  
  } //end-isEmpty       
} //end-Queue 

// Test code for the Queue        
Q = new Queue();
console.log('Adding 1 to the Q');
Q.add(1);

console.log("Adding 2 to the Q");
Q.add(2);

console.log("Adding Ali to the Q");
Q.add("Ali");

console.log("Adding 4.5 to the Q");
Q.add(4.5);

console.log(`Item at the front of the Q: ${Q.front()}`);
console.log(`Removing the item at the front of the Q: ${Q.remove()}`);

console.log("Adding Veli to the Q");
Q.add("Veli");

console.log("Adding 10 to the Q");
Q.add(10);

str = "Removing all Q elements: ";
while (!Q.isEmpty()){str += `${Q.remove()}, `;}
console.log(str);

if (Q.isEmpty()) console.log("Q is empty");
else             console.log("Q is not empty");


