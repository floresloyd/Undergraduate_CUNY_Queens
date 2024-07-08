function drawTriangle(triangleSize) {
   for (let i = 1; i <= triangleSize; i++) {
       let row = '';
       for (let j = 1; j <= i; j++) {
           row += '*';
       }
       console.log(row);
   }
}

// Test the function
drawTriangle(4); // Change the parameter to test with different sizes