/*
 * VariableArray.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

//#include "TRL/VariableArray.h"
//
//namespace TRL {
//
//template<class T> VariableArray<T>::VariableArray() {
//	initWithCapacity(DEFAULT_VARIABLE_ARRAY_SIZE);
//}
//
//template<class T> VariableArray<T>::VariableArray(int initialSize) {
//	initWithCapacity(initialSize);
//}
//
//template<class T> VariableArray<T>::~VariableArray() {
//	delete[] arrayStart;
//}
//
//template<class T> void VariableArray<T>::initWithCapacity(int capacity) {
//	arrayStart = new T[capacity];
//	arraySize = 0;
//	arrayCapacity = capacity;
//	erase();
//}
//
//template<class T> void VariableArray<T>::erase() {
//	for (int i = 0; i < arrayCapacity; i++) {
//		arrayStart[i] = NULL;
//	}
//}
//
//template<class T> void VariableArray<T>::resize() {
//	T* tempArrayStart = arrayStart;
//	int tempArraySize = arraySize;
//	int tempArrayCapacity = arrayCapacity;
//
//	getHighestUsedIndex();
//
//	if ((arrayCapacity - arraySize) < VARIABLE_ARRAY_CAPACITY_BUFFER) {
//		//Expand Array If Necessary
//		initWithCapacity(arraySize + VARIABLE_ARRAY_CAPACITY_BUFFER);
//		arraySize = tempArraySize;
//
//		for (int i = 0; i < tempArraySize; i++) {
//			arrayStart[i] = tempArrayStart[i];
//		}
//
//		delete[] tempArrayStart;
//	} else if ((arrayCapacity - arraySize) > VARIABLE_ARRAY_CAPACITY_BUFFER) {
//		//Shrink Array If Possible
//		initWithCapacity(arraySize + VARIABLE_ARRAY_CAPACITY_BUFFER);
//		arraySize = tempArraySize;
//
//		for (int i = 0; i < tempArraySize; i++) {
//			arrayStart[i] = tempArrayStart[i];
//		}
//
//		delete[] tempArrayStart;
//	}
//}
//
//template<class T> void VariableArray<T>::expandToIndex(int index) {
//	T* tempArrayStart = arrayStart;
//	int tempArraySize = arraySize;
//	int tempArrayCapacity = arrayCapacity;
//
//	//Expand Array If Necessary
//	initWithCapacity(index + VARIABLE_ARRAY_CAPACITY_BUFFER);
//	arraySize = tempArraySize;
//
//	for (int i = 0; i < tempArraySize; i++) {
//		arrayStart[i] = tempArrayStart[i];
//	}
//
//	delete[] tempArrayStart;
//}
//
//template<class T> int VariableArray<T>::getHighestUsedIndex() {
//	int highest = arrayCapacity - 1;
//	for (int i = highest; i >= 0; i--) {
//		if (arrayStart[i] != NULL) {
//			break;
//		}
//		highest--;
//	}
//	return highest;
//}
//
//template<class T> T& VariableArray<T>::operator[](int index) {
//	return arrayStart[index];
//}
//
//template<class T> T& VariableArray<T>::get(int index) {
//	return arrayStart[index];
//}
//
//template<class T> void VariableArray<T>::set(int index, T object) {
//	if (index >= arrayCapacity) {
//		expandToIndex(index);
//	}
//	arrayStart[index] = object;
//	arraySize = getHighestUsedIndex();
//}
//
///*
// * Warning: this does not actually delete the objects stored in the array. It just stops pointing to it.
// * So make sure you delete the actual object yourself first
// */
//template<class T> void VariableArray<T>::eraseElementAtIndex(int index) {
//	arrayStart[index] = NULL;
//	arraySize = getHighestUsedIndex();
//}
//
//template<class T> void VariableArray<T>::addToEnd(T object) {
//	set(arraySize + 1, object);
//}
//
//template<class T> T* VariableArray<T>::toArray() {
//	return arrayStart;
//}
//
//template<class T> int VariableArray<T>::getSize() {
//	return arraySize();
//}
//
//} /* namespace TRL */
