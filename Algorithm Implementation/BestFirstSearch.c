#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// নোড (Node) এর জন্য স্ট্রাকচার
struct Node {
    int id;   // নোড নাম্বার (id)
    int h;    // heuristic মান (goal পর্যন্ত আনুমানিক খরচ)

    // priority_queue ছোট h-কে আগে নিতে পারে, এজন্য operator সংজ্ঞা
    bool operator<(const Node& other) const {
        return h > other.h;  
    }
};

// গ্রাফকে অ্যাডজেসেন্সি লিস্ট দিয়ে রাখা
unordered_map<int, vector<int>> graph;

// heuristic মানগুলো রাখা
unordered_map<int, int> heuristic;

// Best First Search ফাংশন
void bestFirstSearch(int start, int goal) {
    priority_queue<Node> pq;   // Priority Queue (ছোট heuristic আগে আসবে)
    pq.push({start, heuristic[start]});  // শুরু নোডকে কিউতে রাখি

    unordered_map<int, bool> visited;   // ভিজিটেড নোড চেক করার জন্য

    while (!pq.empty()) {
        Node current = pq.top();  // সবচেয়ে কম heuristic এর নোড নেওয়া হলো
        pq.pop();

        cout << "Visited Node: " << current.id << endl;

        if (current.id == goal) {   // goal পেলে থামবো
            cout << "Goal Found!" << endl;
            return;
        }

        visited[current.id] = true;  // ভিজিটেড হিসেবে মার্ক করা

        // প্রতিবেশী নোডগুলো কিউতে ঢুকানো
        for (int neighbor : graph[current.id]) {
            if (!visited[neighbor]) {
                pq.push({neighbor, heuristic[neighbor]});
            }
        }
    }
}
 
int main() {
    // গ্রাফ বানানো (Undirected)
    graph[1] = {2, 3};
    graph[2] = {4, 5};
    graph[3] = {6};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};

    // heuristic মান (ধরা হলো goal = 6)
    heuristic[1] = 5;
    heuristic[2] = 3;
    heuristic[3] = 2;
    heuristic[4] = 6;
    heuristic[5] = 4;
    heuristic[6] = 0;

    bestFirstSearch(1, 6);   // শুরু 1 থেকে goal 6
} 