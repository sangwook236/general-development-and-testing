#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# REF [site] >> https://github.com/cocodataset/cocoapi

import os, math, functools, time
import numpy as np
import pycocotools.coco

def vsualize_annotations(image, annotations, coco, font):
	''' Draws the segmentation, bounding box, and label of each annotation
	'''

	from PIL import ImageDraw

	# Define color code.
	colors = [(0, 0, 255), (0, 255, 0), (255, 0, 0), (0, 255, 255), (255, 0, 255), (255, 255, 0)]

	draw = ImageDraw.Draw(image, 'RGBA')
	for annotation in annotations:
		cat_name = coco.loadCats(ids=[annotation['category_id']])[0]['name']
		bbox = annotation['bbox']  # (left, top, width, height).

		color = colors[(annotation['category_id'] - 1) % len(colors)]

		# Draw segmentation.
		draw.polygon(annotation['segmentation'][0], fill=color + (64,))
		# Draw bbox.
		draw.rectangle(
			(bbox[0], bbox[1], bbox[0] + bbox[2], bbox[1] + bbox[3]),
			outline=color + (255,),
			width=2
		)
		# Draw label.
		w, h = draw.textsize(text=cat_name, font=font)
		if bbox[3] < h:
			draw.rectangle(
				(bbox[0] + bbox[2], bbox[1], bbox[0] + bbox[2] + w, bbox[1] + h),
				fill=(64, 64, 64, 255)
			)
			draw.text(
				(bbox[0] + bbox[2], bbox[1]),
				text=cat_name,
				fill=(255, 255, 255, 255),
				font=font
			)
		else:
			draw.rectangle(
				(bbox[0], bbox[1], bbox[0] + w, bbox[1] + h),
				fill=(64, 64, 64, 255)
			)
			draw.text(
				(bbox[0], bbox[1]),
				text=cat_name,
				fill=(255, 255, 255, 255),
				font=font
			)
	return np.array(image)

