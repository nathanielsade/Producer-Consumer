# News Broadcasting Simulation

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

![image](https://github.com/roini7/Producer-Consumer/assets/60584742/3b7d4e50-5d76-44e7-8d9f-f2715891339e)


## Instructions for Running the Project

Follow these steps to compile and run the producer-consumer project:

1. **Compile the Code**: Use the provided `Makefile` to compile the program. In your terminal, run:

make

markdown
Copy
Edit

2. **Execute the Program**: After compilation, run the program with the path to your configuration file:

./ex3.out path

csharp
Copy
Edit

- Replace `path` with the actual location of your configuration file.

## Configuration File Format

The configuration file should be structured as follows:

<Producer ID 1> <Number of Articles Produced by Producer 1> <Queue Size for Producer 1>

<Producer ID 2> <Number of Articles Produced by Producer 2> <Queue Size for Producer 2> ...

<Final Queue Size> ```
Each section in the configuration file corresponds to a producer and contains the following:

Producer ID: The identifier of the producer.
Articles Count: The number of articles that producer will generate.
Queue Size: The maximum number of articles that the producer's queue can hold.
The last section specifies the size of the final queue where co-edited articles are placed.

Example Configuration File
Copy
Edit
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
In this example:

There are three producers, each with its own article production count and queue size.
The final section indicates the size of the final queue (3 in this case).
Make sure that there are spaces between each section as shown above, as the program will parse the file based on this format.

Feel free to modify the configuration file to suit your needs.

Enjoy building, editing, and managing articles in this synchronized producer-consumer setup!

vbnet
Copy
Edit
