# Producer-Consumer System in C

## Project Overview
This C implementation addresses the classical producer-consumer problem within a news agency framework. The system consists of multiple reporter threads (producers) that generate articles, which are then managed by a dispatcher that distributes them to co-editors using round-robin scheduling. Each reporter operates with their own bounded-capacity article queue.

## Synchronization Implementation
The project implements robust thread synchronization using:
- Counting semaphores to regulate production flow
- Binary semaphores to ensure mutual exclusion
- Custom queue management for different article types

These mechanisms prevent race conditions while enabling efficient coordination between reporters, the dispatcher, and co-editors.

## Article Processing Workflow
1. Reporter threads generate articles and place them in their individual bounded queues
2. The dispatcher extracts articles using round-robin scheduling
3. Articles are transferred to appropriate unbounded buffers based on their type
4. Co-editors process articles from these type-specific buffers
5. Edited articles are placed in the final queue for output processing
6. The main thread handles display of completed articles

![image](https://github.com/roini7/Producer-Consumer/assets/60584742/3b7d4e50-5d76-44e7-8d9f-f2715891339e)

## Compiling and Executing
To build and run the program:

```bash
# Compile using the included makefile
make

# Run the program with your configuration file
./ex3.out [config_file_path]
```

## Configuration File Format
The program requires a configuration file with the following structure:

```
[Reporter ID 1]
[Number of Articles for Reporter 1]
[Queue Size for Reporter 1]

[Reporter ID 2]
[Number of Articles for Reporter 2]
[Queue Size for Reporter 2]

...

[Final Queue Size]
```

### Sample Configuration
```
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
```

This example configures:
- Reporter 1: Produces 10 articles with a queue size of 5
- Reporter 2: Produces 8 articles with a queue size of 4
- Reporter 3: Produces 12 articles with a queue size of 6
- Final queue size: 3

**Note:** Ensure blank lines separate each reporter's configuration and the final queue size specification for proper parsing.

## Project Constraints
- Bounded queues for reporters
- Unbounded buffers for article types
- Round-robin scheduling
- Thread-safe operations throughout the pipeline

The system demonstrates effective management of concurrent processes while maintaining data integrity across multiple threads.
