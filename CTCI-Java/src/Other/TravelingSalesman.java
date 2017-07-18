package Other;

/**
 * Created by cptmidler on 7/18/17.
 * Given a list of cities and the distances between each pair of cities,
 * what is the shortest possible route that visits each city exactly once and returns to the origin city
 */
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashSet;
public class TravelingSalesman {

    class City{
        boolean isOrigin;
        String cityName;
        boolean isVisited;
    }

    class CityPair{
        City origin;
        City destination;
        double distance;
    }

    ArrayList<City> getShortestRoute(City origin, CityPair[] cities)
    {
        if(origin == null)
            return null;
        origin.isOrigin = true;
        origin.isVisited = true;

        ArrayList<City> nearestNeighbors = new ArrayList<City>();
        City current = origin;
        while(true)
        {
            nearestNeighbors.add(current);
            current = getNextShortestRoute(current, cities);
            if(current == null)
                break;
        }

        nearestNeighbors.add(origin);
        return nearestNeighbors;

    }

    City getNextShortestRoute(City origin, CityPair[] cities)
    {
        double minDistance = Double.MAX_VALUE;
        City nextCity = null;

        for(int i = 0; i<cities.length; i++)
        {
            City o = cities[i].origin;
            City d = cities[i].destination;
            double dist = cities[i].distance;

            if(o==origin && !d.isVisited)
            {
                if(dist<minDistance)
                {
                    nextCity = d;
                    minDistance = dist;
                }
            }
        }

        if(nextCity!=null)
            nextCity.isVisited = true;

        return nextCity;
    }

    int getNumberOfCities(CityPair[] cities)
    {
        HashSet<City> seen = new HashSet<City>();
        for(int i = 0; i<cities.length; i++)
        {
            if(!seen.contains(cities[i].origin))
                seen.add(cities[i].origin);
        }

        return seen.size();
    }


}
