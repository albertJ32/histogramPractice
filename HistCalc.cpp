#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * @function main
 */

// Get highest histogram value for window calibration
float highestVal(Mat test1){
    if(!test1.data){
      cout << "highestVal Mat was unable to load" << endl;
    }
    float high = 0.0;

    for(int i = 0;i < test1.rows;i++){
      for(int j = 0;j < test1.cols;j++){
        if(test1.at<float>(i, j) > high){
          high = test1.at<float>(i, j);
        }
      }
    }
    cout << "This is the high value.. " << high  << endl;
    return high;
}

// Draw histogram
Mat showHist(Mat& test1, Mat& histImage, int histSize){
  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = floorf( (double) hist_w/histSize );

  Mat m( hist_h, hist_w, CV_8UC1, Scalar( 0) );

  // Calibrate the maximum histogram value at 80% of window height
  float high = highestVal(test1);
  float scaleFactor = ((hist_h*0.8)/high);
  //cout << "this is the size: " << histImage.size() << endl;

  /// Draw for each channel
  for( int i = 0; i < histSize; i++ )
  {
  cout << "result " << i << ":" << test1.at<float>(i) << endl;
       rectangle( histImage, Point( bin_w*(i),  hist_h) ,
                        Point( (bin_w*(i))+bin_w,  hist_h - (test1.at<float>(i)*scaleFactor)),
                        Scalar( 255, 255, 255),-1, 8);
  }
  return m;
}

// Create Hist variables and return histogram
Mat createHist(Mat& test1, Mat& histImage){
  /// Establish the number of bins
  int histSize = 100;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 100 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat test;

  /// Compute the histograms:
  calcHist( &test1, 1, 0, Mat(), test, 1, &histSize, &histRange, uniform, accumulate );

  return showHist(test, histImage, histSize);
}

void getImgs(Mat& img, Mat& img2){
  VideoCapture stream1(1);
  if(!stream1.isOpened()){
    cout << "cannot open video stream" << endl;
  }

  int imgCount = 0;

  cout << "\n\nEntering img collection loop. Press '1' and '2' to collect images. Press 'q' to leave loop.\n\n";

  while(true){
    Mat imgTmp;
    stream1.read(imgTmp);
    imshow("VideoStream", imgTmp);

    char key = waitKey(30);

    if(key == '1'){
      cout << "this is the leypress" << key << endl;
      imgTmp.copyTo(img);
      imgCount++;
    } else if(key == '2'){
      cout << "this is the leypress" << key << endl;
      imgTmp.copyTo(img2);
      imgCount++;
    } else if(key == 'q' && (img.empty() || img2.empty())){
      cout << "Please collect both image '1' and image '2'" << endl;
    } else if(key == 'q'){
      break;
    }
  }
}

int main( int argc, char** argv )
{
  Mat savedPic1, savedPic2;

  getImgs(savedPic1, savedPic2);
  if(savedPic1.empty() || savedPic2.empty()){
    cout << "savedPic does not have any data.." << endl;
    return -1;
  }

  // Equalise captured images
  cvtColor(savedPic1, savedPic1, CV_BGR2GRAY);
  equalizeHist(savedPic1, savedPic1);

  cvtColor(savedPic2, savedPic2, CV_BGR2GRAY);
  equalizeHist(savedPic2, savedPic2);

  // Calculate and return histogram representation
  Mat histImage = createHist(savedPic1, histImage);

  /// Display
  namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );

  waitKey(0);

  return 0;
}
