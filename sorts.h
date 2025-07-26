#ifndef SORTS_H
#define SORTS_H

#include <vector>

//insertion sort default ascending, comparator decides
template <typename T, typename Compare>
void insertionSort(std::vector<T>& list, Compare comp) {
    for (size_t i = 1; i < list.size(); ++i) {
        T key = list[i];
        int j = i - 1;
        while (j >= 0 && comp(key, list[j])) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

//merge helper
template <typename T, typename Compare>
void merge(std::vector<T>& list, int left, int mid, int right, Compare comp) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = list[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}

//merge sort
template <typename T, typename Compare>
void mergeSort(std::vector<T>& list, int left, int right, Compare comp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(list, left, mid, comp);
        mergeSort(list, mid + 1, right, comp);
        merge(list, left, mid, right, comp);
    }
}

//wrapper
template <typename T, typename Compare>
void mergeSort(std::vector<T>& list, Compare comp) {
    if (list.size() > 1)
        mergeSort(list, 0, list.size() - 1, comp);
}

#endif
