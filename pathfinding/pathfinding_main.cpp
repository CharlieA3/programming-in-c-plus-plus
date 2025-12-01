#include "Pathfinding.hpp"
#include "Point.hpp"
#include "World.hpp"
#include <iostream>
#include <list>
#include <set>
#include <sstream>
using namespace std;



// display a point
void displayPoint(const Point & p) {
  cout << p.row << "," << p.col;
}

// display the neighbors for all cells on the diagonal
void displayNeighbors(const World & w) {
  set< Point > to_check;
  for (int ii = 0; ii <= w.size + 1; ++ ii) { // <= to test requesting out of bounds points
    to_check.insert({ 0, ii });
    to_check.insert({ ii, 0 });
    to_check.insert({ ii, ii });
  }
  
  for (const Point & pt: to_check) {
    displayPoint(pt);
    cout << ":";
    
    set<Point> neighbors;
    w.get_neighbors(pt, neighbors);

    for (const Point & nb: neighbors) {
      cout << " ";
      displayPoint(nb);
    }
    cout << endl;
  }
}

// display a short summary of the path
void displayPathSummary(const World & w, const list<Point> & path) {
  if (path.empty()) {
    cout << "no path" << endl;
  } else {
    bool first = true;
    Point prev;

    cout << "path: ";
    for (const Point & pt: path) {
      if (!first) {
	if ((pt.row == prev.row && (pt.col == prev.col + 1 || pt.col == prev.col - 1)) || 
	    (pt.col == prev.col && (pt.row == prev.row + 1 || pt.row == prev.row - 1))) {
	  cout << '-';
	} else {
	  cout << ' ';
	}
      }
      first = false;
      prev = pt;
	  
      if (pt == w.start) {
	cout << 's';
      } else if (pt == w.goal) {
	cout << 'g';
      } else if (w.blocks.find(pt) != w.blocks.end()) {
	cout << 'x';
      } else {
	cout << '.';
      }
    }
    cout << endl;
  }
}

// display the points along the path
void displayPathPoints(const list<Point> & path) {
  if (path.empty()) {
    cout << "no path" << endl;
  } else {
    cout << "path:";
    for (const Point & pt: path) {
      cout << " ";
      displayPoint(pt);
    }
    cout << endl;
  }
}

int main() {
  string line;
  while (getline(cin, line)) {
    stringstream sstr(line);

    string command;
    sstr >> command;

    int worldId;
    sstr >> worldId;

    if (!sstr || worldId < 1 || worldId > 99) {
      cout << "Invalid input." << endl;
      continue;
    }

    World w;
    w.initialize(worldId);
    
    if (command == "print") {
      w.display(list<Point>());
    } else if (command == "neighbors") {
      displayNeighbors(w);
    } else if (command == "astar-print") {
      list<Point> path;
      pathfind_astar(w, path);
      
      w.display(path);
      displayPathPoints(path);
      displayPathSummary(w, path);
    } else if (command == "astar-summary") {
      list<Point> path;
      pathfind_astar(w, path);

      displayPathSummary(w, path);
    } else if (command == "bfs-print") {
      list<Point> path;
      pathfind_bfs(w, path);
      
      w.display(path);
      displayPathPoints(path);
      displayPathSummary(w, path);
    } else if (command == "bfs-summary") {
      list<Point> path;
      pathfind_bfs(w, path);

      displayPathSummary(w, path);
    } else {
      cout << "Invalid input." << endl;
    }
  }
}
