import numpy as np

# Sigmoid activation function
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Derivative of sigmoid function
def sigmoid_derivative(x):
    return x * (1 - x)


# Error Backpropagation Network
class BackPropagationNetwork:
    def __init__(self, input_size, hidden_size, output_size, learning_rate=0.25):
        self.learning_rate = learning_rate

        # Input → Hidden layer weights (including bias)
        self.W_input_hidden = np.array([
            [0.6, -0.3],
            [-0.1, 0.4],
            [0.3, 0.5]
        ])

        # Hidden → Output layer weights (including bias)
        self.W_hidden_output = np.array([
            [0.4],
            [0.1],
            [-0.2]
        ])

    # Forward Pass
    def forward_pass(self, X):
        # Add bias to input layer
        X = np.append(X, 1)

        # Input → Hidden
        self.hidden_input = np.dot(X, self.W_input_hidden)
        self.hidden_output = sigmoid(self.hidden_input)

        # Add bias to hidden layer
        self.hidden_output = np.append(self.hidden_output, 1)

        # Hidden → Output
        self.final_input = np.dot(self.hidden_output, self.W_hidden_output)
        self.final_output = sigmoid(self.final_input)

        # Display values
        print(f"Net input to hidden layer: {self.hidden_input}")
        print(f"Output from hidden layer: {self.hidden_output[:-1]}")
        print(f"Net input to output layer: {self.final_input}")
        print(f"Output from output layer: {self.final_output}")

        return self.final_output

    # Backpropagation
    def backpropagate(self, X, Y):
        # Forward pass
        output = self.forward_pass(X)

        # Output layer error
        output_error = Y - output
        delta_output = output_error * sigmoid_derivative(output)

        # Hidden layer error
        hidden_error = np.dot(self.W_hidden_output[:-1], delta_output)
        delta_hidden = hidden_error.flatten() * sigmoid_derivative(self.hidden_output[:-1])

        # Display errors
        print(f"Output layer error: {output_error}")
        print(f"Delta for output layer: {delta_output}")
        print(f"Hidden layer error: {hidden_error}")
        print(f"Delta for hidden layer: {delta_hidden}")

        # Update Hidden → Output weights
        W_hidden_output_update = self.learning_rate * np.outer(self.hidden_output, delta_output)
        self.W_hidden_output += W_hidden_output_update

        # Add bias again to input
        X = np.append(X, 1)

        # Update Input → Hidden weights
        W_input_hidden_update = self.learning_rate * np.outer(X, delta_hidden)
        self.W_input_hidden += W_input_hidden_update

        # Display updates
        print("Updated weights for hidden to output layer:")
        print(W_hidden_output_update)

        print("Updated weights for input to hidden layer:")
        print(W_input_hidden_update)

        print("=" * 50)

    # Training
    def train(self, X, Y, epochs=5):
        for epoch in range(epochs):
            print(f"\nEpoch {epoch + 1}")
            self.backpropagate(X, Y)

    # Prediction
    def predict(self, X):
        return self.forward_pass(X)


# Main Program
input_size = 2
hidden_size = 2
output_size = 1
learning_rate = 0.25

bpn = BackPropagationNetwork(
    input_size,
    hidden_size,
    output_size,
    learning_rate
)

# Input and Target
X = np.array([0, 1])   # X1 = 0, X2 = 1
Y = np.array([1])      # Target output

# Train
bpn.train(X, Y, epochs=5)

# Test
predicted_output = bpn.predict(X)
print(f"\nFinal predicted output: {predicted_output}, Target: {Y}")
