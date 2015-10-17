#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/features2d/features2d.hpp>


using namespace std;
using namespace cv;

const String filename = "C:\\Users\\lunning\\Desktop\\lena.jpg";

int main()
{
	Mat picture;
	Mat output;
	SiftFeatureDetector detector;
	vector<KeyPoint> kp;

	picture = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	detector.detect(picture, kp);
	drawKeypoints(picture, kp, output);
	imshow("image keypoints", output);
	waitKey();
}