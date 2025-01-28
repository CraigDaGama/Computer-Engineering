list = c(2,4,4,4,5,5,7,9)
print(mean(list))
print(var(list))
print(sd(list))
n <- length(list)
a <- c(2,4,6,8,10)
b <- c(1,11,3,33,5)
# covariance
print(cov(a,b,method = "pearson"))
# corelation
print(cor(a,b,method = "pearson"))

