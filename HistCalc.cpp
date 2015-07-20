#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * @function main
 */
int main( int argc, char** argv )
{

  /// Establish the number of bins
  int histSize = 20;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 100 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  int h = 20, w = 20;
  int total = (h*w)*100;
  Mat test = Mat(h,w,CV_32FC1, Scalar(23));

  // Add pixel variations
  for(int i=0;i<168;i++)
    test.at<float>(10,i) = 90;

  test.at<float>(15,3) = 11;

  /// Compute the histograms:
  Mat test1;
  calcHist( &test, 1, 0, Mat(), test1, 1, &histSize, &histRange, uniform, accumulate );

  // // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC1, Scalar( 0) );

  /// Normalize the result to [ 0, histImage.rows ]
  // normalize(test1, test1, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  // normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  // normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
       rectangle( histImage, Point( bin_w*(i),  hist_h) ,
                        Point( (bin_w*(i))+bin_w,  hist_h - test1.at<float>(i)),
                        Scalar( 255, 255, 255),-1, 8);
  }

  /// Display
  namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );

  waitKey(0);

  return 0;
}
