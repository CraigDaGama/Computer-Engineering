library(modeest)
vec1=c(12,15,15,22,22,22,23,45,67,78,89)
print(summary(vec1))
cat("median=",median(vec1))
cat("\nIQR",IQR(vec1))
range = max(vec1) - min(vec1)
cat("\n range=",range)
cat("\n using range function",range(vec1))
cat("\n mode",mfv(vec1))


boxplot(
  vec1,
  data=vec1
)
par(mar=c(8,8,8,8))
