package abstract_classes.abstract_classes_java;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractHashTable<K, V> {

    // Def_Cap sets the Initial Size of the Table
    // Larger has more space and needs less rehashing
    // But smaller has less need for storage
    protected static final int DEFAULT_CAPACITY = 10;

    // Def_Load_Fac sets how full we need to be before we resize (rehash)
    protected static final double DEFAULT_LOAD_FACTOR = 0.75;

    // Initializes the traits of a given HashTable
    protected List<ArrayList<Entry<K, V>>> table;
    protected int size;
    protected double loadFactor;
    protected int threshold;

    // Allows us to create a Key, Value pair for info entry
    protected static class Entry<K, V> {
        K key;
        V value;

        Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    // Initializes the HashTable, gives us a Def_Cap and Def_Load_Fac
    public AbstractHashTable() {
        this(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR);
    }

    // Initializes the hashtable with more attributes this time
    // like size and loadfactor and threshold
    public AbstractHashTable(int capacity, double loadFactor) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Invalid capacity: " + capacity);
        }
        if (loadFactor <= 0.0 || loadFactor >= 1.0) {
            throw new IllegalArgumentException("Invalid load factor: " + loadFactor);
        }

        this.table = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            this.table.add(null);
        }
        this.size = 0;
        this.loadFactor = loadFactor;
        this.threshold = (int) (capacity * loadFactor);
    }

    // searches for a key
    public abstract V get(K key);

    // adds a key, value pair
    public abstract void put(K key, V value);

    // removes a key, value pair (based on a key)
    public abstract V remove(K key);

    // returns true/false if we have a certain key added
    public abstract boolean containsKey(K key);

    // returns true/false if we have a certain value added
    public abstract boolean containsValue(V value);

    public abstract int size();

    public abstract boolean isEmpty();

    public abstract void clear();

    // returns the hash of the key
    protected abstract int hash(K key);

    // returns index of key
    protected abstract int getIndex(K key);

    // resizes the hashmap when we're at .75 percent capacity
    // creates a new table with ArrayList, transfers our data
    protected void resize(int newCapacity) {
        List<ArrayList<Entry<K, V>>> newTable = new ArrayList<>(newCapacity);
        for (int i = 0; i < newCapacity; i++) {
            newTable.add(null);
        }
        transfer(newTable);
        table = newTable;
        threshold = (int) (newCapacity * loadFactor);
    }

    // transfers each key value pair to new tablee
    protected void transfer(List<ArrayList<Entry<K, V>>> newTable) {
        for (ArrayList<Entry<K, V>> entryList : table) {
            if (entryList != null) {
                for (Entry<K, V> entry : entryList) {
                    int index = getIndex(entry.key);
                    ArrayList<Entry<K, V>> newList = newTable.get(index);
                    if (newList == null) {
                        newList = new ArrayList<>();
                        newTable.set(index, newList);
                    }
                    newList.add(entry);
                }
            }
        }
    }
}
