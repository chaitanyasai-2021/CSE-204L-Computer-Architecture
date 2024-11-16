import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression

num_points = int(input("Enter the number of data points: "))

x = []
y = []

for i in range(num_points):
    x_val = float(input(f"Enter x[{i + 1}]: "))
    y_val = float(input(f"Enter y[{i + 1}]: "))
    x.append(x_val)
    y.append(y_val)

x = np.array(x)
y = np.array(y)

mean_x = np.mean(x)
mean_y = np.mean(y)

x_minus_mean_x = x - mean_x
y_minus_mean_y = y - mean_y
xy_minus_mean_x_mean_y = x_minus_mean_x * y_minus_mean_y
x_minus_mean_x_squared = (x - mean_x) ** 2

if len(x.shape) == 1:
    x = x.reshape(-1, 1)

model = LinearRegression()
model.fit(x, y)

slope = model.coef_[0]
intercept = model.intercept_

result_df = pd.DataFrame({'x': x.flatten(), 'y': y,
                          'x - mean(x)': x_minus_mean_x.flatten(),
                          'y - mean(y)': y_minus_mean_y.flatten(),
                          '(x - mean(x)) * (y - mean(y))': xy_minus_mean_x_mean_y.flatten(),
                          '(x - mean(x))^2': x_minus_mean_x_squared.flatten()})
result_df['Predicted y'] = model.predict(x)

print(result_df)
print("Slope (Coefficient): %.2f" % slope)
print("Intercept: %.2f" % intercept)
