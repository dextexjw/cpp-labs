
template <class T>
Set<T>::Set() {
}

template <class T>
Set<T>::Set(initializer_list<T> list) {
    for (const T& value : list) {
        add(value);
    }
}

template <class T>
bool Set<T>::contains(const T& value) const {
    for (const T& item : this->items) {
        if (item == value) {
            return true;
        }
    }
    return false;
}

template <class T>
bool Set<T>::add(const T& value) {
    if (contains(value)) {
        return false;
    }

    this->items.push_back(value);
    return true;
}

template <class T>
bool Set<T>::remove(const T& value) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == value) {
            items[i] = items[items.size() - 1];
            items.pop_back();
            return true;
        }
    }

    return false;
}

template <class T>
int Set<T>::size() const {
    return items.size();
}
