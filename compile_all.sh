#!/bin/bash

echo "Compiling all Data Structure programs..."

# Stack programs
echo "Compiling Stack programs..."
gcc Stack/1_layered_cake.c -o Stack/layered_cake
gcc Stack/2_undo_operation.c -o Stack/undo_operation
gcc Stack/3_plate_pile.c -o Stack/plate_pile

# Queue programs
echo "Compiling Queue programs..."
gcc Queue/4_ride_queue.c -o Queue/ride_queue
gcc Queue/5_printer_jobs.c -o Queue/printer_jobs
gcc Queue/6_music_playlist.c -o Queue/music_playlist

# Circular Queue programs
echo "Compiling Circular Queue programs..."
gcc Circular_Queue/7_hot_potato.c -o Circular_Queue/hot_potato
gcc Circular_Queue/8_car_ferry.c -o Circular_Queue/car_ferry
gcc Circular_Queue/9_task_scheduler.c -o Circular_Queue/task_scheduler

# Deque programs
echo "Compiling Deque programs..."
gcc Deque/10_train_compartment.c -o Deque/train_compartment

# Singly Linked List programs
echo "Compiling Singly Linked List programs..."
gcc Singly_Linked_List/13_student_rolls.c -o Singly_Linked_List/student_rolls

# Doubly Linked List programs
echo "Compiling Doubly Linked List programs..."
gcc Doubly_Linked_List/16_train_compartments.c -o Doubly_Linked_List/train_compartments
gcc Doubly_Linked_List/17_library_books.c -o Doubly_Linked_List/library_books

# Circular Linked List programs
echo "Compiling Circular Linked List programs..."
gcc Circular_Linked_List/19_game_players.c -o Circular_Linked_List/game_players
gcc Circular_Linked_List/20_round_robin.c -o Circular_Linked_List/round_robin

# Binary Tree programs
echo "Compiling Binary Tree programs..."
gcc Binary_Tree/22_employee_hierarchy.c -o Binary_Tree/employee_hierarchy
gcc Binary_Tree/23_family_tree.c -o Binary_Tree/family_tree

# Binary Search Tree programs
echo "Compiling Binary Search Tree programs..."
gcc Binary_Search_Tree/24_student_marks.c -o Binary_Search_Tree/student_marks

echo "Compilation complete!"
echo ""
echo "To run programs:"
echo "Stack: ./Stack/layered_cake, ./Stack/undo_operation, ./Stack/plate_pile"
echo "Queue: ./Queue/ride_queue, ./Queue/printer_jobs, ./Queue/music_playlist"
echo "Circular Queue: ./Circular_Queue/hot_potato, ./Circular_Queue/car_ferry, ./Circular_Queue/task_scheduler"
echo "Deque: ./Deque/train_compartment"
echo "Singly Linked List: ./Singly_Linked_List/student_rolls"
echo "Doubly Linked List: ./Doubly_Linked_List/train_compartments, ./Doubly_Linked_List/library_books"
echo "Circular Linked List: ./Circular_Linked_List/game_players, ./Circular_Linked_List/round_robin"
echo "Binary Tree: ./Binary_Tree/employee_hierarchy, ./Binary_Tree/family_tree"
echo "Binary Search Tree: ./Binary_Search_Tree/student_marks"
