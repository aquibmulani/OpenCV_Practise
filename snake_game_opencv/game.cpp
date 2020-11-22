
#include <opencv2/opencv.hpp>
#include <iostream>
/*#include <core/core.hpp>
#include <highgui/highgui.hpp>
#include <imgproc/imgproc.hpp>
#include <iostream>*/
#include <time.h>


using namespace std;
using namespace cv;


// define box size and window size
int box_width = 14;
int box_length= 14;
int window_width = 41 *box_width * 2;
int window_length = 41 *box_length * 2;



//Defenition of Box class, including size and location information
class Box
{
public:
        Mat boxMat;
        Point boxpoint;
	Box();
};

Box::Box()
{
         Mat image01(box_width,box_length,CV_8UC3,Scalar(0,0,0));
         boxMat =  image01;
         boxpoint = Point(((window_width/box_width)/2+1) *box_width, ((window_width/box_width)/2+1) * box_width); 
}

Box boxtarget;
Mat backGroundImage;
vector<Box> arraryBox;
//srand(time(0));

int main(int argc,char *agrv[])
{
Box box01;
  Mat imagebackground(window_width,window_length,CV_8UC3,Scalar(255,255,255));
  boxtarget.boxpoint.x= 250; //(rand()%(window_width/box_width))*box_width; 
  boxtarget.boxpoint.y=250;//(rand()%(window_length/box_length))*box_length;

//  boxtarget.boxpoint.x=(rand()%(window_width/box_width))*box_width;
//  boxtarget.boxpoint.y=(rand()%(window_length/box_length))*box_length;
 arraryBox.push_back(box01);
  Mat ROIBackground=imagebackground(Rect(boxtarget.boxpoint.x,boxtarget.boxpoint.y,box_width,box_length));
  addWeighted(ROIBackground,0,boxtarget.boxMat,1,0,ROIBackground);
  //Mat ROICenterPoint=imagebackground(Rect(arraryBox[0].boxpoint.x,arraryBox[0].boxpoint.y,box_width,box_length));
  //addWeighted(ROICenterPoint,0,arraryBox[0].boxMat,1,0,ROICenterPoint);
  
 
  String windowname = "Snake Game";
  imshow(windowname,imagebackground);
  waitKey(0); // Wait for any keystroke in the window

  waitKey(0); // Wait for any keystroke in the window

 destroyWindow(windowname); //destroy the created window); //destroy the created window

return 0;
}
