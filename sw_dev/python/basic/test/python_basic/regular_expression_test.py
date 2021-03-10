#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# REF [site] >>
#	https://docs.python.org/3/library/re.html
#	https://docs.python.org/3/howto/regex.html

import re

def basic_operation():
	r"""
	# Special sequence.
	\number \A \b \B \d \D \s \S \w \W \Z

	# Standard escape.
	\a \b \f \n \N \r \t \u \U \v \x \\

	# Flag.
	re.A, re.ASCII
	re.I, re.IGNORECASE
	re.L, re.LOCALE
	re.M, re.MULTILINE
	re.S, re.DOTALL
	re.U, re.UNICODE
	re.X, re.VERBOSE

	re.DEBUG

	re.search(pattern, string, flags=0)
	re.match(pattern, string, flags=0)
	re.fullmatch(pattern, string, flags=0)
	re.split(pattern, string, maxsplit=0, flags=0)
	re.findall(pattern, string, flags=0)
	re.finditer(pattern, string, flags=0)
	re.sub(pattern, repl, string, count=0, flags=0)
	re.subn(pattern, repl, string, count=0, flags=0)

	re.escape(pattern)

	re.purge()
	"""

	re.split(r'\W+', 'Words, words, words.')
	re.split(r'(\W+)', 'Words, words, words.')
	re.split(r'\W+', 'Words, words, words.', 1)
	re.split('[a-f]+', '0a3B9', flags=re.IGNORECASE)
	re.split(r'(\W+)', '...words, words...')

	def dash_repl(match):
		if match.group(0) == '-': return ' '
		else: return '-'
	re.sub('-{1,2}', '-', 'pro----gram-files')
	re.sub('-{1,2}', dash_repl, 'pro----gram-files')
	re.sub(r'\sAND\s', ' & ', 'Baked Beans And Spam', flags=re.IGNORECASE)

	re.subn('-{1,2}', dash_repl, 'pro----gram-files')
	re.subn(r'\sAND\s', ' & ', 'Baked Beans And Spam', flags=re.IGNORECASE)

	re.escape('http://www.python.org')

	try:
		re.compile('[a-z+')
	except re.error as ex:
		print('re.error: {}.'.format(ex))

	#--------------------
	# Regular expression object.

	"""
	re.compile(pattern, flags=0)

	Pattern.search(string, pos, endpos)
	Pattern.match(string, pos, endpos)
	Pattern.fullmatch(string, pos, endpos)
	Pattern.split(string, maxsplit=0)
	Pattern.findall(string, pos, endpos)
	Pattern.finditer(string, pos, endpos)
	Pattern.sub(repl, string, count=0)
	Pattern.subn(repl, string, count=0)

	Pattern.flags
	Pattern.groups
	Pattern.groupindex
	Pattern.pattern
	"""

	pattern = re.compile('[a-z]+')
	#pattern = re.compile('[a-z]+', re.IGNORECASE)
	#pattern = re.compile(r'(\w+) (\w+)')
	#pattern = re.compile(r'\d+\.\d*', re.X)

	pattern = re.compile('d')
	pattern.search('dog')  # Match at index 0.
	pattern.search('dog', 1)  # No match; search doesn't include the 'd'.

	pattern = re.compile("o")
	pattern.match('dog')  # No match as 'o' is not at the start of 'dog'.
	pattern.match('dog', 1)  # Match as 'o' is the 2nd character of 'dog'.

	pattern = re.compile('o[gh]')
	pattern.fullmatch('dog')  # No match as "o" is not at the start of 'dog'.
	pattern.fullmatch('ogre')  # No match as not the full string matches.
	pattern.fullmatch('doggie', 1, 3)  # Matches within given limits.

	pattern = re.compile(r'\d+')
	print(pattern.findall('12 drummers drumming, 11 pipers piping, 10 lords a-leaping'))

	iterator = pattern.finditer('12 drummers drumming, 11 ... 10 ...')
	for match in iterator:
		print(match.span())

	#--------------------
	# Match object.

	"""
	Match.expand()
	Match.group()
	Match.groups()
	Match.groupdict()
	Match.start()
	Match.end()
	Match.span()

	Match.pos
	Match.endpos
	Match.lastindex
	Match.lastgroup
	Match.re
	Match.string
	"""

	pattern = re.compile('[a-z]+')

	print(pattern)
	print(pattern.match(''))

	match = pattern.match('tempo')
	if match:
		print(match)
		print(match.group())
		print(match.start(), match.end())
		print(match.span())
	else:
		print('No match')

	match = re.match(r'(\w+) (\w+)', 'Isaac Newton, physicist')
	match.group(0)  # The entire match.
	match.group(1)  # The first parenthesized subgroup.
	match.group(2)  # The second parenthesized subgroup.
	match.group(1, 2)  # Multiple arguments give us a tuple.

	match = re.match(r'(?P<first_name>\w+) (?P<last_name>\w+)', 'Malcolm Reynolds')
	match.group('first_name')
	match.group('last_name')
	match.group(1)
	match.group(2)

	# If a group matches multiple times, only the last match is accessible.
	match = re.match(r'(..)+', 'a1b2c3')  # Matches 3 times.
	match.group(1)  # Returns only the last match.

	match = re.match(r'(\d+)\.(\d+)', '24.1632')
	match.groups()

	match = re.match(r'(\d+)\.?(\d+)?', '24')
	match.groups()  # Second group defaults to None.
	match.groups('0')  # The second group defaults to '0'.

	match = re.match(r'(?P<first_name>\w+) (?P<last_name>\w+)', 'Malcolm Reynolds')
	match.groupdict()

