# Program to find matrix Determinant, Trace, Eigenvalues, Eigenvectors, Singular value decompositions
import numpy as np 
from scipy import linalg

matrix = np.array ([[1, 2, 3],[2, 4, 6],[3, 8, 9]]) 
 
# Diagonal of matrix
print("The Diagonal of the matrix is:")
print(matrix.diagonal()) 
 
#Determinant of matrix
print("The Determinant of the matrix is:") 
print(np.linalg.det(matrix))
 
#Trace of matrix
print("The Trace of the matrix is:") 
print(matrix.trace())
 
eigenvalues, eigenvectors = np.linalg.eig(matrix)
 
#Eigenvalues of matrix
print ("The eigenvalues of the matrix is:") 
print (eigenvalues) 
 
#Eigenvectors of matrix 
print ("The eigenvectors of the matrix is:") 
print (eigenvectors) 
 
#Singular value decompositions of matrix 
A = np.array([[1, 2, 3], [4, 5, 6]])
print("Original Matrix A:")
print(A)
# Get the shape of matrix A
M, N = A.shape

# Perform Singular Value Decomposition (SVD)
U, s, Vh = linalg.svd(A)

# Construct the Sigma matrix
Sig = linalg.diagsvd(s, M, N)

# Ensure that U and Vh are computed correctly
U, Vh = U, Vh

# Print the U, Sigma, and Vh matrices
print("Matrix U:")
print(U)
print("Matrix Sigma:")
print(Sig)
print("Matrix Vh (conjugate transpose of V):")
print(Vh)

# Reconstruct the original matrix from its SVD
b = U.dot(Sig.dot(Vh))
print("Reconstructed Matrix from SVD:")
print(b)
