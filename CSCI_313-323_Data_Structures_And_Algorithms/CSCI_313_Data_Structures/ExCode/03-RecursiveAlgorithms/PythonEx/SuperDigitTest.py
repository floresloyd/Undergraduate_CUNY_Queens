# Computes the super-digit of a number
def superDigit(n: int)->int:
    # Base case
    if n < 10: return n

    digitSum = 0
    while n > 0:
        digitSum += n % 10
        n = n // 10

    return superDigit(digitSum)

# main function
def main():
    sd = superDigit(9875)
    print(f"SuperDigit of 9875 is {sd}")

    sd = superDigit(12478453)
    print(f"SuperDigit of 12478453 is {sd}")

# Run main
if __name__ == "__main__":
    main()