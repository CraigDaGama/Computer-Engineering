# R program to find the minimum of three numbers

minimum <- function(a, b, c) {
  return(min(a, b, c))
}

num1 <- as.numeric(readline(prompt = "Enter the first number: "))
num2 <- as.numeric(readline(prompt = "Enter the second number: "))
num3 <- as.numeric(readline(prompt = "Enter the third number: "))

min <- minimum(num1, num2, num3)
print(paste("The minimum value is:", min))
