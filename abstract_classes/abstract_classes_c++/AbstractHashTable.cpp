#include <vector>
#include <list>

template<typename K, typename V>
class AbstractHashTable {
protected:
    static const int DEFAULT_CAPACITY = 10;
    static const double DEFAULT_LOAD_FACTOR;

    typedef std::pair<K, V> Entry;
    typedef std::list<Entry> EntryList;
    typedef std::vector<EntryList> Table;

    Table table;
    int size;
    double loadFactor;
    int threshold;

public:
    AbstractHashTable() : AbstractHashTable(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR) {}

    AbstractHashTable(int capacity, double loadFactor) : size(0), loadFactor(loadFactor) {
        if (capacity <= 0) {
            throw std::invalid_argument("Invalid capacity: " + std::to_string(capacity));
        }
        if (loadFactor <= 0.0 || loadFactor >= 1.0) {
            throw std::invalid_argument("Invalid load factor: " + std::to_string(loadFactor));
        }

        table.resize(capacity);
        threshold = static_cast<int>(capacity * loadFactor);
    }

    virtual V get(K key) = 0;
    virtual void put(K key, V value) = 0;
    virtual V remove(K key) = 0;
    virtual bool containsKey(K key) = 0;
    virtual bool containsValue(V value) = 0;
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual void clear() = 0;

    int hash(K key) {
        // Implement your own hash function here
    }

    int getIndex(K key) {
        int hashCode = hash(key);
        return hashCode % table.size();
    }

    void resize(int newCapacity) {
        Table newTable(newCapacity);
        threshold = static_cast<int>(newCapacity * loadFactor);

        for (const auto& entryList : table) {
            for (const auto& entry : entryList) {
                int index = getIndex(entry.first);
                EntryList& newList = newTable[index];
                newList.push_back(entry);
            }
        }

        table = std::move(newTable);
    }
};

template<typename K, typename V>
const double AbstractHashTable<K, V>::DEFAULT_LOAD_FACTOR = 0.75;