# REF [site] >> Commonly used regular expressions.
#	https://digitalfortress.tech/tricks/top-15-commonly-used-regex/
def commonly_used_expressions():
	# Roman numerals.
	#	I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000.

	# REF [site] >> https://www.oreilly.com/library/view/regular-expressions-cookbook/9780596802837/ch06s09.html
	#roman_numeral_pattern = re.compile(r'^[MDCLXVI]+$', re.I)  # No validation.
	roman_numeral_pattern = re.compile(r'^(?=[MDCLXVI])M*(C[MD]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$', re.I)  # Strict.
	#roman_numeral_pattern = re.compile(r'^(?=[MDCLXVI])M*(C[MD]|D?C*)(X[CL]|L?X*)(I[XV]|V?I*)$', re.I)  # Flexible.
	#roman_numeral_pattern = re.compile(r'^(?=[MDCLXVI])M*D?C{0,4}L?X{0,4}V?I{0,4}$', re.I)  # Simple.
	# REF [site] >> https://stackoverflow.com/questions/267399/how-do-you-match-only-valid-roman-numerals-with-a-regular-expression
	#roman_numeral_pattern = re.compile(r'^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$', re.I)

	roman_numerals_correct = [
		'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX', 'X',
		'XI', 'XII', 'XIII', 'XIV', 'XV', 'XVI', 'XVII', 'XVIII', 'XIX', 'XX',
		'i', 'ii', 'iii', 'iv', 'v', 'vi', 'vii', 'viii', 'ix', 'x',
		'xi', 'xii', 'xiii', 'xiv', 'xv', 'xvi', 'xvii', 'xviii', 'xix', 'xx',
	]
	roman_numerals_incorrect = [
		'I.',
		'IIII',
		'IIV', 'VIIII', 'VV',
		'IIX','XIIII',
	]

	for ss in roman_numerals_correct:
		match = roman_numeral_pattern.match(ss)
		if match is None:
			print('Roman numeral correct (unmatched): {}.'.format(ss))
		elif ss != match[0]:
			print('Roman numeral correct (partially matched): {} != {}.'.format(match[0], ss))

	for ss in roman_numerals_incorrect:
		#match = roman_numeral_pattern.match(ss)
		match = roman_numeral_pattern.fullmatch(ss)
		if match is not None:
			if ss == match[0]:
				print('Roman numeral incorrect (matched): {}.'.format(ss))
			else:
				print('Roman numeral incorrect (partially matched): {} != {}.'.format(match[0], ss))

	#--------------------
	# HTML tag.
	html_tag_pattern = re.compile(r'<\/?[\w\s]*>|<.+[\W]>')

