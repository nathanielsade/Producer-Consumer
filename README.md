Copy# News Broadcasting Simulation

This project is an implementation of a news broadcasting simulation, designed to provide experience with concurrent programming and synchronization mechanisms. The goal is to simulate the production and display of different types of news stories, while evaluating the performance impact of synchronization constructs under different loads.

## Purpose

The purpose of this assignment is to gain hands-on experience in concurrent programming and synchronization. It is crucial to carefully design the system before implementation to avoid potential difficulties during the coding process.

## Scenario

The simulation revolves around news broadcasting. Various types of stories are produced and sorted for display to the public. The system is composed of four types of active actors:

1. **Producer**: Each producer generates strings in the format: "producer *". The represents the producer's ID, is a randomly chosen type from 'SPORTS', 'NEWS', 'WEATHER', and indicates the number of strings of type produced by the producer. The number of products generated by a producer is specified during its instantiation. The producer sends its information to the Dispatcher through its private queue, which is shared between the producer and the Dispatcher. After inserting all the products into its private queue, the producer sends a "DONE" message through the queue.

2. **Dispatcher**: The Dispatcher continuously receives messages from the producers' queues using a Round Robin algorithm. It does not block when the queues are empty. The Dispatcher sorts each message and inserts it into one of its three queues: "S dispatcher queue" for sports, "N dispatcher queue" for news, and "W dispatcher queue" for weather. Once the Dispatcher receives a "DONE" message from all producers, it sends a "DONE" message through each of its queues.

3. **Co-Editors**: Each type of message has a corresponding Co-Editor. These Co-Editors receive messages from the Dispatcher's queues, perform an "editing" process by blocking for 0.1 seconds, and then pass the edited message to the Screen Manager via a shared queue. When a Co-Editor receives a "DONE" message, it immediately passes it through the shared queue without waiting.

4. **Screen Manager**: The Screen Manager receives the edited messages from the Co-Editors via a shared queue and displays them on the screen (standard output). After printing all the messages and receiving three "DONE" messages, the Screen Manager displays a "DONE" statement.

## System Design

[System Design Diagram Here]

## Running Commands

To compile and run the program:
make
./ex3.out config.txt
Copy
## Configuration File

The configuration file defines the producers and queue sizes. Each producer section includes:
- Producer ID
- Number of articles to produce
- Queue size for that producer

The final line specifies the size of the final queue.

Example configuration:
1
10
5
2
8
4
3
12
6
3
