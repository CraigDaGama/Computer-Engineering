def decimal_to_binary(n, bits=8):
    """Convert positive decimal to binary."""
    return format(n, f'0{bits}b')


def twos_complement(binary):
    """Find 2's complement of a binary string."""
    # 1's complement
    ones_comp = ''.join('1' if bit == '0' else '0' for bit in binary)

    # Add 1
    twos_comp = format(int(ones_comp, 2) + 1, f'0{len(binary)}b')

    return ones_comp, twos_comp[-len(binary):]


def signed_binary(n, bits=8):
    """Return binary representation of signed integer."""
    if n >= 0:
        return decimal_to_binary(n, bits)
    else:
        binary = decimal_to_binary(abs(n), bits)
        _, twos = twos_complement(binary)
        return twos


def binary_addition(a_bin, b_bin):
    """Perform binary addition step-by-step."""
    max_len = len(a_bin)

    carry = 0
    result = ""
    carry_steps = []

    print("\nStep 4: Binary Addition")
    print("-" * 40)

    for i in range(max_len - 1, -1, -1):
        bit_a = int(a_bin[i])
        bit_b = int(b_bin[i])

        total = bit_a + bit_b + carry

        result_bit = total % 2
        carry = total // 2

        result = str(result_bit) + result
        carry_steps.append(carry)

    overflow_carry = carry

    print("   ", a_bin)
    print("+  ", b_bin)
    print("-" * (max_len + 5))
    print("   ", result)

    if overflow_carry:
        print("\nOverflow Carry:", overflow_carry)

    return result


def binary_to_decimal(binary):
    """Convert signed 8-bit binary back to decimal."""
    if binary[0] == '0':
        return int(binary, 2)

    # Negative number
    inverted = ''.join('1' if b == '0' else '0' for b in binary)
    magnitude = int(inverted, 2) + 1
    return -magnitude


def main():
    print("=" * 50)
    print("      BINARY ADDITION")
    print("=" * 50)

    a = int(input("\nEnter first number: "))
    b = int(input("Enter second number: "))

    print("\nStep 1: Decimal Numbers")
    print("-" * 40)
    print(f"A = {a}")
    print(f"B = {b}")

    print("\nStep 2: Binary Conversion")
    print("-" * 40)

    if a >= 0:
        a_bin = decimal_to_binary(a)
        print(f"{a} = {a_bin}")
    else:
        abs_bin = decimal_to_binary(abs(a))
        ones, twos = twos_complement(abs_bin)

        print(f"{abs(a)} = {abs_bin}")
        print(f"1's Complement = {ones}")
        print(f"2's Complement = {twos}")

        a_bin = twos

    print()

    if b >= 0:
        b_bin = decimal_to_binary(b)
        print(f"{b} = {b_bin}")
    else:
        abs_bin = decimal_to_binary(abs(b))
        ones, twos = twos_complement(abs_bin)

        print(f"{abs(b)} = {abs_bin}")
        print(f"1's Complement = {ones}")
        print(f"2's Complement = {twos}")

        b_bin = twos

    result_bin = binary_addition(a_bin, b_bin)

    print("\nStep 5: Result Interpretation")
    print("-" * 40)

    decimal_result = binary_to_decimal(result_bin)

    print(f"Binary Result : {result_bin}")
    print(f"Decimal Result: {decimal_result}")

    print("\nVerification")
    print("-" * 40)
    print(f"{a} + {b} = {a + b}")

    if decimal_result == a + b:
        print("✓ Correct")
    else:
        print("✗ Overflow occurred (outside 8-bit range)")


if __name__ == "__main__":
    main()
    
