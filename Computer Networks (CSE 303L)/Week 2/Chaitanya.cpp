// AP21110010253
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const double ERROR_PROBABILITY = 0.2;

int simulateChannel(int frame) {
    if (rand() / double(RAND_MAX) < ERROR_PROBABILITY) {
        
        return 1 - frame;
    }
    return frame;
}

void sender(int data[], int dataSize) {
    int ack = 0;
    while (ack < dataSize) {
        int frame = data[ack];
        cout << "Sender: Sending Frame " << frame << endl;
        sleep(1); 
        int receivedFrame = frame;
        receivedFrame = simulateChannel(receivedFrame);
        cout << "Receiver: Received Frame " << receivedFrame << endl;
        if (receivedFrame == frame) {
            cout << "Sender: Acknowledgment " << frame << " received." << endl;
            ack++;
        } else {
            cout << "Sender: Acknowledgment " << frame << " not received. Resending..." << endl;
        }
    }
}

int main() {
    srand(time(0)); 

    int dataSize;
    cout << "Enter the number of data frames to send: ";
    cin >> dataSize;

    int dataToSend[dataSize];
    cout << "Enter the data frames (0 or 1) separated by spaces: ";
    for (int i = 0; i < dataSize; i++) {
        cin >> dataToSend[i];
    }

    cout << "Simulating 1-bit Stop and Wait Protocol" << endl;
    sender(dataToSend, dataSize);

    return 0;
}