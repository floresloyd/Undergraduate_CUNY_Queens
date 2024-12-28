# Computes 1+2+3+...+n
def Sum(n):
    # Base case */
    if n == 1: return 1

    # Divide and conquer
    partialSum = Sum(n - 1)

    # Merge
    return partialSum + n

# main function
def main():
    x = Sum(4)
    print(f"1+2+3+4 = {x}")
    print("--------------------------")

    x = Sum(7)
    print(f"1+2+3+4+5+6+7 = {x}")

# Run main
if __name__ == "__main__":
    main()