# histogram on iris dataset
data("iris")
cat("summary:\n",summary(iris))
cat("\nnames",names(iris))
cat("\ndim",dim(iris))
hist(iris$Sepal.Length,
     col='steelblue',
     main='Histogram example',
     xlab='length',
     ylab='frequency')
par(mar(6,6,6,6))
