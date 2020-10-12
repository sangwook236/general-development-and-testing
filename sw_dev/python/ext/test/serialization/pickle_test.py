#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import pickle

def main():
	filepath = 'test.pkl'

	try:
		favorite_color = {'lion': 'yellow', 'kitty': 'red'}
		with open(filepath, 'wb') as fd:
			pickle.dump(favorite_color, fd)
	except FileNotFoundError as ex:
		print('File not found, {}: {}.'.format(filepath, ex))

	try:
		with open(filepath, 'rb') as fd:
			loaded = pickle.load(fd)
			print(loaded)
	except FileNotFoundError as ex:
		print('File not found, {}: {}.'.format(filepath, ex))

	#--------------------
	dumped = pickle.dumps(favorite_color)  # A bytes object.
	print(type(dumped))

	loaded = pickle.loads(dumped)
	print(loaded)

#--------------------------------------------------------------------

if '__main__' == __name__:
	main()
