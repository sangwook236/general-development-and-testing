#!/usr/bin/env python
# coding: utf-8

import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# REF [site] >> https://librosa.github.io/librosa/generated/librosa.feature.melspectrogram.html
def melspectrogram_test():
	y, sr = librosa.load(librosa.util.example_audio_file())
	librosa.feature.melspectrogram(y=y, sr=sr)

	D = np.abs(librosa.stft(y))**2
	S = librosa.feature.melspectrogram(S=D, sr=sr)

	# Passing through arguments to the Mel filters.
	S = librosa.feature.melspectrogram(y=y, sr=sr, n_mels=128, fmax=8000)
	#S = librosa.feature.melspectrogram(y=y, sr=sr, n_fft=512, n_mels=128, fmax=8000)

	plt.figure(figsize=(10, 4))
	S_dB = librosa.power_to_db(S, ref=np.max)
	librosa.display.specshow(S_dB, x_axis='time', y_axis='mel', sr=sr, fmax=8000)
	plt.colorbar(format='%+2.0f dB')
	plt.title('Mel-frequency Spectrogram')
	plt.tight_layout()
	plt.show()

def main():
	melspectrogram_test()

#--------------------------------------------------------------------

if '__main__' == __name__:
	main()
