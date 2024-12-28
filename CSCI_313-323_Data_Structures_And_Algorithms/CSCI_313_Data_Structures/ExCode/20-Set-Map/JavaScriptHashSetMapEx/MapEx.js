// Maps in JavaScript are unique "key/value" pairs, and correspond to HashMap in other Programming Languages
// When we iterate over a map object, the key values are returned in the order they are inserted.
//
function PrintMapItem(M){
    str = "The map elements are: ";
    M.forEach((value, key)=>{str += `(${key}, ${value}), `;});
    console.log(str);
} //end-PrintMapItem

let M = new Map([[3, "Ali"], [5, "Veli"], ["Tree", "OK"], [4.5, 88]]);
console.log(M);
console.log(`The map has ${M.size} items`);
PrintMapItem(M);

console.log(M.keys());
console.log(M.values());

// Add a new (key/value) pair
//
console.log("Adding ('Cem', 'Smart') to the map");
M.set("Cem", "Smart");
PrintMapItem(M);

// Remove an existing item
console.log("Removing 'Tree' from the map");
if (M.has("Tree")) M.delete("Tree");

console.log("Removing 99 from the map");
if (M.has(99)) M.delete(99);
PrintMapItem(M);

// Get the value of a key
if (M.has(4.5)) console.log(`The value associated with 4.5 is: ${M.get(4.5)}`);
if (M.has("Cem")) console.log(`The value associated with 'Cem' is: ${M.get('Cem')}`);

// clear(): Deletes all (key/value) pairs in the map
console.log("Removing all map items...");
M.clear();
PrintMapItem(M);
