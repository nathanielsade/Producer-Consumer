# Producer-Consumer Problem Implementation in C

This project demonstrates a solution to the classic producer-consumer problem using C, set in a reporter-article context. In this scenario, reporters are modeled as producer threads that generate articles, while the article manager (dispatcher) is responsible for distributing these articles to co-editor threads. The dispatcher ensures a fair distribution of tasks using a round-robin scheduling technique, where each producer is allocated a fixed 5ms time quantum for article dispatch.

## Synchronization Overview

The synchronization mechanism at the core of this implementation involves counting and binary semaphores. These semaphores are crucial for coordinating the activities of the producer threads, the dispatcher, and the co-editor threads. They ensure that the producers generate articles, the dispatcher correctly assigns articles to editors, and the co-editors finalize the articles in a synchronized fashion.

![image](https://github.com/roini7/Producer-Consumer/assets/60584742/3b7d4e50-5d76-44e7-8d9f-f2715891339e)

## Article Editing Process

Once the dispatcher assigns an article to the co-editor, it is placed in an unbounded queue categorized by article type. The co-editor thread then handles the article's editing, and once editing is completed, the article is moved to the final queue. The main thread monitors the progress, handling the output of finalized articles.

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

You can now copy and paste this directly as your README. Let me know if you'd like any further adjustments!