# REF [site] >> https://cocodataset.org/#format-data
def simple_example():
	if False:
		annotation_filepath = '/path/to/annotation.json'
		data_dir_path = '/path/to/data'
	elif False:
		if 'posix' == os.name:
			data_base_dir_path = '/home/sangwook/work/dataset'
		else:
			data_base_dir_path = 'D:/work/dataset'
		publaynet_dir_path = data_base_dir_path + '/text/layout/publaynet/publaynet'

		#annotation_filepath = publaynet_dir_path + '/train.json'
		annotation_filepath = publaynet_dir_path + '/val.json'

		if 'train' in annotation_filepath:
			data_dir_path = publaynet_dir_path + '/train'
		elif 'val' in annotation_filepath:
			data_dir_path = publaynet_dir_path + '/val'
		else:
			print('Invalid directory tag.')
			return
	else:
		if 'posix' == os.name:
			data_base_dir_path = '/home/sangwook/work/dataset'
		else:
			data_base_dir_path = 'D:/work/dataset'
		coco_dir_path = data_base_dir_path + '/coco'

		annotation_filepath = coco_dir_path + '/annotations/instances_train2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/instances_val2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/instances_train2017.json'
		#annotation_filepath = coco_dir_path + '/annotations/instances_val2017.json'
		#annotation_filepath = coco_dir_path + '/annotations/person_keypoints_train2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/person_keypoints_val2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/person_keypoints_train2017.json'
		#annotation_filepath = coco_dir_path + '/annotations/person_keypoints_val2017.json'
		#annotation_filepath = coco_dir_path + '/annotations/captions_train2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/captions_val2014.json'
		#annotation_filepath = coco_dir_path + '/annotations/captions_train2017.json'
		#annotation_filepath = coco_dir_path + '/annotations/captions_val2017.json'

		if 'train2014' in annotation_filepath:
			data_dir_path = coco_dir_path + '/train2014'
		elif 'val2014' in annotation_filepath:
			data_dir_path = coco_dir_path + '/val2014'
		elif 'train2017' in annotation_filepath:
			data_dir_path = coco_dir_path + '/train2017'
		elif 'val2017' in annotation_filepath:
			data_dir_path = coco_dir_path + '/val2017'
		else:
			print('Invalid directory tag.')
			return

	try:
		print('Start loading a PubLayNet data from {}...'.format(annotation_filepath))
		start_time = time.time()
		coco = pycocotools.coco.COCO(annotation_filepath)
		print('End loading a PubLayNet data: {} secs.'.format(time.time() - start_time))
	except UnicodeDecodeError as ex:
		print('Unicode decode error in {}: {}.'.format(annotation_filepath, ex))
		return
	except FileNotFoundError as ex:
		print('File not found, {}: {}.'.format(annotation_filepath, ex))
		return

	#--------------------
	# Show information on data.
	if True:
		#print('Dataset: {}.'.format(coco.dataset))
		print('Dataset keys = {}.'.format(list(coco.dataset.keys())))

		if 'info' in coco.dataset:
			#print('Info: {}.'.format(coco.dataset['info']))
			print('Info: {}.'.format(coco.info()))
		if 'license' in coco.dataset:
			print('License: {}.'.format(coco.dataset['license']))

		if 'images' in coco.dataset:
			print('Images:')
			#print('\tData: {}.'.format(coco.dataset['images']))
			print('\tKeys = {}.'.format(list(coco.dataset['images'][0].keys())))
			print('\t#images = {}.'.format(len(coco.dataset['images'])))
			print('\tMin and max IDs = ({}, {}).'.format(functools.reduce(lambda mm, img: min(mm, img['id']), coco.dataset['images'], coco.dataset['images'][0]['id']), functools.reduce(lambda mm, img: max(mm, img['id']), coco.dataset['images'], 0)))
		if 'categories' in coco.dataset:
			print('Categories:')
			#print('\tData: {}.'.format(coco.dataset['categories']))
			print('\tKeys = {}.'.format(list(coco.dataset['categories'][0].keys())))
			print('\t#categories = {}.'.format(len(coco.dataset['categories'])))
			print('\tMin and max IDs = ({}, {}).'.format(functools.reduce(lambda mm, cat: min(mm, cat['id']), coco.dataset['categories'], coco.dataset['categories'][0]['id']), functools.reduce(lambda mm, cat: max(mm, cat['id']), coco.dataset['categories'], 0)))
			print('\tCategory = {}.'.format(list(cat['name'] for cat in coco.dataset['categories'])))
		if 'annotations' in coco.dataset:
			print('Annotations:')
			#print('\tData: {}.'.format(coco.dataset['annotations']))
			print('\tKeys = {}.'.format(list(coco.dataset['annotations'][0].keys())))
			print('\t#annotations = {}.'.format(len(coco.dataset['annotations'])))
			print('\tMin and max IDs = ({}, {}).'.format(functools.reduce(lambda mm, ann: min(mm, ann['id']), coco.dataset['annotations'], coco.dataset['annotations'][0]['id']), functools.reduce(lambda mm, ann: max(mm, ann['id']), coco.dataset['annotations'], 0)))
		if 'segment_infos' in coco.dataset:
			print('Segment infos:')
			#print('\tData: {}.'.format(coco.dataset['segment_infos']))
			print('\tKeys = {}.'.format(list(coco.dataset['segment_infos'][0].keys())))
			print('\t#segment infos = {}.'.format(len(coco.dataset['segment_infos'])))
			print('\tMin and max IDs = ({}, {}).'.format(functools.reduce(lambda mm, si: min(mm, si['id']), coco.dataset['segment_infos'], coco.dataset['segment_infos'][0]['id']), functools.reduce(lambda mm, si: max(mm, si['id']), coco.dataset['segment_infos'], 0)))

		#--------------------
		"""
		APIs for pycocotools.coco.COCO:
			annIds = coco.getAnnIds(imgIds=[], catIds=[], areaRng=[], iscrowd=None)
			catIds = coco.getCatIds(catNms=[], supNms=[], catIds=[])
			imgIds = coco.getImgIds(imgIds=[], catIds=[])

			anns = coco.loadAnns(ids=[])
			cats = coco.loadCats(ids=[])
			imgs = coco.loadImgs(ids=[])

			import matplotlib.pyplot as plt
			coco.showAnns(anns, draw_bbox=False)
			plt.show()

			loaded_coco = coco.loadRes(resFile)
			anns = coco.loadNumpyAnnotations(data)

			rle = coco.annToRLE(ann)
			mask = coco.annToMask(ann)
		"""

		if 'categories' in coco.dataset:
			cat_counts = dict()
			for cat in coco.dataset['categories']:
				annIds = coco.getAnnIds(imgIds=[], catIds=[cat['id']], areaRng=[], iscrowd=None)
				cat_counts[cat['name']] = len(annIds)
			print("#annotations per category: {}.".format(cat_counts))

		#imgIds = coco.getImgIds(imgIds=[1, 3, 7], catIds=[1])
		#images = coco.loadImgs(ids=imgIds)
		#print('Image IDs = {}.'.format(imgIds))
		#print('Images = {}.'.format(images))

		#catIds = coco.getCatIds(catNms=[coco.dataset['categories'][1 - 1]['name'], coco.dataset['categories'][2 - 1]['name']], supNms=[], catIds=[2, 3])
		#categories = coco.loadCats(ids=annIds)
		#print('Category IDs = {}.'.format(catIds))
		#print('Categories = {}.'.format(categories))

		#annIds = coco.getAnnIds(imgIds=[1], catIds=[], areaRng=[], iscrowd=None)
		#annotations = coco.loadAnns(ids=annIds)
		#print('Annotation IDs = {}.'.format(annIds))
		#print('Annotation = {}.'.format(annotations))

	#--------------------
	# Visualize data.
	if True:
		num_data_to_visualize = 10
		for idx, image_info in enumerate(coco.dataset['images']):
			image_filepath = image_info['file_name']
			image_id = image_info['id']
			image_height, image_width = image_info['height'], image_info['width']

			image_filepath = os.path.join(data_dir_path, image_filepath)

			annIds = coco.getAnnIds(imgIds=[image_id], catIds=[], areaRng=[], iscrowd=None)
			annotations = coco.loadAnns(ids=annIds)

			if True:
				from PIL import Image, ImageFont
				import matplotlib.pyplot as plt

				if 'posix' == os.name:
					font_dir_path = '/home/sangwook/work/font'
				else:
					font_dir_path = 'D:/work/font'
				font_filepath = font_dir_path + '/DejaVuSans.ttf'
				try:
					font = ImageFont.truetype(font_filepath, 15)
				except Exception as ex:
					print('Invalid font, {}: {}.'.format(font_filepath, ex))
					raise

				try:
					with Image.open(image_filepath) as img:
						if img.size[0] != image_width or img.size[1] != image_height:
							print('Invalid image size, ({}, {}) != ({}, {}).'.format(img.size[0], img.size[1], image_width, image_height))
							return
						plt.imshow(vsualize_annotations(img, annotations, coco, font))
						plt.axis('off')
				except IOError as ex:
					print('Failed to load an image, {}: {}.'.format(image_filepath, ex))
					raise
				plt.tight_layout()
				plt.show()
			else:
				import cv2

				img = cv2.imread(image_filepath, cv2.IMREAD_COLOR)
				if img is None:
					print('Failed to load an image, {}.'.format(image_filepath))
					return
				if img.shape[0] != image_height or img.shape[1] != image_width:
					print('Invalid image shape, ({}, {}) != ({}, {}).'.format(img.shape[0], img.shape[1], image_height, image_width))
					return

				colors = [(0, 0, 255), (0, 255, 0), (255, 0, 0), (0, 255, 255), (255, 0, 255), (255, 255, 0)]

				print('Labels = {}.'.format(list(ann['category_id'] for ann in annotations)))
				for ann in annotations:
					bbox = ann['bbox']  # [x, y, width, height].
					#area = ann['area']
					segmentation = ann['segmentation']  # RLE or [polygon].
					category_id = ann['category_id']
					#iscrowd = ann['iscrowd']  # 0 or 1.

					assert len(segmentation) == 1
					segmentation = segmentation[0]

					color = colors[(category_id - 1) % len(colors)]
					left, top, right, bottom = bbox[0], bbox[1], bbox[0] + bbox[2], bbox[1] + bbox[3]
					#assert left >= 0 and top >= 0 and right <= img.shape[1] and bottom <= img.shape[0], ((left, top, right, bottom), (img.shape))
					left, top, right, bottom = max(math.floor(left), 0), max(math.floor(top), 0), min(math.ceil(right), img.shape[1] - 1), min(math.ceil(bottom), img.shape[0] - 1)
					cv2.rectangle(img, (left, top), (right, bottom), color, 2, cv2.LINE_8)
					segmentation = np.expand_dims(np.round(np.array(list(segmentation[si:si + 2] for si in range(0, len(segmentation), 2)))).astype(np.int), axis=1)
					overlay = np.zeros_like(img)
					cv2.drawContours(overlay, [segmentation], 0, color, cv2.FILLED, cv2.LINE_8)
					img = cv2.addWeighted(img, 1.0, overlay, 0.25, 0)
				cv2.imshow('Image', img)
				cv2.waitKey(0)
			if num_data_to_visualize and idx >= (num_data_to_visualize - 1): break
		#cv2.destroyAllWindows()

def main():
	simple_example()

#--------------------------------------------------------------------

if '__main__' == __name__:
	main()
