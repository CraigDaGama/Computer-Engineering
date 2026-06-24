import numpy as np
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import SimpleRNN, Dense
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical

# ==========================================
# Load MNIST Dataset
# ==========================================
(x_train, y_train), (x_test, y_test) = mnist.load_data()

print("Training Data Shape:", x_train.shape)
print("Testing Data Shape :", x_test.shape)

# ==========================================
# Normalize Pixel Values (0-255 -> 0-1)
# ==========================================
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0

# ==========================================
# Reshape for RNN
# Shape: (samples, timesteps, features)
# Each row of image = one timestep
# ==========================================
x_train = x_train.reshape((x_train.shape[0], 28, 28))
x_test = x_test.reshape((x_test.shape[0], 28, 28))

print("RNN Input Shape:", x_train.shape)

# ==========================================
# One-Hot Encode Labels
# ==========================================
y_train = to_categorical(y_train, 10)
y_test = to_categorical(y_test, 10)

# ==========================================
# Build RNN Model
# ==========================================
model = Sequential()

# RNN Layer
model.add(
    SimpleRNN(
        units=50,
        activation='relu',
        input_shape=(28, 28)
    )
)

# Output Layer
model.add(
    Dense(
        10,
        activation='softmax'
    )
)

# ==========================================
# Display Model Architecture
# ==========================================
model.summary()

# ==========================================
# Compile Model
# ==========================================
model.compile(
    optimizer='adam',
    loss='categorical_crossentropy',
    metrics=['accuracy']
)

# ==========================================
# Train Model
# ==========================================
history = model.fit(
    x_train,
    y_train,
    epochs=10,
    batch_size=128,
    validation_data=(x_test, y_test)
)

# ==========================================
# Evaluate Model
# ==========================================
test_loss, test_acc = model.evaluate(
    x_test,
    y_test,
    verbose=2
)

print("\nTest Loss     :", test_loss)
print("Test Accuracy :", test_acc)

# ==========================================
# Predict Sample Image
# ==========================================
sample = x_test[0].reshape(1, 28, 28)

prediction = model.predict(sample)

predicted_digit = np.argmax(prediction)
actual_digit = np.argmax(y_test[0])

print("\nActual Digit    :", actual_digit)
print("Predicted Digit :", predicted_digit)
print("Prediction Probabilities:")
print(prediction)
