import numpy as np

def bipolar_sigmoid(net):
    return (2 / (1 + np.exp(-net))) - 1

def bipolar_sigmoid_derivative(output):
    return 0.5 * (1 - output**2)

weights = np.array([1, -1, 0, 0.5])  
learning_rate = 0.1

input_vectors = [
    np.array([1, -2, 0, -1]),  
    np.array([0, 1.5, -0.5, -1]),  
    np.array([-1, 1, 0.5, -1])  
]

desired_outputs = [-1, -1, 1]

for epoch in range(2):
    print(f"Epoch {epoch + 1}:")
    for i, x in enumerate(input_vectors):
        net = np.dot(weights, x)
        output = bipolar_sigmoid(net)
        error = (desired_outputs[i] - output)
        derivative = bipolar_sigmoid_derivative(output)
        delta_w = learning_rate * error * derivative * x
        weights += delta_w
        
        print(f" Input vector x{i + 1}: {x}")
        print(f" Net{i + 1}: {net}")
        print(f" Output{i + 1}: {output:.4f}")
        print(f" Derivative{i + 1}: {derivative:.4f}")
        print(f" Updated Weights: {weights}\n")
