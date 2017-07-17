package Chapter16;

import java.util.Arrays;

/**
 * Created by cmidler on 7/16/17.
 *  Living People: Given a list of people with their birth and death years, implement a method to
 compute the year with the most number of people alive. You may assume that all people were born
 between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should
 be included in that year's count. For example, Person (birth = 1908, death = 1909) is included in the
 counts for both 1908 and 1909.
 */
public class Question10 {

    class Person{
        int birthYear;
        int deathYear;
    }

    int getYear(Person[] people)
    {
        int[] birthYears = new int[people.length];
        int[] deathYears = new int[people.length];

        for(int i =0; i<people.length; i++)
        {
            Person p = people[i];
            birthYears[i] = p.birthYear;
            deathYears[i] = p.deathYear;
        }

        Arrays.sort(birthYears);
        Arrays.sort(deathYears);

        int mostPeople = 0;
        int currentPeople = 0;
        int year = 1900;
        int bIndex = 0;
        int dIndex = 0;
        while(bIndex<birthYears.length && dIndex<deathYears.length)
        {
            if(dIndex == deathYears.length || birthYears[bIndex]<=deathYears[dIndex])
            {
                bIndex++;
                currentPeople++;
                if(currentPeople> mostPeople)
                {
                    year = birthYears[bIndex];
                    mostPeople = currentPeople;
                }
            }
            else
            {
                dIndex++;
                currentPeople--;
            }
        }
        return year;

    }

}
