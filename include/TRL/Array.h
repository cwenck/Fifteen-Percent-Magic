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
	private:
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
			arrayStart = arr;
		}

		/*Array(int size, ...) {
			this->arrSize = size;
			arrayStart = new T[size];

			va_list arg;
			va_start(arg, size);
			{
				for(int i = 0; i < size; i++) {
					arrayStart[i] = (va_arg(arg,T));
				}

			}
			va_end(arg);
		}*/

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
		T& get(int index) {
			return arrayStart[index];
		}

		void set(int index, T& value) {
			arrayStart[index] = value;
		}

		/* The value returned can be read from and written to because
		 * it has the same address as the particular location in the array.
		 */
		T& at(int index) {
			return arrayStart[index];
		}

		int size() {
			return arrSize;
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
