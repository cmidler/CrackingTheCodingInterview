package Chapter16;

/**
 * Created by cmidler on 7/17/17.
 * LRU Cache: Design and build a "least recently used" cache, which evicts the least recently used
 item. The cache should map from keys to values (allowing you to insert and retrieve a value associated
 with a particular key) and be initialized with a max size. When it is full, it should evict the least
 recently used item.
 */
import java.util.HashMap;
public class Question25 {
    class Cache{
        int maxSize;
        int currentSize;
        Node head;
        Node tail;
        HashMap<String,Node> map;

        class Node{
            Node prev;
            Node next;
            String key;
            int value;

            public Node(String key, int value)
            {
                this.key = key;
                this.value = value;
                this.prev = null;
                this.next = null;
            }
        }

        public Cache(int maxSize)
        {
            this.maxSize = maxSize;
            this.currentSize = 0;
            this.map = new HashMap<String, Node>();
        }

        void removeTail()
        {
            if (tail == null)
                return;
            map.remove(tail.key);
            Node prev = tail.prev;
            if(prev == null) {
                tail = null;
                return;
            }
            prev.next = null;
            tail.prev = null;
            tail = prev;
        }

        void insert(String key, int value)
        {
            if(map.containsKey(key))
                return;

            Node n = new Node(key, value);

            if(head == null)
            {
                head = tail = n;
                map.put(key,n);
                return;
            }

            if(currentSize == maxSize)
                removeTail();

            n.next = head;
            head = n;
            map.put(key,n);
        }

        Integer find(String key)
        {
            if(head.key.equals(key))
                return head.value;

            if(!map.containsKey(key))
                return null;

            Node ptr = map.get(key);

            boolean isTail = false;
            if(ptr == tail)
                isTail = true;
            Node n = ptr.prev;
            n.next = ptr.next;
            if(!isTail)
                ptr.next.prev = n;
            else
                tail = n;
            ptr.prev = null;
            ptr.next = head;
            head = ptr;
            return ptr.value;
        }

    }
}

