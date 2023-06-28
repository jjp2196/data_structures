package abstract_classes.abstract_classes_java.implemented_subclasses_java;
import abstract_classes.abstract_classes_java.AbstractHashTable;

public class HashTable<K, V> extends AbstractHashTable<K, V> {

    @Override
    public V get(K key) {
        // Provide implementation for getting the value associated with the key
        return null;
    }

    @Override
    public void put(K key, V value) {
        // Provide implementation for adding the key-value pair to the hash table
    }

    @Override
    public V remove(K key) {
        // Provide implementation for removing the key-value pair from the hash table
        return null;
    }

    @Override
    public boolean containsKey(K key) {
        // Provide implementation for checking if the hash table contains the key
        return false;
    }

    @Override
    public boolean containsValue(V value) {
        // Provide implementation for checking if the hash table contains the value
        return false;
    }

    @Override
    public int size() {
        // Provide implementation for returning the size of the hash table
        return 0;
    }

    @Override
    public boolean isEmpty() {
        // Provide implementation for checking if the hash table is empty
        return false;
    }

    @Override
    public void clear() {
        // Provide implementation for clearing the hash table
    }

    @Override
    protected int hash(K key) {
        // Provide implementation for calculating the hash of the key
        return 0;
    }

    @Override
    protected int getIndex(K key) {
        // Provide implementation for calculating the index of the key in the hash table
        return 0;
    }
}
