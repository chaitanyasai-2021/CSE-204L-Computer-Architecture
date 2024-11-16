# -*- coding: utf-8 -*-


import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import DBSCAN
from sklearn.datasets import make_blobs

# Function to generate a sample dataset
def generate_sample_dataset():
    # Create a synthetic dataset with three blobs
    data, labels = make_blobs(n_samples=300, centers=3, cluster_std=0.60, random_state=0)
    return data

# Function to implement DBSCAN clustering
def dbscan_clustering(data, epsilon, min_samples):
    dbscan = DBSCAN(eps=epsilon, min_samples=min_samples)
    labels = dbscan.fit_predict(data)
    return labels

# Function to visualize the results
def visualize_results(data, labels):
    unique_labels = np.unique(labels)

    for label in unique_labels:
        cluster_points = data[labels == label]
        plt.scatter(cluster_points[:, 0], cluster_points[:, 1], label=f'Cluster {label}')

    plt.title('DBSCAN Clustering Results')
    plt.xlabel('Feature 1')
    plt.ylabel('Feature 2')
    plt.legend()
    plt.show()

# User-defined parameters
epsilon = 0.5
min_samples = 5

# Generate sample dataset
dataset = generate_sample_dataset()

# Perform DBSCAN clustering
cluster_labels = dbscan_clustering(dataset, epsilon, min_samples)

# Visualize the results
visualize_results(dataset, cluster_labels)