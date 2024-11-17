import numpy as np

num_products = int(input("Enter the number of products: "))

prices = list(map(int, input("Enter the price of the products:\n").split()))

num_bins = int(input("Enter the number of bins: "))

bin_size = num_products // num_bins

prices.sort()

bins = []
start = 0

for _ in range(num_bins):
    end = start + bin_size
    bin_data = prices[start:end]
    bins.append(bin_data)
    start = end

bin_means = [np.mean(bin_data) for bin_data in bins]

smoothed_data = []
for bin_mean in bin_means:
    smoothed_data.extend([round(bin_mean, 2)] * bin_size)

for i in range(num_bins):
    print(f"Bin {i + 1}:", ", ".join(map(str, smoothed_data[i * bin_size:(i + 1) * bin_size])))
