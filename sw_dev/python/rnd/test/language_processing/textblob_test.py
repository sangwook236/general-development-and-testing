#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# REF [site] >> https://github.com/sloria/textblob

import textblob

def simple_example():
	text = '''
The titular threat of The Blob has always struck me as the ultimate movie
monster: an insatiably hungry, amoeba-like mass able to penetrate
virtually any safeguard, capable of--as a doomed doctor chillingly
describes it--"assimilating flesh on contact.
Snide comparisons to gelatin be damned, it's a concept with the most
devastating of potential consequences, not unlike the grey goo scenario
proposed by technological theorists fearful of
artificial intelligence run rampant.
'''

	blob = textblob.TextBlob(text)

	print('Tags:', blob.tags)
	print('Noun phrases:', blob.noun_phrases)

	for sentence in blob.sentences:
		print('Sentiment polarity = {}.'.format(sentence.sentiment.polarity))

def main():
	simple_augmentation_example()

#--------------------------------------------------------------------

if '__main__' == __name__:
	main()