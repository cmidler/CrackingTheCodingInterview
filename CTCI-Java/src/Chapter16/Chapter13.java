package Chapter16;

import javax.sound.sampled.Line;

/**
 * Created by cptmidler on 7/17/17.
 * Bisect Squares: Given two squares on a two-dimensional plane, find a line that would cut these two
 squares in half. Assume that the top and the bottom sides of the square run parallel to the x-axis.
 */
public class Chapter13 {
    class Square{
        Point topLeft;
        Point topRight;
        Point bottomLeft;
        Point bottomRight;
    }

    class Point{
        double x;
        double y;

        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class LineSegment{
        Point startPoint;
        Point endPoint;
    }

    LineSegment getLine(Square s1, Square s2)
    {
        Point m1 = getMiddlePoint(s1);
        Point m2 = getMiddlePoint(s2);

        LineSegment line = new LineSegment();
        if(m1.equals(m2) || m1.x == m2.x)
        {
            Square bigger = getBiggerSquare(s1,s2);
            Point bMiddle = getMiddlePoint(bigger);

            line.startPoint = new Point(bMiddle.x, bigger.topLeft.y);
            line.endPoint = new Point(bMiddle.x, bigger.bottomLeft.y);
            return line;
        }

        double slope = getSlope(m1, m2);

        double highY = getHigherY(s1,s2);
        double lowY = getLowerY(s1,s2);

        double highX =  getXIntercept(slope, highY, m1);
        double lowX = getXIntercept(slope, lowY, m1);

        line.startPoint = new Point(lowX, lowY);
        line.endPoint = new Point(highX, highY);
        return line;
    }

    double getXIntercept(double slope, double y, Point middle)
    {
        return ((y-middle.y)/slope)+middle.x;
    }

    double getHigherY(Square s1, Square s2)
    {
        if(s1.topLeft.y > s2.topLeft.y)
            return s1.topLeft.y;
        return s2.topLeft.y;
    }

    double getLowerY(Square s1, Square s2)
    {
        if(s1.bottomLeft.y > s2.bottomLeft.y)
            return s2.bottomLeft.y;
        return s1.bottomLeft.y;
    }

    Square getBiggerSquare(Square s1, Square s2)
    {
        double height1 = s1.topLeft.y-s1.bottomLeft.y;
        double width1 = s1.topRight.x-s1.topLeft.x;

        double height2 = s2.topLeft.y-s2.bottomLeft.y;
        double width2 = s2.topRight.x-s2.topLeft.x;

        if (height1*width1 > height2*width2)
            return s1;
        return s2;
    }

    Point getMiddlePoint(Square s1)
    {
        double midY = (s1.topLeft.y + s1.bottomLeft.y)/2;
        double midX =  (s1.topRight.x + s1.topLeft.x)/2;
        return new Point(midX, midY);
    }

    double getSlope(Point p1, Point p2)
    {
        return ((p2.y-p1.y)/(p2.x-p1.x));
    }

}
