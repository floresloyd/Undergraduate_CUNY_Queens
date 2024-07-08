function isStrongPassword(password) {
    // Check if password is at least 8 characters long
    if (password.length < 8) {
        return false;
    }

    // Check if password contains "password"
    if (password.toLowerCase().includes("password")) {
        return false;
    }

    // Check if password contains at least one uppercase character
    if (!/[A-Z]/.test(password)) {
        return false;
    }

    // All conditions passed, return true
    return true;
}

// Test the function
console.log(isStrongPassword("Qwerty"));         // false - Too short
console.log(isStrongPassword("passwordQwerty")); // false - Contains "password"
console.log(isStrongPassword("qwerty123"));      // false - No uppercase characters
console.log(isStrongPassword("Qwerty123"));      // true
