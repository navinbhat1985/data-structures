#include <stdio.h>
#include <stdbool.h>


typedef struct Point 
{ 
    int x, y; 
}Point; 
  
// Returns true if two rectangles (l1, r1) and (l2, r2) overlap 
bool doOverlap(Point l1, Point r1, Point l2, Point r2) 
{
    // top left x coordinates of one rectange is greater than bottom right x coordinates
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
    // top left y coordinates of one rectange is less than bottom right y coordinates
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
    return true; 
} 
  
int main() 
{
    // l1,l2 top left coordinates, r1,r2 bottom right coordinates
    Point l1 = {0, 10}, r1 = {10, 0}; 
    Point l2 = {5, 5}, r2 = {15, 0}; 
    if (doOverlap(l1, r1, l2, r2)) 
        printf("Rectangles Overlap"); 
    else
        printf("Rectangles Don't Overlap"); 
    return 0; 
}