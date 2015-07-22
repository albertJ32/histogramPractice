#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * @function main
 */

int maxHistVal(Mat in){
  int maxVal = 0;

  for(int i = 0; i < in.rows;i++){
    for(int j = 0; j < in.cols;j++){
      if(in.at<float>(i,j)>maxVal){
        maxVal = in.at<float>(i,j);
      }
    }
  }

  return maxVal;
}

// Draw histogram
Mat showHist(Mat& test1, int histSize){
    // Draw the histograms for B, G and R
    int hist_w = 512; int hist_h = 400;
    int bin_w = floorf( (double) hist_w/histSize );

    int maxVal = maxHistVal(test1);

    Mat m( hist_h, hist_w, CV_8UC1, Scalar( 0) );

    // Calibrate the maximum histogram value at 80% of window height
    double scaleFactor = ((hist_h*0.8)/maxVal);
  //  cout << "maxVal: " << maxVal << " hist_h: " << hist_h << " hist_h*0.8: " << (double)hist_h*0.8 << " (hist_h/maxVal): " << ((double)hist_h/maxVal) << " the scale: " << scaleFactor <<  endl;

    /// Draw for each channel
    for( int i = 0; i < histSize; i++ )
    {
    // cout << "result " << i << ":" << test1.at<float>(i) << " adjusted values: " << test1.at<float>(i)*scaleFactor << endl;
         rectangle( m, Point( bin_w*(i),  hist_h) ,
                          Point( (bin_w*(i))+bin_w,  hist_h - (test1.at<float>(i)*scaleFactor)),
                          Scalar( 255, 255, 255),-1, 8);
    }

    return m;
}

// Create Hist variables and return histogram
Mat createHist(Mat& test1, int histSize){
  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;
  Mat test;

  /// Compute the histograms:
  calcHist( &test1, 1, 0, Mat(), test, 1, &histSize, &histRange, uniform, accumulate );
  return test;
}


int main( int argc, char** argv )
{
  int win_h = 400, win_w = 512;
  int histSize = 100; // Establish the number of bins
  double compHistogram = 0.0;

  int imgCount = 0;
  int loopCounter = 0;

  Mat histImage;


  VideoCapture stream1(1);
  if(!stream1.isOpened()){
    cout << "cannot open video stream" << endl;
  }


  cout << "\n\nEntering img collection loop. Press '1' and '2' to collect images. Press 'q' to leave loop.\n\n";

  namedWindow("VideoStream", CV_WINDOW_AUTOSIZE);
  namedWindow("win1", CV_WINDOW_AUTOSIZE );
  namedWindow("win2", CV_WINDOW_AUTOSIZE );

  Mat savedPic1 = cv::Mat::zeros(win_h, win_w, CV_8UC3);
  Mat savedPic2 = cv::Mat::zeros(win_h, win_w, CV_8UC3);

  while(true){

    Mat imgTmp;
    stream1.read(imgTmp);
    imshow("VideoStream", imgTmp);

    char key = waitKey(30);

    if(key == '1'){
      cout << "\nthis is the Keypress" << key << endl;
      savedPic1 = Scalar(0,0,0);
      savedPic1 = imgTmp.clone();
      cout << "New Histogram Comparison: " << compHistogram << endl;
      imgCount++;
    } else if(key == '2'){
      cout << "\nthis is the Keypress" << key << endl;
      savedPic2 = Scalar(0,0,0);
      savedPic2 = imgTmp.clone();
      cout << "New Histogram Comparison: " << compHistogram << endl;
      imgCount++;
    } else if(key == 'q' && (savedPic1.empty() || savedPic2.empty())){
      cout << "\nPlease collect both image '1' and image '2'" << endl;
    } else if(key == 'q'){
      cout << "Exiting. " << endl;
      break;
    }

    //Check if Mat's need to be converted to grayscale and equalised
    if(savedPic1.channels()==3){
      // Equalise captured images
      cvtColor(savedPic1, savedPic1, CV_BGR2GRAY);
      equalizeHist(savedPic1, savedPic1);
    }
    // Equalise captured images
    if(savedPic2.channels()==3){
      cvtColor(savedPic2, savedPic2, CV_BGR2GRAY);
      equalizeHist(savedPic2, savedPic2);
    }

    // Calculate and return histogram representation
    Mat hist1 = createHist(savedPic1, histSize);
    Mat hist2 = createHist(savedPic2, histSize);

    // if(loopCounter%10==0)
    //   cout << "\nhere... loopCounter: " << loopCounter <<"\n\n" << endl;

    compHistogram = compareHist(hist1, hist2, CV_COMP_CHISQR);

    Mat m =  showHist(hist1, histSize);
    Mat m1 =  showHist(hist2, histSize);

    /// Display
    imshow("win1", m );
    imshow("win2", m1 );

    loopCounter ++;
  }
  return 0;
}
