#include "sift.h"

static inline double vec_distance(uchar *src1, uchar *src2)
{
	int i;
	double adder = 0;
	for (i = 0; i < 128; i++)
	{
		adder += (src1[i] - src2[i]) * (src1[i] - src2[i]);
	}
	return sqrt(adder);
}

int sift_match(Mat &input, Mat &com)
{
	Mat input_detect, com_detect;
	Mat input_descriptor, com_descriptor;
	Mat *max_descriptor, *min_descriptor;
	SiftFeatureDetector input_detector, com_detector;
	SiftDescriptorExtractor extractor;
	vector<KeyPoint> input_kp, com_kp;
	int i, j, input_size, com_size, min_size, max_size, matches;

	input_detector.detect(input, input_kp);
	com_detector.detect(com, com_kp);
	extractor.compute(input, input_kp, input_descriptor);
	extractor.compute(com, com_kp, com_descriptor);

	input_size = input_kp.size();
	com_size = com_kp.size();
	if (input_size < com_size)
	{
		min_size = input_size;
		max_size = com_size;
		min_descriptor = &input_descriptor;
		max_descriptor = &com_descriptor;
	}
	else
	{
		min_size = com_size;
		max_size = input_size;
		min_descriptor = &com_descriptor;
		max_descriptor = &input_descriptor;
	}

	matches = 0;
	for (i = 0; i < min_size; i++)
	{
		double min_distance = DBL_MAX;
		double sec_min_distance = DBL_MAX;
		uchar *pic_charac = min_descriptor->data + i * 128;
		for (j = 0; j < max_size; j++)
		{			
			uchar *ref_charac = max_descriptor->data + j * 128;
			double dis = vec_distance(pic_charac, ref_charac);
			if (dis < min_distance)
			{
				sec_min_distance = min_distance;
				min_distance = dis;
			}
			else if (dis < sec_min_distance)
			{
				sec_min_distance = dis;
			}
		}
		if (min_distance / sec_min_distance <= RATIO_MATCH)
		{
			matches++;
			//需要去掉match的点吗？
		}
	}

	return matches;
}
