package Chapter16;

/**
 * Created by cmidler on 7/15/17.
 * Intersection: Given two straight line segments (represented as a start point and an end point),
 compute the point of intersection, if any.
 */
public class Question3 {

    class Point{
        int x;
        int y;
    }

    Point getIntersection(Point start1, Point end1, Point start2, Point end2)
    {
        int slope1 = (end1.y -start1.y)/(end1.x-start1.x);
        int slope2 = (end2.y -start2.y)/(end2.x-start2.x);

        if(slope1 == slope2)
            return null;

        return null;
    }
}
