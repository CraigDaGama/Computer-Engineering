# matrix operations: add(), subtract(), divide(), multiply(), dot(), sqrt(), sum(x,axis),
#transpose, arrange(), shape(), max(), min(), inverse(), rank(), variance(), mean(),
#standard deviation
import numpy as np 
  
x = np.array([[1, 2], [4, 5]])
y = np.array([[7, 8], [9, 10]])

# using add() to add matrices
print("The element-wise addition of matrices is:")
print(np.add(x, y))

# using subtract() to subtract matrices
print("The element-wise subtraction of matrices is:")
print(np.subtract(x, y))

# using divide() to divide matrices
print("The element-wise division of matrices is:")
print(np.divide(x, y))

# using multiply() to multiply matrices 
print("The element-wise multiplication of matrices is:")
print(np.multiply(x, y))

# using dot() to multiply matrices
print("The product of matrices is:")
print(np.dot(x, y))

# using sqrt() to print the square root of matrix
print("The element-wise square root is:")
print(np.sqrt(x))

# using sum() to print summation of all elements of matrix
print("The summation of all matrix elements is:")
print(np.sum(y))

# using sum(axis=0) to print summation of all columns of matrix
print("The column-wise summation of all matrix is:")
print(np.sum(y, axis=0))

# using sum(axis=1) to print summation of all rows of matrix
print("The row-wise summation of all matrix is:")
print(np.sum(y, axis=1))

# using "T" to transpose the matrix
print("The transpose of the given matrix is:")
print(x.T)

# np.arange(4) creates an array containing elements from 0 to 3.
print("The matrix of size 4 using arrange is:")
A = np.arange(4)
print('A =', A)

# np.arange(12) creates an array containing elements from 0 to 11.
# .reshape(2, 6) reshapes the array into a 2x6 matrix.
print("reshaping 1D array B of size 12 into 2D array:")
B = np.arange(12).reshape(2, 6)
print('B =', B)

# using max() to find largest element in matrix
print("The largest element of the given matrix is:")
print(np.max(x))

# using mean to find mean of elements of the matrix
print("The mean of elements of the given matrix is:")
print(np.mean(x))

# using std() to find standard deviation of the matrix
print("The standard deviation of the given matrix is:")
print(np.std(x))
# variance
print("The variance of the given matrix is:")
print(np.var(x))

# inverse
print("The inverse of the given matrix is:")
print(np.linalg.inv(x))

# finding rank of given matrix
print("The rank of the given matrix is:")
print(np.linalg.matrix_rank(x))
