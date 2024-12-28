// Sets in JavaScript are an unordered set of items with no duplicates
// This corresponds to the HashSet in other Programming Languages
// When we iterate over a set object, the values are returned in the order they are inserted.
//
function PrintSetItems(S){
    let str = "The set items are: ";
    S1.forEach(item=>{str += `${item}, `;});
    console.log(str);    
} //end-PrintSetItems


let S1 = new Set([3, 5, "ali", 4.5, "veli"]);
console.log(S1);
console.log(`The set has ${S1.size} items`);
PrintSetItems(S1);

// add(item): Adds an item to the set. If the item already exists, it is not added
//
console.log("Adding 20 to the set");
S1.add(20);
PrintSetItems(S1);

console.log("Adding 'ali' to the set");
S1.add('ali');  // No duplicates in a set. So, this does not add 'ali' again.
PrintSetItems(S1);

// remove(item): Removes an item from the set. 
//
console.log("Removing 4.5 from the set");
S1.delete(4.5);

console.log("Removing 5 from the set");
S1.delete(5)
PrintSetItems(S1);

// find: Does an item exist?
let exist = S1.has('ali')
console.log(`Does the set contain 'ali'? ${exist? 'Yes': 'No'}`);

console.log("Adding 'cemal' to the set");
if (!S1.has("cemal")) S1.add("cemal");
PrintSetItems(S1);

console.log("Removing 'ali' from the set")
S1.delete('ali');
PrintSetItems(S1);

console.log("Removing 30 from the set")
S1.delete(30);
PrintSetItems(S1);



