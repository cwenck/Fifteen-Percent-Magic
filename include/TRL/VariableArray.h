/*
 * VariableArray.h
 *
 *  Created on: Apr 8, 2015
 *      Author: guywenck
 */

#ifndef VARIABLEARRAY_H_
#define VARIABLEARRAY_H_

#define DEFAULT_VARIABLE_ARRAY_SIZE 8
#define VARIABLE_ARRAY_CAPACITY_BUFFER 8

#include "LibraryFixes.h"
#include "PrintStream.h"

namespace TRL {
//Template member functions must all be defined in the .h file
	template <typename T> class VariableArray {
	private:
		T* arrayStart;
		int arraySize;
		int arrayCapacity;

		void initWithCapacity(int capacity) {
			arrayStart = new T[capacity];
			arraySize = 0;
			arrayCapacity = capacity;
			erase();
		}

		int getHighestUsedIndex() {
			int highest = arrayCapacity - 1;
			for (int i = highest; i >= 0; i--) {
				if (arrayStart[i] != NULL) {
					break;
				}
				highest--;
			}
			return highest;
		}

		void refreshArraySize(){
			arraySize = 1 + getHighestUsedIndex();
		}

		void expandToIndex(int index) {
			refreshArraySize();
			T* tempArrayStart = arrayStart;
			int tempArraySize = arraySize;

			//Expand Array If Necessary
			initWithCapacity(index + 1 + VARIABLE_ARRAY_CAPACITY_BUFFER);
			arraySize = tempArraySize;

			for (int i = 0; i < tempArraySize; i++) {
				arrayStart[i] = tempArrayStart[i];
			}

			delete[] tempArrayStart;
		}
	public:
		VariableArray() {
			initWithCapacity(DEFAULT_VARIABLE_ARRAY_SIZE);
		}

		VariableArray(int initialSize) {
			initWithCapacity(initialSize);
		}

		~VariableArray() {
			delete[] arrayStart;
		}

		void erase() {
			for (int i = 0; i < arrayCapacity; i++) {
				arrayStart[i] = NULL;
			}
		}

		void resize() {
			refreshArraySize();

			T* tempArrayStart = arrayStart;
			int tempArraySize = arraySize;

			if ((arrayCapacity - arraySize) < VARIABLE_ARRAY_CAPACITY_BUFFER) {
				//Expand Array If Necessary
				initWithCapacity(arraySize + VARIABLE_ARRAY_CAPACITY_BUFFER);
				arraySize = tempArraySize;

				for (int i = 0; i < tempArraySize; i++) {
					arrayStart[i] = tempArrayStart[i];
				}

				delete[] tempArrayStart;
			} else if ((arrayCapacity - arraySize) > VARIABLE_ARRAY_CAPACITY_BUFFER) {
				//Shrink Array If Possible
				initWithCapacity(arraySize + VARIABLE_ARRAY_CAPACITY_BUFFER);
				arraySize = tempArraySize;

				for (int i = 0; i < tempArraySize; i++) {
					arrayStart[i] = tempArrayStart[i];
				}

				delete[] tempArrayStart;
			}
		}

		T& operator[](int index) {
			return arrayStart[index];
		}

		T& get(int index) {
			return arrayStart[index];
		}

		void set(int index, T object) {
			if (index >= arrayCapacity) {
				this->expandToIndex(index);
			}
			arrayStart[index] = object;
			refreshArraySize();
		}

		/*
		 * Warning: this does not actually delete the objects stored in the array. It just stops pointing to it.
		 * So make sure you delete the actual object yourself first
		 */
		void eraseElementAtIndex(int index) {
			arrayStart[index] = NULL;
			refreshArraySize();
		}

		void add(T object) {
			refreshArraySize();
			set(arraySize, object);
		}

		T* toArray() {
			return arrayStart;
		}

		int getSize() {
			refreshArraySize();
			return arraySize;
		}

		int getCapacity() {
			return arrayCapacity;
		}
	};
}

#endif /* VARIABLEARRAY_H_ */
