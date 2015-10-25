#include "common.h"
#include "sift.h"
const String input_filename = "E:\\dev\\image\\building\\200.jpg";
const String com_filename = "E:\\dev\\image\\building\\201.jpg";


int main()
{
	Mat input_picture, com_picture;
	
	//vector<DMatch> matches;
	//Mat img_matches;
	//BFMatcher matcher(NORM_L2);
	//int drawmode = DrawMatchesFlags::DRAW_RICH_KEYPOINTS;
	//DescriptorMatcher *matcher = new FlannBasedMatcher;

	input_picture = imread(input_filename, CV_LOAD_IMAGE_COLOR);
	//drawKeypoints(input_picture, input_kp, input_detect, Scalar::all(-1), drawmode);

	com_picture = imread(com_filename, CV_LOAD_IMAGE_COLOR);
	//drawKeypoints(com_picture, com_kp, com_detect, Scalar::all(-1), drawmode);
	//printf("Number of input picture points : %d\n", input_kp.size());
	//printf("Number of common picture points : %d\n", com_kp.size());
	printf("total %d matches", sift_match(input_picture, com_picture));
	//imshow("input descriptor", input_descriptor);
	//imshow("common descriptor", com_descriptor);

	//matcher.match(input_descriptor, com_descriptor, matches);
	//sort(matches.begin(), matches.end());
	//drawMatches(input_picture, input_kp, com_picture, com_kp, matches, img_matches);
	//printf("Number of matched points : %d\n", matches.size());
	//imshow("image keypoints", input_detect);
	//imshow("ref keypoints", com_detect);
	//imshow("matches", img_matches);
	waitKey();
}