package Chapter16;

import java.util.HashMap;

/**
 * Created by cptmidler on 7/17/17.
 * Best Line: Given a two-dimensional graph with points on it, find a line which passes the most
 number of points
 */
public class Question14 {
    class Point{
        double x;
        double y;

        public Point(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
    }

    class Line{
        Double slope;
        Double yIntercept;
        Double x;


    }

    Line getLineWithMostPoints(Point[] points)
    {
        if (points == null || points.length==0)
            return null;

        HashMap<String, Integer> slopeCount = new HashMap<String, Integer>();

        int count = 0;
        String countKey = "";

        for(int i = 0; i<points.length; i++)
        {
            for(int j = i+1; i<points.length; i++)
            {
                String key;
                if(points[i].x == points[j].x)
                {
                    key = "undefined " + Double.toString(points[i].x);
                }
                else
                {
                    double slope = getSlope(points[i], points[j]);
                    double intercept = getYIntercept(slope, points[i]);
                    key = Double.toString(slope) + ' ' + Double.toString(intercept);
                }
                if (!slopeCount.containsKey(key))
                {
                    slopeCount.put(key, 0);
                }
                slopeCount.put(key, slopeCount.get(key)+1);

                if(slopeCount.get(key) > count)
                {
                    count = slopeCount.get(key);
                    countKey = key;
                }
            }
        }

        Line line = new Line();
        if(countKey.startsWith("undefined "))
        {
            line.slope = null;
            line.yIntercept = null;
            line.x = Double.parseDouble(countKey.substring(10));
        }
        else
        {
            line.x = null;
            int i = 0;
            StringBuilder slope = new StringBuilder();
            StringBuilder intercept = new StringBuilder();
            for(; countKey.charAt(i) !=' '; i++)
            {
                slope.append(countKey.charAt(i));
            }

            line.slope = Double.parseDouble(slope.toString());
            i++;
            for(; i< countKey.length(); i++)
            {
                intercept.append(countKey.charAt(i));
            }

            line.yIntercept = Double.parseDouble(intercept.toString());
        }
        return line;
    }

    double getSlope(Point p1,Point p2)
    {
        return ((p2.y-p1.y)/(p2.x-p1.x));
    }

    double getYIntercept(double slope, Point p)
    {
        return (p.y -(slope*p.x));
    }
}

