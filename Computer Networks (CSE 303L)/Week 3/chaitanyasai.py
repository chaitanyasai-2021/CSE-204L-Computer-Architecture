#AP21110010253
import time

# Simulated network delay function
def simulate_network_delay():
    time.sleep(1)  # Simulate a 1-second network delay

# Sender function
def sender(data, n):
    seq_num = 0
    while seq_num < len(data):
        # Create a packet with sequence number
        packet = f"Packet {seq_num}: {data[seq_num]}"

        # Send the packet
        print(f"Sender: Sending {packet}")

        # Simulate network delay
        simulate_network_delay()

        # Wait for ACK
        ack = receiver(packet)

        if ack == f"ACK {seq_num}":
            seq_num += 1
        else:
            print("Sender: Timeout, Resending the packet")

# Receiver function
def receiver(packet):
    # Simulate network delay
    simulate_network_delay()

    # Simulate packet loss (50% chance)
    import random
    if random.random() < 0.5:
        print("Receiver: Packet lost")
        return None

    # Otherwise, acknowledge the packet
    seq_num = int(packet.split(":")[0].split()[1])
    ack = f"ACK {seq_num}"
    print(f"Receiver: Received {packet}, Sending {ack}")
    return ack

# Test the Stop-and-Wait protocol with a window size of 3
data = ["Hello", "World", "This", "Is", "Stop", "And", "Wait"]
sender(data, 3)
