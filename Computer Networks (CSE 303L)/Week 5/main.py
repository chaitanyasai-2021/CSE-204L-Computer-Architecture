// Chaitanya Sai Nutakki , AP21110010253

import copy
zzzzzzzzzzzzzzzzzzzzzzzzzzzzz
network = {
    'X': {'X': 0, 'Y': 1, 'Z': 2, 'W': float('inf')},
    'Y': {'X': 1, 'Y': 0, 'Z': 3, 'W': 4},
    'Z': {'X': 2, 'Y': 3, 'Z': 0, 'W': 5},
    'W': {'X': float('inf'), 'Y': 4, 'Z': 5, 'W': 0}
}

def print_routing_table(node, routing_table):
    print(f"Routing table for Node {node}:")
    for destination, cost in routing_table.items():
        print(f"Destination: {destination}, Cost: {cost}")

def distance_vector_routing(network, max_iterations=10):
    nodes = network.keys()

    for _ in range(max_iterations):
        updated_network = copy.deepcopy(network)
        for node in nodes:
            for destination in nodes:
                if node == destination:
                    continue
                min_cost = min(updated_network[node][neighbor] + network[neighbor][destination] for neighbor in nodes)
                updated_network[node][destination] = min_cost
        network = updated_network

    for node in nodes:
        print_routing_table(node, network[node])
        print()

distance_vector_routing(network)