def page_object_example():
	# Basic pattern.
	#re_pattern = re.compile(r'([0-9]+\.)*[0-9]+\.?')  # 1, 2., 1.2, 2.3., ...
	re_pattern = re.compile(r'(\d+\.)*\d+\.?')  # 1, 2., 1.2, 2.3., ...
	re_pattern = re.compile(r'[A-Za-z]\d*\.')  # A. B1., c2., ...
	# NOTE [info] >> As the target string is scanned, REs separated by '|' are tried from left to right.
	re_pattern = re.compile(r'([A-Za-z]\d*\.)?(\d+\.)*\d+\.?|[A-Za-z]\d*\.')
	re_pattern = re.compile(r'(([A-Za-z]\d*\.)?(\d+\.)*\d+\.?|[A-Za-z]\d*\.)\s+.+')

	#--------------------
	numberings_correct = [
		'3.', '3)', '(3)',
		'12345.', '12345)', '(12345)',
		'1.2', '1.2.', '1.2)', '(1.2)',
		'1.2.3.4.5', '1.2.3.4.5.', '1.2.3.4.5)', '(1.2.3.4.5)',
		'b.', 'b)', '(b)',
		'b.2', 'b.2.', 'b.2)', '(b.2)',
		'b137.', 'b137)', '(b137)',
		'b.1.2', 'b.1.2.', 'b.1.2)', '(b.1.2)',
		'b1.2', 'b1.2.', 'b1.2)', '(b1.2)',
		'b.1.2.3.4.5', 'b.1.2.3.4.5.', 'b.1.2.3.4.5)', '(b.1.2.3.4.5)',
		'b1.2.3.4.5', 'b1.2.3.4.5.', 'b1.2.3.4.5)', '(b1.2.3.4.5)',
	]
	numberings_incorrect = [
		'3', '12', '12345',
		'.3', '.12', '.12345',
		'b', 'b2', '2b', 'ab',
		'b.a1.2', 'b.a1.2.',
		'b.a.1.2', 'b.a.1.2.',
		'ab.1.2.3.4.5', 'ab.1.2.3.4.5.',
		'2b.1.2', '2b.1.2.',
		'2b.1.2.3.4.5', '2b.1.2.3.4.5.',
		'.b.1.2', '.b.1.2.',
		'.b.1.2.3.4.5', '.b.1.2.3.4.5.',
	]

	#--------------------
	# For numbering.
	if False:
		#re_pattern = re.compile(r'\(?([A-Za-z]\d*\.)?(\d+\.)*\d+\)|([A-Za-z]\d*\.)?(\d+\.)*\d+\.?|\(?[A-Za-z]\d*\)|[A-Za-z]\d*\.')
		re_pattern = re.compile(r'\(?([A-Za-z]\d*\.)?(\d+\.)*\d+\)|[A-Za-z]\d*\.(\d+\.)*\d+\.?|(\d+\.)+\d+\.?|\d+\.|\(?[A-Za-z]\d*\)|[A-Za-z]\d*\.')

		for ss in numberings_correct:
			match = re_pattern.match(ss)
			if match is None:
				print('Numbering correct (unmatched): {}.'.format(ss))
			elif ss != match[0]:
				print('Numbering correct (partially matched): {} != {}.'.format(match[0], ss))
			#else:
			#z	print('Numbering correct (matched): {}.'.format(ss))

		for ss in numberings_incorrect:
			#match = re_pattern.match(ss)
			match = re_pattern.fullmatch(ss)
			if match is not None:
				if ss == match[0]:
					print('Numbering incorrect (matched): {}.'.format(ss))
				else:
					print('Numbering incorrect (partially matched): {} != {}.'.format(match[0], ss))

	#--------------------
	# For heading.
	if False:
		heading_formats = [
			'{} Introduction',
			'{} Introduction.',
			'{} Experimental results',
			'{} Experimental results.',
			'{} Experimental results!',
			'{} Introduction. Experimental results',
			'{} Introduction. Experimental results.',
		]

		#re_pattern = re.compile(r'(\(?([A-Za-z]\d*\.)?(\d+\.)*\d+\)|([A-Za-z]\d*\.)?(\d+\.)*\d+\.?|\(?[A-Za-z]\d*\)|[A-Za-z]\d*\.)\s+.+')
		re_pattern = re.compile(r'(\(?([A-Za-z]\d*\.)?(\d+\.)*\d+\)|[A-Za-z]\d*\.(\d+\.)*\d+\.?|(\d+\.)+\d+\.?|\d+\.|\(?[A-Za-z]\d*\)|[A-Za-z]\d*\.)\s+.+')

		for head_fmt in heading_formats:
			for numbering in numberings_correct:
				ss = head_fmt.format(numbering)

				match = re_pattern.match(ss)
				if match is None:
					print('Heading correct (unmatched): {}.'.format(ss))
				elif ss != match[0]:
					print('Heading correct (partially matched): {} != {}.'.format(match[0], ss))

			for numbering in numberings_incorrect:
				ss = head_fmt.format(numbering)

				#match = re_pattern.match(ss)
				match = re_pattern.fullmatch(ss)
				if match is not None:
					if ss == match[0]:
						print('Heading incorrect (matched): {}.'.format(ss))
					else:
						print('Heading incorrect (partially matched): {} != {}.'.format(match[0], ss))

		#--------------------

		simple_headings_correct = [
			'Table 0', 'TABLE 0.',
			'figure 13', 'FIGURE 13.',
			'APPendix 297', 'AppEndiX 297.',
		]
		simple_headings_incorrect = [
			'Tablea 0', 'TABLE 0)',
			'figure (13', 'PIGURE 13.',
			'APPendix 297]', '0AppEndiX 297.',
		]

		re_pattern = re.compile(r'([Tt][Aa][Bb][Ll][Ee]|[Ff][Ii][Gg][Uu][Rr][Ee]|[Aa][Pp]{2}[Ee][Nn][Dd][Ii][Xx])\s+\d+\.?')

		for ss in simple_headings_correct:
			match = re_pattern.match(ss)
			if match is None:
				print('Simlple heading correct (unmatched): {}.'.format(ss))
			elif ss != match[0]:
				print('Simlple heading correct (partially matched): {} != {}.'.format(match[0], ss))

		for ss in simple_headings_incorrect:
			#match = re_pattern.match(ss)
			match = re_pattern.fullmatch(ss)
			if match is not None:
				if ss == match[0]:
					print('Simlple heading incorrect (matched): {}.'.format(ss))
				elif ss != match[0]:
					print('Simlple heading incorrect (partially matched): {} != {}.'.format(match[0], ss))

	#--------------------
	# For list.
	if True:
		list_paragraph_formats = [
			'{1} studies not conducted in SSA{0} {2} studies that were reviews, case reports, or case series{0} {3} studies that did not relate epidemiologic data{0} {4} studies that did not discuss dementia or its subtypes in individuals aged 60 years and above.',
			#'{1} studies not conducted in SSA{0} {2} studies that were reviews, case reports, or case series{0} {3} studies that did not relate epidemiologic data{0} {4} studies that did not discuss dementia or its subtypes in individuals aged 60 years and above. VII.',
			#'studies not conducted in SSA{0} studies that were reviews, case reports, or case series{0} studies that did not relate epidemiologic data{0} studies that did not discuss dementia or its subtypes in individuals aged 60 years and above.',
			#'{1} {2}',
		]
		list_separators = [';', ':', ',', '.']

		list_numbering_formats = ['({})', '{})', '{}.']
		list_indices_lst = [
			[1, 2, 3, 4], [3, 4, 5, 6], [9, 10, 11, 12], [1279, 1280, 1281, 1282],
			['a', 'b', 'c', 'd'], ['c', 'd', 'e', 'f'],
			['A', 'B', 'C', 'D'], ['C', 'D', 'E', 'F'],
			['i', 'ii', 'iii', 'iv'], ['iii', 'iv', 'v', 'vi'], ['ix', 'x', 'xi', 'xii'],
			['I', 'II', 'III', 'IV'], ['III', 'IV', 'V', 'VI'], ['IX', 'X', 'XI', 'XII'],
			# Error cases.
			#['XIi', 'iXII', '0XII', 'XI0'],
		]
		list_bullets = ['•', '‣']

		#re_pattern = re.compile(r'(\(?\d+\)|\d+\.|\(?[a-zA-Z]\)|[a-zA-Z]\.)')  # Not correct.
		#re_pattern = re.compile(r'\(?\b\d+\b\)|\b\d+\b\.|\(?\b[a-zA-Z]\b\)|\b[a-zA-Z]\b\.')  # Digit and alphabet.
		#re_pattern = re.compile(r'(\(?\b\d+\b\)|\b\d+\b\.|\(?\b[a-zA-Z]\b\)|\b[a-zA-Z]\b\.)')  # Digit and alphabet.
		#re_pattern = re.compile(r'\(?\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\)|\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\.|\(?\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\)|\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\.')  # Roman numerals (1 ~ 13).
		#re_pattern = re.compile(r'(\(?\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\)|\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\.|\(?\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\)|\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\.)')  # Roman numerals (1 ~ 13).
		#re_pattern = re.compile(r'\(?\b\d+\b\)|\b\d+\b\.|\(?\b[a-zA-Z]\b\)|\b[a-zA-Z]\b\.|\(?\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\)|\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\.|\(?\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\)|\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\.|•')
		re_pattern = re.compile(r'(\(?\b\d+\b\)|\b\d+\b\.|\(?\b[a-zA-Z]\b\)|\b[a-zA-Z]\b\.|\(?\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\)|\b(?:i{1,3}|i[vx]|[vx]i{0,3})\b\.|\(?\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\)|\b(?:I{1,3}|I[VX]|[VX]I{0,3})\b\.|•)')

		for para_fmt in list_paragraph_formats:
			for lst_sep in list_separators:
				for num_fmt in list_numbering_formats:
					for indices in list_indices_lst:
						ss = para_fmt.format(lst_sep, *[num_fmt.format(idx) for idx in indices])

						occurrences = re_pattern.split(ss)
						print('Occurrences split (len = {}): {}.'.format(len(occurrences), occurrences))
						matches_found = re_pattern.findall(ss)
						print('Matches found (len = {}): {}.'.format(len(matches_found), matches_found))

				for bullet in list_bullets:
					ss = para_fmt.format(lst_sep, *([bullet] * 4))

					occurrences = re_pattern.split(ss)
					print('Occurrences split (len = {}): {}.'.format(len(occurrences), occurrences))
					matches_found = re_pattern.findall(ss)
					print('Matches found (len = {}): {}.'.format(len(matches_found), matches_found))

def main():
	#basic_operation()
	commonly_used_expressions()
	
	#--------------------
	#page_object_example()

#--------------------------------------------------------------------

if '__main__' == __name__:
	main()
