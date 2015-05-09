/*
 * Array.h
 *
 *  Created on: Apr 27, 2015
 *      Author: guywenck
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdarg.h>
#include "LibraryFixes.h"
#include "PrintStream.h"

namespace TRL {
	template <typename T> class Array {
	protected:
		T* arrayStart;
		int arrSize;
	public:
		Array() {
			arrSize = 0;
			arrayStart = NULL;
		}

		Array(int size) {
			this->arrSize = size;
			arrayStart = new T[size];
		}

		Array(int size, T* arr) {
			this->arrSize = size;
			arrayStart = new T[size];
			for(int i = 0; i < size; i++) {
				arrayStart[i] = arr[i];
			}
		}

		/*
		 * Initializes the array with some starting values
		 * @param numberInitialValuesPassed must match the number of starting values passed afterward
		 * @param ... any values you want to be initialized. They will be initialized from 0 to (numberInitialValuesPassed - 1)
		 */
		Array(int arrSize, int numberInitialValuesPassed,...) {
			this->arrSize = arrSize;
			arrayStart = new T[arrSize];

			va_list arg;
			va_start(arg, numberInitialValuesPassed);
			{
				for(int i = 0; i < numberInitialValuesPassed; i++) {
					arrayStart[i] = (va_arg(arg,T));
				}

			}
			va_end(arg);
		}

		virtual ~Array() {
			delete[] arrayStart;
		}

		/* The value returned can be read from and written to because
		 * it has the same address as the particular location in the array.
		 */
		T& operator[](int index) {
			return arrayStart[index];
		}

		/* The value returned can be read from and written to because
		 * it has the same address as the particular location in the array.
		 */
		T& at(int index) {
			return arrayStart[index];
		}

		/* The value returned can be read from and written to because
		 * it has the same address as the particular location in the array.
		 */
		T& get(int index) {
			return arrayStart[index];
		}

		T& start() {
			return arrayStart(0);
		}

		T& last() {
			return arrayStart[size - 1];
		}

		void set(int index, T& value) {
			arrayStart[index] = value;
		}

		int size() {
			return arrSize;
		}

		void reinitWithNewSize(int newSize) {
			if(size() != 0){
				delete[] arrayStart;
			}
			this->arrSize = newSize;
			arrayStart = new T[newSize];
		}

		/*
		 * Alias for size()
		 */
		int length() {
			return arrSize;
		}
	};
}

#endif /* ARRAY_H_ */
