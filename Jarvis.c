#include <stdio.h>
typedef struct
{
    double x;
    double y;
} point;
// returns the cross product of vectors p1p2 and p2p3 
double cross_product(point p1, point p2, point p3)
{
    return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
}
// Jarvis March Algorithm for Convex Hull
void convex_hull(point points[], int n)
{
    int hull[n];
    int leftmost = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[leftmost].x)
        {
            leftmost = i;
        }
    }
    int p = leftmost, q;
    int hull_size = 0;
    do
    {
        hull[hull_size++] = p;
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (cross_product(points[p], points[i], points[q]) > 0)
            {
                q = i;
            }
        }
        p = q;
    } while (p != leftmost);
        // print the hull points
        for (int i = 0; i < hull_size; i++)
    {
        printf("(%lf, %lf)\n", points[hull[i]].x, points[hull[i]].y);
    }
}
int main()
{
    // read input
    int n;
    scanf("%d", &n);
    point points[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }
    // compute and print the Convex Hull using Jarvis March algorithm
        convex_hull(points, n);
    return 0;
}