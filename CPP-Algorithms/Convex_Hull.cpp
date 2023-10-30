#include <iostream>
#include <vector>
#include <algorithm>

class Point {
public:
    int x;
    int y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// Function to calculate the cross product of two vectors
int crossProduct(const Point& p, const Point& q, const Point& r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// Function to compare two points based on their polar angle
bool comparePoints(const Point& p1, const Point& p2) {
    int cross = crossProduct(Point(0, 0), p1, p2);
    if (cross > 0)
        return true;
    if (cross < 0)
        return false;
    return p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y;
}

// Function to compute the convex hull using Graham's scan algorithm
std::vector<Point> computeConvexHull(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3)
        return points;

    int bottommostIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[bottommostIndex].y || (points[i].y == points[bottommostIndex].y && points[i].x < points[bottommostIndex].x))
            bottommostIndex = i;
    }

    std::swap(points[0], points[bottommostIndex]);
    std::sort(points.begin() + 1, points.end(), comparePoints);

    std::vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    int numPoints;
    std::cout << "Enter the number of points: ";
    std::cin >> numPoints;

    std::vector<Point> points;
    for (int i = 0; i < numPoints; i++) {
        int x, y;
        std::cout << "Enter x and y coordinates for point " << i + 1 << ": ";
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }

    std::vector<Point> convexHull = computeConvexHull(points);

    std::cout << "Convex Hull Points:\n";
    for (const auto& point : convexHull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
