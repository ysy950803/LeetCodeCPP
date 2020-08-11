#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key, value;
    Node *pre{}, *next{};

    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LinkedNodeList {
private:
    Node *head, *tail;

    static void remove(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->pre = nullptr;
        node->next = nullptr;
    }

public:
    LinkedNodeList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    Node *addRecent(Node *node) {
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
        return node;
    }

    int moveToRecent(Node *node) {
        remove(node);
        addRecent(node);
        return node->value;
    }

    int removeOldest() {
        Node *oldest = head->next;
        remove(oldest);
        return oldest->key;
    }
};

class LRUCache {
private:
    unordered_map<int, Node *> map;
    LinkedNodeList *cache = new LinkedNodeList();
    int capacity;

public:
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            // 没找到
            return -1;
        }
        return cache->moveToRecent(map[key]);
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node *node = map[key];
            node->value = value;
            cache->moveToRecent(node);
            return;
        }

        if (map.size() >= capacity) {
            map.erase(cache->removeOldest());
        }
        map[key] = cache->addRecent(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void test146() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    int v = cache.get(1); // returns 1
    cout << v << endl;
    cache.put(3, 3); // evicts key 2
    v = cache.get(2); // returns -1 (not found)
    cout << v << endl;
    cache.put(4, 4); // evicts key 1
    v = cache.get(1); // returns -1 (not found)
    cout << v << endl;
    v = cache.get(3); // returns 3
    cout << v << endl;
    v = cache.get(4); // returns 4
    cout << v << endl;
}
