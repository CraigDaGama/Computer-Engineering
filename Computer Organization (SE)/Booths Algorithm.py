# Convert a decimal number to its binary representation
def decimal_to_binary(num, bits):
    binary = [0] * bits
    if num < 0:
        num = (1 << bits) + num  # Two's complement for negative numbers
    for i in range(bits):
        binary[bits - i - 1] = num % 2
        num //= 2
    return binary

# Add two binary numbers
def binary_addition(A, B):
    n = len(A)
    result = [0] * n
    carry = 0
    for i in range(n - 1, -1, -1):
        result[i] = A[i] + B[i] + carry
        if result[i] > 1:
            result[i] -= 2
            carry = 1
        else:
            carry = 0
    return result

# Perform arithmetic right shift
def arithmetic_right_shift(A, Q, Q_1):
    Q_1 = Q[-1]
    Q = [A[-1]] + Q[:-1]
    A = [A[0]] + A[:-1]
    return A, Q, Q_1

# Print binary with spaces for readability
def format_binary(binary):
    return ''.join(map(str, binary))

# Booth's Multiplication Algorithm
def booth_multiplication(multiplicand, multiplier, bits):
    A = [0] * bits  # Initialize A to 0
    M = decimal_to_binary(multiplicand, bits)  # Binary of multiplicand
    M_neg = decimal_to_binary(-multiplicand, bits)  # Binary of -multiplicand
    Q = decimal_to_binary(multiplier, bits)  # Binary of multiplier
    Q_1 = 0  # Initialize Q-1 to 0
    count = bits

    print("Step\tA\t\tQ\t\tQ-1\tAction")

    print(f"Init\t{format_binary(A)}\t{format_binary(Q)}\t{Q_1}\tInitial Values\n")

    for step in range(1, bits + 1):
        action = ""
        
        # Check the last bits of Q and Q-1 to decide action
        if Q[-1] == 1 and Q_1 == 0:
            A = binary_addition(A, M_neg)
            action = "A = A - M"
        elif Q[-1] == 0 and Q_1 == 1:
            A = binary_addition(A, M)
            action = "A = A + M"
        else:
            action = "No Operation"

        # Print the values before shifting
        print(f"{step}\t{format_binary(A)}\t{format_binary(Q)}\t{Q_1}\t{action}")

        # Perform the arithmetic right shift
        A, Q, Q_1 = arithmetic_right_shift(A, Q, Q_1)

        # Print the values after shifting with shift direction specified
        print(f"\t{format_binary(A)}\t{format_binary(Q)}\t{Q_1}\tArithmetic Right Shift\n")

    # Combine A and Q to get the final result in binary
    result = A + Q

    # Convert binary result to decimal
    final_result = 0
    for i in range(len(result)):
        final_result = (final_result << 1) | result[i]

    # Adjust for two's complement negative values
    if result[0] == 1:
        final_result -= (1 << (2 * bits))

    print(f"Final Binary: {format_binary(result)}")
    print(f"Final Decimal: {final_result}")

if __name__ == "__main__":
    multiplicand = int(input("Enter multiplicand: "))
    multiplier = int(input("Enter multiplier: "))
    bits = int(input("Enter the number of bits: "))
    
    booth_multiplication(multiplicand, multiplier, bits)
