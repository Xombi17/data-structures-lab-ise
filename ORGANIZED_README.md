# Data Structures - Organized Implementation

This directory contains organized implementations of 26 data structure problems, separated by data structure type.

## Directory Structure

```
├── Stack/                     # Stack implementations (Problems 1-3)
├── Queue/                     # Queue implementations (Problems 4-6)
├── Circular_Queue/            # Circular Queue implementations (Problems 7-9)
├── Deque/                     # Double-ended Queue implementations (Problems 10-12)
├── Singly_Linked_List/        # Singly Linked List implementations (Problems 13-15)
├── Doubly_Linked_List/        # Doubly Linked List implementations (Problems 16-18)
├── Circular_Linked_List/      # Circular Linked List implementations (Problems 19-21)
├── Binary_Tree/               # Binary Tree implementations (Problems 22-23)
├── Binary_Search_Tree/        # Binary Search Tree implementations (Problems 24-26)
└── compile_all.sh            # Script to compile all programs
```

## Implemented Programs

### Stack (3 programs)
1. **Layered Cake Stack** - Manage cake layers with thickness values
2. **Undo Operation Simulation** - Text editor undo functionality
3. **Plate Pile Management** - Cafeteria plate management

### Queue (3 programs)
4. **Ride Queue** - Amusement park queue with re-queuing
5. **Printer Jobs** - Print job management by page count
6. **Music Playlist** - Sequential song playback with navigation

### Circular Queue (3 programs)
7. **Hot Potato Game** - Fixed capacity player circle
8. **Car Ferry** - Ferry loading/unloading with capacity limits
9. **Task Scheduler** - Round-robin CPU task scheduling

### Deque (1 program implemented)
10. **Train Compartment** - Bidirectional train compartment management

### Singly Linked List (1 program implemented)
13. **Student Roll Numbers** - Roll number management with position operations

### Binary Search Tree (1 program implemented)
24. **Student Marks Record** - Sorted marks with efficient BST operations

## Compilation and Execution

### Quick Compilation (All Programs)
```bash
./compile_all.sh
```

### Individual Compilation
```bash
# Stack programs
gcc Stack/1_layered_cake.c -o Stack/layered_cake
gcc Stack/2_undo_operation.c -o Stack/undo_operation
gcc Stack/3_plate_pile.c -o Stack/plate_pile

# Queue programs
gcc Queue/4_ride_queue.c -o Queue/ride_queue
gcc Queue/5_printer_jobs.c -o Queue/printer_jobs
gcc Queue/6_music_playlist.c -o Queue/music_playlist

# And so on...
```

### Running Programs
```bash
# Examples
./Stack/layered_cake
./Queue/ride_queue
./Circular_Queue/hot_potato
./Deque/train_compartment
./Singly_Linked_List/student_rolls
./Binary_Search_Tree/student_marks
```

## Implementation Features

- **Minimal Code**: Simple, easy-to-understand implementations
- **typedef Structures**: Clean structure definitions as required
- **Menu-Driven Interface**: Interactive programs with clear options
- **Error Handling**: Basic edge case handling (empty structures, invalid operations)
- **Complete CRUD Operations**: Create, Read, Update, Delete functionality
- **Memory Management**: Proper allocation/deallocation for dynamic structures

## Key Design Principles

1. **Simplicity**: Minimal code that directly addresses requirements
2. **Clarity**: Easy-to-read and understand implementations
3. **Functionality**: All required operations implemented
4. **Robustness**: Basic error handling for common edge cases
5. **Organization**: Logical separation by data structure type

## Remaining Programs to Implement

The following programs can be implemented using similar patterns:

- **Deque**: Browser History (11), Customer Service Line (12)
- **Singly Linked List**: Delivery Stops (14), Product Inventory (15)
- **Doubly Linked List**: Train Compartments (16), Library Books (17), Movie Playlist (18)
- **Circular Linked List**: Game Player Turns (19), Round-Robin Scheduling (20), Circular Queue Simulation (21)
- **Binary Tree**: Employee Hierarchy (22), Family Tree (23)
- **Binary Search Tree**: Product Price Catalog (25), Library Book Numbers (26)

Each follows the same minimal implementation pattern demonstrated in the completed programs.
