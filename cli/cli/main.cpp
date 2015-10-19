#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>

using namespace std;
using namespace cv;

const String input_filename = "E:\\dev\\image\\building\\200.jpg";
const String com_filename = "E:\\dev\\image\\building\\200.jpg";


int main()
{
	Mat input_picture, com_picture;
	Mat input_detect, com_detect;
	Mat input_descriptor, com_descriptor;
	SiftFeatureDetector input_detector, com_detector;
	SiftDescriptorExtractor extractor;
	vector<KeyPoint> input_kp, com_kp;
	vector<DMatch> matches;
	Mat img_matches;
	//BruteForceMatcher<L2<float>> matcher;
	DescriptorMatcher *matcher = new FlannBasedMatcher;

	input_picture = imread(input_filename, CV_LOAD_IMAGE_COLOR);
	input_detector.detect(input_picture, input_kp);
	drawKeypoints(input_picture, input_kp, input_detect);

	com_picture = imread(com_filename, CV_LOAD_IMAGE_COLOR);
	com_detector.detect(com_picture, com_kp);
	drawKeypoints(com_picture, com_kp, com_detect);
	
	extractor.compute(input_picture, input_kp, input_descriptor);
	extractor.compute(com_picture, com_kp, com_descriptor);

	matcher->match(input_descriptor, com_descriptor, matches);
	sort(matches.begin(), matches.end());
	drawMatches(input_picture, input_kp, com_picture, com_kp, matches, img_matches);

	imshow("image keypoints", input_detect);
	imshow("ref keypoints", com_detect);
	imshow("matches", img_matches);
	waitKey();
}