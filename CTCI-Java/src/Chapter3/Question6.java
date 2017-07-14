package Chapter3;

/**
 * Created by cmidler on 7/14/17.
 * Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
 out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
 or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
 that type). They cannot select which specific animal they would like. Create the data structures to
 maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
 and dequeueCat. You may use the built-in Linked List data structure
 */
import java.util.LinkedList;
public class Question6 {
    class AnimalQueue{
        LinkedList<Animal> dq;
        LinkedList<Animal> cq;
        int age;

        public AnimalQueue(){
            this.dq = new LinkedList<Animal>();
            this.cq = new LinkedList<Animal>();
            this.age= Integer.MAX_VALUE;
        }

        private void reshuffleAges(){
            //Don't need to write this
        }
        public void enqueue(Animal a)
        {
            if (this.age == 0)
                reshuffleAges();
            a.age = this.age--;
            if(a.isCat)
                cq.addLast(a);
            else if (a.isDog)
                dq.addLast(a);
        }

        public Animal dequeueDog(){
            if (dq.isEmpty())
                return null;
            return dq.removeFirst();
        }

        public Animal dequeueCat(){
            if(cq.isEmpty())
                return null;
            return cq.removeFirst();
        }

        public Animal dequeueAny(){
            if (dq.isEmpty())
                return dequeueCat();
            else if (cq.isEmpty())
                return dequeueDog();
            else
            {
                Animal dog = dq.getFirst();
                Animal cat = cq.getFirst();
                if(dog.age > cat.age)
                    return dequeueDog();
                return dequeueCat();
            }
        }

        class Animal{
            boolean isDog;
            boolean isCat;
            int age;
        }
    }
}
