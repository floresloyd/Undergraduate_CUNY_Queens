# Computes nth Fibonacci number
def Fibonacci(n: int)->int:
    # Base cases */
    if n == 0: return 0
    if n == 1: return 1

    return Fibonacci(n - 1) + Fibonacci(n - 2)

# main function
def main():
    print(f"5th Fibonacci number is: {Fibonacci(5)}")
    print(f"9th Fibonacci number is: {Fibonacci(9)}")

# Run main
if __name__ == "__main__":
    main()