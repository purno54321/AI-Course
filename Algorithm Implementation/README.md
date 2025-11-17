# 🤖 AI Algorithm Implementations

## 1. `a_star.cpp`

### 🧠 Description:
A* algorithm is a best-first search algorithm that uses both actual cost and heuristic to find the shortest path.

### 📍 Applications:
- Pathfinding in games
- Robot navigation
- GPS systems

### ⏱️ Time Complexity:
- Best Case: O(E)
- Worst Case: O(b^d)

---

## 2. `alpha_beta.cpp`

### 🧠 Description:
Alpha-Beta Pruning is used in the Minimax algorithm to reduce the number of nodes evaluated in the search tree.

### 📍 Applications:
- Game-playing AI (like Chess, Tic Tac Toe)
- Decision-making in turn-based strategy games

### ⏱️ Time Complexity:
- O(b^(d/2))

---

## 3. `beam_search.cpp`

### 🧠 Description:
A heuristic search that keeps only a fixed number of the best nodes at each depth level to control memory usage.

### 📍 Applications:
- Speech recognition
- Machine translation

### ⏱️ Time Complexity:
- O(w × depth), w = beam width

---

## 4. `best_first search.cpp`

### 🧠 Description:
Best-First Search expands the most promising node based on a heuristic. It is greedy in nature.

### 📍 Applications:
- AI planning
- Pathfinding

### ⏱️ Time Complexity:
- O(b^m)

---

## 5. `bfs.cpp` (Breadth-First Search)

### 🧠 Description:
Explores all neighbors at the current depth before moving to the next level.

### 📍 Applications:
- Shortest path in unweighted graphs
- Web crawlers

### ⏱️ Time Complexity:
- O(V + E)

---

## 6. `bidirectional.cpp`

### 🧠 Description:
Performs two simultaneous searches—one forward from the source and one backward from the goal.

### 📍 Applications:
- Navigation systems
- Puzzle solving

### ⏱️ Time Complexity:
- O(b^(d/2))

---

## 7. `c_cpp_properties.json`

### 🛠️ Description:
Configuration file for IntelliSense, including include paths and defines for the C++ environment in VS Code.

### 📍 Purpose:
- Ensures proper compilation and auto-complete support for C++ code in VS Code.

---

## 8. `depth_limited.cpp`

### 🧠 Description:
Performs DFS with a predefined depth limit. Helps prevent infinite recursion in deep/looping graphs.

### 📍 Applications:
- Game AI with limited decision lookahead

### ⏱️ Time Complexity:
- O(b^l), where l = depth limit

---

## 9. `dfs.cpp` (Depth-First Search)

### 🧠 Description:
Explores as far as possible along each branch before backtracking.

### 📍 Applications:
- Maze solving
- Topological sorting

### ⏱️ Time Complexity:
- O(V + E)

---

## 10. `hillclimb.cpp` (Hill Climbing)

### 🧠 Description:
An optimization algorithm that moves in the direction of increasing value until it reaches a peak.

### 📍 Applications:
- Local optimization problems
- Scheduling and planning

### ⏱️ Time Complexity:
- Depends on the problem space

---

## 11. `iterative_deeping.cpp`

### 🧠 Description:
Combines depth-limited search with DFS and increases the depth limit gradually.

### 📍 Applications:
- Game tree search
- Memory-efficient alternative to BFS

### ⏱️ Time Complexity:
- O(b^d)

---

## 12. `launch.json`

### 🛠️ Description:
VS Code debugger configuration file. Defines how C++ programs should be compiled and run during debugging.

---

## 13. `minmax.cpp` (Minimax Algorithm)

### 🧠 Description:
A decision rule used for minimizing the possible loss in a worst-case scenario. Widely used in two-player games.

### 📍 Applications:
- Tic Tac Toe
- Chess and board games

### ⏱️ Time Complexity:
- O(b^d)

---

## 14. `setting.json`

### 🛠️ Description:
VS Code user settings file for configuring environment preferences such as formatting, extensions, and themes.


