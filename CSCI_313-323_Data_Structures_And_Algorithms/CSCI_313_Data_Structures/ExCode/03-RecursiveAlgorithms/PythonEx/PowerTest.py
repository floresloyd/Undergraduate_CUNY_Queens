# Computes a^n
def Power(a: float, n: int) -> float:
    # Base cases
    if n == 0: return 1
    if n == 1: return a

    # partialResult = a^(n-1)
    partialResult = Power(a, n - 1)

    # Merge
    return partialResult * a

# main function
def main():
    p = Power(3, 4)
    print(f"3^4 = {p}")
    print("--------------------------")

    p = Power(2.1, 8)
    print(f"2.1^8 = {p:.2f}")

# Run main
if __name__ == "__main__":
    main()