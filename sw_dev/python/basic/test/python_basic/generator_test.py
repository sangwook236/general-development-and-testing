#!/usr/bin/env python

# REF [site] >> https://wiki.python.org/moin/Generators

import time, copy
import numpy as np

# yield is a keyword that is used like return, except the function will return a generator.
def simple_yield_example_1():
	def simple_generator():
		yield 1
		yield 2
		yield 3

	gen = simple_generator()
	print('type(gen) =', type(gen), gen)

	print('Next =', next(gen))
	print('Next =', next(gen))
	print('Next =', next(gen))
	#print('Next =', next(gen))  # Exception: StopIteration is raised.

	for val in gen:
		print('Generated value =', val)

	#--------------------
	for val in simple_generator():
		print('Generated value =', val)

	#--------------------
	def createGenerator():
		for val in range(3):
			yield val * val

	for val in createGenerator():
		print('Generated value =', val)

def simple_yield_example_2():
	def inner_generator_1():
		print('Entered inner_generator_1().')
		val = 0
		while val < 10:
			yield (val, val**2), val**3
			time.sleep(0.5)
			val += 1
		print('Exited inner_generator_1().')

	def inner_generator_2():
		print('Entered inner_generator_2().')
		with open('./generator_test_file.txt', 'r', encoding='utf-8') as fd:
			for line in fd.readlines():
				line = line.strip('\n').split(' ')
				yield int(line[0]), line[1]
				time.sleep(0.5)
		print('Exited inner_generator_2().')

	def return_generator():
		#return inner_generator_1()
		return inner_generator_2()

	def yield_generator():
		#yield inner_generator_1()
		yield inner_generator_2()

	gen1 = return_generator()
	print(type(gen1))
	for val in gen1:
		print('Generated value =', val)

	gen2 = yield_generator()
	print(type(gen2))
	for g in gen2:
		for val in g:
			print('Generated value =', val)

# Build and return a list.
def firstn_1(n):
	num, nums = 0, list()
	while num < n:
		nums.append(num)
		num += 1
	return nums

# Using the generator pattern (an iterable).
class firstn_2(object):
	def __init__(self, n):
		self.n = n
		self.num, self.nums = 0, list()

	def __iter__(self):
		return self

	# Python 3 compatibility.
	def __next__(self):
		return self.next()

	def next(self):
		if self.num < self.n:
			cur, self.num = self.num, self.num + 1
			return cur
		else:
			raise StopIteration()

# A generator that yields items instead of returning a list.
def firstn_3(n):
	num = 0
	while num < n:
		yield num
		num += 1

# Generators are iterators, but you can only iterate over them once.
# It's because they do not store all the values in memory, they generate the values on the fly.
def simple_generator_example():
	start = time.time()
	firstn_1_retval = firstn_1(1000000)
	sum_of_first_n_1 = sum(firstn_1_retval)
	print('Elapsed time = {}'.format(time.time() - start))
	print('type(firstn_1_retval) =', type(firstn_1_retval))
	print('sum_of_first_n_1 =', sum_of_first_n_1)

	start = time.time()
	firstn_2_retval = firstn_2(1000000)
	sum_of_first_n_2 = sum(firstn_2_retval)
	print('Elapsed time = {}'.format(time.time() - start))
	print('type(firstn_2_retval) =', type(firstn_2_retval))
	print('sum_of_first_n_2 =', sum_of_first_n_2)

	start = time.time()
	firstn_3_retval = firstn_3(1000000)
	sum_of_first_n_3 = sum(firstn_3_retval)
	print('Elapsed time = {}'.format(time.time() - start))
	print('type(firstn_3_retval) =', type(firstn_3_retval))
	print('sum_of_first_n_3 =', sum_of_first_n_3)

def reuse_generator_example():
	def create_generator(arr, length):
		num_arr = len(arr)
		start_idx = 0
		while True:
			end_idx = start_idx + length
			sub_arr = arr[start_idx:end_idx]
			yield sub_arr
			if end_idx >= num_arr:
				break
			start_idx = end_idx

	arr = np.arange(20)
	gen = create_generator(arr, 3)
	gen_copyed = gen
	#gen_copyed = copy.deepcopy(gen)  # TypeError: can't pickle generator objects.

	print('A generator is used first.')
	for idx, sa in enumerate(gen):
		print(idx, sa)

	# NOTE [info] >> Cannot use a generator again.
	print('A generator is used again.')
	for idx, sa in enumerate(gen_copyed):
		print(idx, sa)

def main():
	#simple_yield_example_1()
	simple_yield_example_2()

	#simple_generator_example()
	#reuse_generator_example()

#%%------------------------------------------------------------------

if '__main__' == __name__:
	main()
