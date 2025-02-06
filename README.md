# The Puppet Project

## Overview
The goal was to create a **3D puppet using geometric primitives in OpenGL**, implementing a **hierarchical structure** for animation and a **user interface** to manipulate joints and movements.

## Features
- **Hierarchical Animation Structure**: Each body part is controlled using a **stack of transformation matrices**, allowing for smooth and logical movement.
- **Interactive Controls**: Implemented a user interface with **sliders for joint angles, global position, and orientation**.
- **Transformation System**: Added **undo and redo functionality** for transformations, making adjustments more intuitive.
- **Predefined Animations**: Pressing specific keys triggers animations that simulate **realistic human movements**.

## Implementation Challenges
### **Hierarchical Model & Stacks**
One of the biggest challenges was **understanding and implementing stacks for each branch of the hierarchical model**. Each body part (limb) is added to the stack with **control parameters for joint articulation**. The **stack-based transformation system** works by:
1. **Pushing transformation matrices** as the hierarchy is traversed.
2. **Performing translations and rotations** for each body part relative to its parent.
3. **Ensuring correct placement** by first translating to the origin, applying rotations, and then translating to the final position.

### **OpenGL Integration Issues**
At one point, OpenGL **completely crashed** due to renaming one of the `.cpp` files to `main.cpp`. This issue prevented the project from running and required:
- **Recreating the project from scratch** and reinstalling OpenGL.
- **Referencing tutorials (e.g., Cherno’s videos)** to debug and rebuild the system.

## File Structure
- **`src/Application.cpp`** → Main program logic.
- **`src/`** → Contains all required **source codes and libraries** for handling transformations, shaders, and rendering.
- **`Shaders/`** → Contains necessary shader files for rendering in OpenGL.

## Controls
- **Press `O`** → Moves the puppet along the **Y-axis**.
- **Hold `P`** → Triggers an **animated movement sequence**, simulating natural body oscillations.

---
This project was a great learning experience in **hierarchical modeling, OpenGL transformations, and debugging complex rendering systems**.
